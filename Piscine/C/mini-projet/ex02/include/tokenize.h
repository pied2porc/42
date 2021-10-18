#pragma once

typedef enum {
    tt_none = -1,
    tt_sign,
    tt_term,
    tt_operator,
    tt_parOpen,
    tt_parClose
} e_tokenType;

typedef struct s_token {
    int             nb;
    char            op;
    e_tokenType     tt;
    struct s_token* tail;
    struct s_token* next;
    struct s_token* prev;
} t_token;

e_tokenType pushOperator   (char** expr,
                            t_token** operators,
                            t_token** postfix,
                            e_tokenType lastToken);
e_tokenType pushParenthesis(char** expr,
                            t_token** operators,
                            t_token** postfix,
                            e_tokenType lastToken);
e_tokenType pushTerm       (char** expr,
                            t_token** operators,
                            t_token** postfix,
                            e_tokenType lastToken);
e_tokenType popParenthesis (char** expr,
                            t_token** operators,
                            t_token** postfix,
                            e_tokenType lastToken);
