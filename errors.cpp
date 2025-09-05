#include <stdio.h>

#include "errors.h"

const char* err_msg[] = {"Pointer went equal NULL",
                         "Variable went equal NAN",
                         "The digit didn't become finite"};

void print_err_message(const char *file_name, const char* func_name, const int n_line,
                       const int error_code) {
    char str[200] = "";

    printf("%s in %s failed in fuction %s in line %d\n", err_msg[error_code], file_name, func_name, n_line);
}