#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MIN(a, b) (((a) < (b)) ? a : b)
#define MAX(a, b) (((a) > (b)) ? a : b)

enum ERRORS {
    NOTHING    =  0,
    NULLPTR    =  1,
    NAN_ERR    =  2,
    InNFINITY  =  3
};

const char* err_msg[] = {"Pointer went equal NULL",
                         "Variable went equal NAN",
                         "The digit didn't become finite"};

void print_err_message(const char *file_name, const char* func_name, const int n_line,
                       const int error_code) {
    char str[200] = "";

    printf("%s in %s failed in fuction %s in line %d\n", err_msg[error_code], file_name, func_name, n_line);
}

#define my_assert(comp, code_err) if (comp) {print_err_message(__FILE__, __FUNCTION__, __LINE__, code_err);}

const int NULL_code = 48;
const int A_code = 65;
const int a_code = 97;



void my_puts(const char* str) {
    my_assert(!str, NULLPTR);

    while (*str != '\0')
        printf("%c", *str++);
    putchar('\n');
}

const char* my_strchr(const char* str, int c) {
    my_assert(!str, NULLPTR);

    while (*str != '\0')
        if (*str++ == c)
            return str;
    return NULL;
}

size_t my_strlen(const char* str) {
    my_assert(!str, NULLPTR);

    int len = 0;
    while (*str++ != '\0')
        ++len;
    return len;
}

char* my_strcpy(char* dest, const char* src) {
    my_assert(!src, NULLPTR);
    my_assert(!dest, NULLPTR);

    int i = 0;
    while (*src != '\0')
        dest[i++] = *src++;
    dest[i] = '\0';
    return dest;
}

char* my_strncpy(char* dest, const char* src, size_t n) {
    my_assert(!dest, NULLPTR);
    my_assert(!src, NULLPTR);

    int i = 0;
    while (n-- && *src != '\0')
        dest[i++] = *src++;

    while (n--)
        dest[i++] = '\0';
    return dest;
}

char* my_strcat(char* dest, const char* src) {
    my_assert(!dest, NULLPTR);
    my_assert(!src, NULLPTR);

    int i = 0;
    while (dest[i++] != '\0');

    while (*src != '\0')
        dest[i++] = *src++;
    dest[i] = '\0';
    return dest;
}

char* my_strncat(char* dest, const char* src, size_t n) {
    my_assert(!dest, NULLPTR);
    my_assert(!src, NULLPTR);

    int i = 0;
    while (n-- && *src != '\0') 
        dest[i++] = *src++;

    while (n--)
        dest[i++] = '\0';
    return dest;
}   

int my_atoi(const char* nptr) {
    my_assert(!nptr, NULLPTR);

    while (*nptr == ' ')
        ++nptr;

    if (*nptr != '-' && !isdigit(*nptr))
        return 0;
    
    int mn = 1;
    if (*nptr == '-') {
        mn *= -1;
        ++nptr;
    }

    int x = 0;
    while (*nptr != '\0') {
        if (isdigit(*nptr))
            x = x * 10 + (*nptr++ - NULL_code);
        else
            break;
    }
    return x * mn;
}

char* my_fgets(char* s, int size, FILE* stream) {
    my_assert(!s, NULLPTR);
    my_assert(!stream, NULLPTR);

    int i = 0;
    while (--size) {
        char c = 0;
        fscanf(stream, "%c", &c);
        if (c == EOF || c == '\n') {
            return NULL;
        }
        s[i++] = c;
    }
    s[i] = '\0';
    return s;
}

char* my_strdup(const char* s) {
    my_assert(!s, NULLPTR);

    size_t len = my_strlen(s);
    return (char*)calloc(len, sizeof(char));
}

int main() {
    my_puts("Hello, world!");
    char str[] = "popa";
    my_strncat(str, "zhopa", 10);
    my_puts(str);
    printf("%d\n", my_atoi("   -138 pop"));
    char st[10];
    my_fgets(st, 5, stdin);
    my_puts(st);
}