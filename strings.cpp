#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

const int NULL_code = 48;
const int A_code = 65;
const int a_code = 97;

void my_puts(const char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        printf("%c", str[i]);
    }
    printf("\n");
}

const char* my_strchr(const char* str, int c) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == c) {
            return &str[i];
        }
    }
    return NULL;
}

size_t my_strlen(const char* str) {
    size_t len = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        ++len;
    return len;
}

char* my_strcpy(char* dest, const char* src) {
    size_t len = my_strlen(src);
    for (size_t i = 0; i < len; ++i) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
}

char* my_strncpy(char* dest, const char* src, size_t n) {
    size_t len = my_strlen(src);
    for (size_t i = 0; i < MIN(len, n); ++i) {
        dest[i] = src[i];
    }
    for (size_t i = len; i < n; ++i) {
        dest[i] = '\0';
    }
    return dest;
}

char* my_strcat(char* dest, const char* src) {
    size_t len = my_strlen(dest);
    size_t n = my_strlen(src);
    for (size_t i = len; i < (len + n); ++i) {
        dest[i] = src[i - len];
    }
    dest[len + n] = '\0';
    return dest;
}

char* my_strncat(char* dest, const char* src, size_t n) {
    size_t len = my_strlen(dest);
    size_t len_src = my_strlen(src);
    for (size_t i = len; i < (len + MIN(n, len_src)); ++i) {
        dest[i] = src[i - len];
    }
    for (size_t i = len + len_src; i < len + n; ++i) {
        dest[i] = '\0';
    }
    dest[len + n] = '\0';
    return dest;
}   

int my_atoi(const char* nptr) {
    size_t len = my_strlen(nptr);
    size_t i = 0;
    while (nptr[i] == ' ' && i < len) { // (i < len)?
        ++i;
    }
    if (nptr[i] != '-' && !isdigit(nptr[i])) {
        return 0;
    }
    int mn = 1;
    if (nptr[i] == '-') {
        mn *= -1;
        ++i;
    }
    int x = 0;
    for (; i < len; ++i) {
        if (isdigit(nptr[i])) {
            x = x * 10 + (nptr[i] - NULL_code);
        }
        else {
            break;
        }
    }
    return x * mn;
}

char* my_fgets(char* s, int size, FILE* stream) {
    for (size_t i = 0; i < size - 1; ++i) {
        char c = 0;
        fscanf(stream, "%c", &c);
        if (c == EOF || c == '\n') {
            return NULL;
        }
        s[i] = c;
    }
    s[size] = '\0';
}

int main() {
    my_puts("Hello, world!");
    char str[] = "popa";
    my_strncat(str, "zhopa", 10);
    my_puts(str);
    printf("%d", my_atoi("   -138 pop"));
    char st[10];
    my_fgets(st, 5, stdin);
    my_puts(st);
}