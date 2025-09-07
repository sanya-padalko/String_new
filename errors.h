#ifndef _ERRORS_H_
#define _ERRORS_H_

#define my_assert(comp, code_err) if (comp) {print_err_message(__FILE__, __FUNCTION__, __LINE__, code_err);exit(0);}

enum ERRORS {
    NOTHING        = 3,
    NAN_ERR        = 1,
    NULLPTR        = 0,
    INFINITY_DIGIT = 2
};

void print_err_message(const char *file_name, const char* func_name, const int n_line,
                       const int error_code);

#endif // _ERRORS_H