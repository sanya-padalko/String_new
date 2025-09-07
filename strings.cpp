#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "errors.h"

#define MIN(a, b) (((a) < (b)) ? a : b)
#define MAX(a, b) (((a) > (b)) ? a : b)

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
    char* result = dest;

    while (*src != '\0')
        *dest++ = *src++;
    
    *dest = '\0';

    return result;
}

char* my_strncpy(char* dest, const char* src, size_t n) {
    my_assert(!dest, NULLPTR);
    my_assert(!src, NULLPTR);

    int i = 0;
    char* result = dest;
    while (n-- && *src != '\0')
        *dest++ = *src++;

    while (n--)
        *dest++ = '\0';

    return result;
}

char* my_strcat(char* dest, const char* src) {
    my_assert(!dest, NULLPTR);
    my_assert(!src, NULLPTR);

    char* result = dest;
    while (*dest++ != '\0');

    while (*src != '\0')
        *dest++ = *src++;
    *dest = '\0';

    return result;
}

char* my_strncat(char* dest, const char* src, size_t n) {
    my_assert(!dest, NULLPTR);
    my_assert(!src, NULLPTR);

    char* result = dest;

    while (n-- && *src != '\0') 
        *dest++ = *src++;

    while (n--)
        *dest++ = '\0';

    return result;
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

    char* result = s;
    char c = 0;

    while (--size) {
        fscanf(stream, "%c", &c);
        if (c == EOF || c == '\n')
            return NULL;
        
        *s++ = c;
    }

    while (c != EOF && c != '\n')
        fscanf(stream, "%c", &c);

    *s = '\0';

    return result;
}

char* my_strdup(const char* s) {       
    my_assert(!s, NULLPTR);

    size_t len = my_strlen(s);

    char* new_str = (char*)calloc(len, sizeof(char));
    my_assert(!new_str, NULLPTR);
    char* start = new_str;

    while (*s != '\0') {
        *new_str++ = *s++;
    }
    
    *new_str = '\0';

    return start;
}

size_t my_getline(char** lineptr, size_t* n, FILE* stream) {
    my_assert(!lineptr, NULLPTR);
    my_assert(!(*lineptr), NULLPTR);
    my_assert(!n, NULLPTR);
    my_assert(!stream, NULLPTR);

    *lineptr = (char*)calloc(*n, sizeof(char));  
    my_assert(!lineptr, NULLPTR);
    char* copy_ptr = *lineptr;

    char c = 0;

    while ((c = getc(stream)) != '\n' && c != EOF) {
        int len = (*lineptr - copy_ptr);

        if (len == *n) {
            if (*n == 0) 
                ++*n;

            *n *= 2;
            copy_ptr = (char*)realloc(copy_ptr, *n); 
            my_assert(!copy_ptr, NULLPTR);

            *lineptr = (copy_ptr + len);
        }

        *(*lineptr)++ = c;
    }

    if (c == EOF)
        return -1;

    int len = (*lineptr - copy_ptr);
    copy_ptr = (char*)realloc(copy_ptr, len + 1);
    my_assert(!copy_ptr, NULLPTR);

    *(copy_ptr + len) = '\0';

    *n = len + 1;
    
    *lineptr = copy_ptr;
    
    return *n;
}

int main() {
    my_puts("Hello, world!");
    char str[] = "popa";
    my_strncat(str, "zhopa", 10);
    my_puts(str);
    printf("%d\n", my_atoi("   -138 pop"));
    char* get_str = "popa";
    size_t len_str = 5;
    printf("%d\n", my_getline(&get_str, &len_str, stdin));
    my_puts(get_str);
    printf("%d = %d - 1", my_strlen(get_str), len_str);
}