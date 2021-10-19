#pragma once
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CIN     0
#define COUT    1
#define CERR    2

#define TRUE    1
#define FALSE   0

#define PLUS_SIGN    1
#define MINUS_SIGN  -1

#define LONG_MUL_THRESHOLD  150

#define MAX(a, b)   ((a > b) ? (a) : (b))
#define MIN(a, b)   ((a < b) ? (a) : (b))

#define BASE_ARG_ERR    "Bad base argument.\n"
#define OPS_ARG_ERR     "Bad operators argument.\n"
#define DIV_BY_ZERO     "Divide by zero.\n"
#define MALLOC_ERR      "Out of memory.\n"
#define PAREN_ERR       "Missing parenthesis.\n"
#define READ_ERR        "Failed to read.\n"
#define READ_SIZE_ERR   "Bad read size.\n"
#define READ_SIZE_MIS   "Warning: read size mismatched.\n"
#define SYNTAX_ERR      "Syntax error.\n"
#define USAGE_ERR       "Usage: .\\calc.exe <base> <operators> <read_size>\n"

#define _BENCHMARK_TEST


//// Global variables ////
int     g_callCount;
int     g_mallocCount;
clock_t g_time;


//// Enums ////
typedef enum e_operators {
    op_none = -1,
    op_parOpen,
    op_parClose,
    op_plus,
    op_minus,
    op_mul,
    op_div,
    op_mod
} e_operators;

typedef enum e_tokenType{
    tt_err = -2,
    tt_none = -1,
    tt_plusSign,
    tt_minusSign,
    tt_number,
    tt_operator,
    tt_parOpen,
    tt_parClose
} e_tokenType;


//// Structures ////
typedef struct s_expr {
    char*  buffer;
    char*  begin;
    size_t buf_size;
    char*  base;
    int    base_len;
    char*  ops;
} t_expr;

typedef struct s_number {
    char*   value;
    char*   begin;
    char*   end;
    int     sign;
    int     pointsToBuffer;
} t_number;

typedef struct s_karatsuba {
    t_number x[2];
    t_number y[2];
    t_number sum[2];
    t_number product[3];
} t_karatsuba;

typedef struct s_multiplication {
    int lsize;
    int rsize;
    int lpos;
    int rpos;
    int res_size;
    int res_pos;
} t_multiplication;

typedef struct s_division {
    t_number lhs_norm;
    t_number rhs_norm;
    int n;
    int d;
    int qhat;
    int rhat;
    int norm_factor;
} t_division;

typedef struct s_token {
    t_number    nb;
    int         op;
    e_tokenType type;
} t_token;

typedef struct s_node {
    t_token         token;
    struct s_node*  tail;
    struct s_node*  next;
    struct s_node*  prev;
} t_node;


//// Function prototypes ////
/* buffer.c */
size_t fill_buffer(char** buf, unsigned int size);
void   freeBuffer (char* buf, char const* msg);

/* checkers.c */
int check_ops (char const* ops);
int check_base(char const* base, char const* ops);
int check_size(char const* size);

/* addition.c */
t_number* sub_redirection(t_number* lhs, t_number* rhs, t_number* result, int base_len);
t_number* inf_add        (t_number* lhs, t_number* rhs, t_number* result, int base_len);

/* subtraction.c */
void      reorder_terms  (t_number** lhs, t_number** rhs, t_number* result);
t_number* add_redirection(t_number* lhs, t_number *rhs, t_number* result, int base_len);
t_number* inf_sub        (t_number* lhs, t_number* rhs, t_number* result, int base_len);

/* multiplication.c */
t_number* inf_mul    (t_number* lhs, t_number* rhs, t_number* result, int base_len);
t_number* long_mul   (t_number* lhs, t_number* rhs, t_number* result, int base_len);
void      add_term_to(t_number* term, t_number* result, size_t offset, int base_len);

/* karatsuba.c */
t_number* karatsuba    (t_number* lhs, t_number* rhs, t_number* result, int base_len);
int       initKaratsuba(t_karatsuba* k);
void      freeKaratsuba(t_karatsuba* k);
void      splitNumber  (t_number* nb, t_number parts[2], size_t half);

/* division.c */
t_number*   inf_div     (t_number* lhs, t_number* rhs, t_number* result, int base_len);
t_number*   long_div    (t_division* d, t_number* result, int base_len);
t_division* initDivision(t_number* lhs, t_number* rhs, int base_len);
void        freeDivision(t_division* d);

/* division_utils.c */
void      add_back         (t_division*d, int base_len);
void      mul_sub          (t_division* d, int base_len);
void      estimate_quotient(t_division* d, int base_len);
t_number* short_div        (t_number* lhs, int d, t_number* result, int base_len);
t_number* short_mul        (t_number* lhs, int m, t_number* result, int base_len);

/* modulo.c */
t_number* inf_mod(t_number* lhs, t_number* rhs, t_number* result, int base_len);

/* eval_expr.c */
t_number  eval_expr   (t_expr* expr);
t_number* eval_postfix(t_node** postfix, t_number* result, t_expr* expr);
t_number* do_op       (int op, t_number* lhs, t_number* rhs, t_number* result, t_expr* expr);

/* format_expr.c */
int   getNumberValue (char c, char const* base);
char* digitToValue   (char* str, char const* base, int base_len);
void  valueToDigit   (char* str, char* end, char const* base);
void  setStringToZero(char* str, char* end);

/* format_nbr.c */
void skip_leading_zeros(t_number* nb, char* begin);
void setNumberToZero   (t_number* nb);

/* number.c */
int  initNumber   (t_number* nb, char* value, size_t size, int sign);
void freeNumber   (t_number* number);
void swapNumber   (t_number** lhs, t_number **rhs);
int  isSmallerThan(t_number* lhs, t_number* rhs);

/* parser.c */
t_node*     toPostfix      (t_expr* expr);
e_tokenType parseSign      (t_expr* expr, t_node** ops, t_node** postfix, e_tokenType lastTokenType);
e_tokenType pushNumber     (t_expr* expr, t_node** postfix, e_tokenType lastTokenType);
e_tokenType pushParenthesis(t_expr* expr, t_node** ops, t_node** postfix, e_tokenType lastTokenType);
e_tokenType popParenthesis (t_expr* expr, t_node** ops, t_node** postfix, e_tokenType lastTokenType);
e_tokenType pushOperator   (int op, t_expr* expr, t_node** ops, t_node** postfix, e_tokenType lastTokenType);

/* parser_utils.c */
e_tokenType syntaxError               ();
int         getPrecedence             (int op);
int         transferRemainingOperators(t_node** ops, t_node** postfix);

/* print.c */
void printNumberString(t_number* nb, char const* base, char const* ops, int skipLeadingZeros);
void printNumberValue (t_number* nb, char const* separator, char const* ops, int skipLeadingZeros);
void printStackReverse(t_node* stack, t_expr* expr);

/* stack.c */
t_node* newNode     (int op, e_tokenType tokenType);
int     push        (t_node* node, t_node** stack);
void    pop         (t_node** stack);
void    deleteStack (t_node** stack);
void    removeNode  (t_node** stack);
void    transferNode(t_node** src, t_node** dst);

/* utils.c */
int          ft_contains(char const* s, char c);
void         ft_putnbr  (int nb);
void         ft_putstr  (char const* str, int fd);
size_t       ft_strlen  (char const* str);
int          ft_strncmp (char* a, char* b, size_t n);
char*        ft_strncpy (char const* s, size_t n);
unsigned int ft_uatoi   (char* nb);
