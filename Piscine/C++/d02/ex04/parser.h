#pragma once
#include "Fixed.h"

int   parseSign(char const**);
Fixed parseFactor(char const**);
Fixed parseProduct(char const**);
Fixed parseSum(char const**);