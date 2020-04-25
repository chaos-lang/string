#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Chaos.h"

// String operations

// string.replace(str haystack, str needle, str replacement)

char *str_replace(char *haystack, char *needle, char *replacement) {
    char *result;
    char *ins;
    char *tmp;
    int len_rep;
    int len_with;
    int len_front;
    int count;

    if (!haystack || !needle)
        return NULL;
    len_rep = strlen(needle);
    if (len_rep == 0)
        return NULL;
    if (!replacement)
        replacement = "";
    len_with = strlen(replacement);

    ins = haystack;
    for (count = 0; (tmp = strstr(ins, needle)); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(haystack) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    while (count--) {
        ins = strstr(haystack, needle);
        len_front = ins - haystack;
        tmp = strncpy(tmp, haystack, len_front) + len_front;
        tmp = strcpy(tmp, replacement) + len_with;
        haystack += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, haystack);
    return result;
}

char *replace_params_name[] = {
    "target",
    "needle",
    "replacement"
};
unsigned replace_params_type[] = {
    K_STRING,
    K_STRING,
    K_STRING
};
unsigned short replace_params_length = (unsigned short) sizeof(replace_params_type) / sizeof(unsigned);
int KAOS_EXPORT Kaos_replace()
{
    char* target = kaos.getVariableString(replace_params_name[0]);
    char* needle = kaos.getVariableString(replace_params_name[1]);
    char* replacement = kaos.getVariableString(replace_params_name[2]);
    char* result = str_replace(target, needle, replacement);
    free(target);
    free(needle);
    free(replacement);
    kaos.returnVariableString(result);
    return 0;
}

// string.upper(str s)

void str_upper(char * s) {
    while (*s) {
        *s = toupper((unsigned char) *s);
        s++;
    }
}

char *upper_params_name[] = {
    "s"
};
unsigned upper_params_type[] = {
    K_STRING
};
unsigned short upper_params_length = (unsigned short) sizeof(upper_params_type) / sizeof(unsigned);
int KAOS_EXPORT Kaos_upper()
{
    char* s = kaos.getVariableString(upper_params_name[0]);
    str_upper(s);
    kaos.returnVariableString(s);
    return 0;
}

// string.lower(str s)

void str_lower(char * s) {
    while (*s) {
        *s = tolower((unsigned char) *s);
        s++;
    }
}

char *lower_params_name[] = {
    "s"
};
unsigned lower_params_type[] = {
    K_STRING
};
unsigned short lower_params_length = (unsigned short) sizeof(lower_params_type) / sizeof(unsigned);
int KAOS_EXPORT Kaos_lower()
{
    char* s = kaos.getVariableString(lower_params_name[0]);
    str_lower(s);
    kaos.returnVariableString(s);
    return 0;
}

// string.capitalize(str s)

void str_capitalize(char * s) {
    while (*s) {
        *s = toupper((unsigned char) *s);
        break;
    }
}

char *capitalize_params_name[] = {
    "s"
};
unsigned capitalize_params_type[] = {
    K_STRING
};
unsigned short capitalize_params_length = (unsigned short) sizeof(capitalize_params_type) / sizeof(unsigned);
int KAOS_EXPORT Kaos_capitalize()
{
    char* s = kaos.getVariableString(capitalize_params_name[0]);
    str_capitalize(s);
    kaos.returnVariableString(s);
    return 0;
}

// string.concat(str s)

char *str_concat(char *s1, const char *s2)
{
    size_t n = strlen(s1);

    char *p = (char *)malloc(n + strlen(s2) + 1);

    if (p) {
        strcpy(p, s1);
        strcpy(p + n, s2);
    }

    if ((s1 != NULL) && (s1[0] != '\0')) {
        free(s1);
    }
    return p;
}


char *concat_params_name[] = {
    "s1",
    "s2"
};
unsigned concat_params_type[] = {
    K_STRING,
    K_STRING
};
unsigned short concat_params_length = (unsigned short) sizeof(concat_params_type) / sizeof(unsigned);
int KAOS_EXPORT Kaos_concat()
{
    char* s1 = kaos.getVariableString(concat_params_name[0]);
    char* s2 = kaos.getVariableString(concat_params_name[1]);
    s1 = str_concat(s1, s2);
    free(s2);
    kaos.returnVariableString(s1);
    return 0;
}


// Information functions

void remove_nth_char(char* string, long long n) {
    memmove(&string[n], &string[n + 1], strlen(string) - n);
}

char* escape_the_sequences_in_string_literal(char* string) {
    char* new_string = malloc(strlen(string) + 1);
    strcpy(new_string, string);

    for (long long i = 0; i < strlen(new_string); i++){
        if (new_string[i] == '\\') {
            switch (new_string[i+1])
            {
                case '\\':
                    remove_nth_char(new_string, i);
                    break;
                case 'a':
                    new_string[i+1] = '\a';
                    remove_nth_char(new_string, i);
                    break;
                case 'b':
                    new_string[i+1] = '\b';
                    remove_nth_char(new_string, i);
                    break;
                case 'e':
                    new_string[i+1] = '\e';
                    remove_nth_char(new_string, i);
                    break;
                case 'f':
                    new_string[i+1] = '\f';
                    remove_nth_char(new_string, i);
                    break;
                case 'n':
                    new_string[i+1] = '\n';
                    remove_nth_char(new_string, i);
                    break;
                case 'r':
                    new_string[i+1] = '\r';
                    remove_nth_char(new_string, i);
                    break;
                case 't':
                    new_string[i+1] = '\t';
                    remove_nth_char(new_string, i);
                    break;
                case 'v':
                    new_string[i+1] = '\v';
                    remove_nth_char(new_string, i);
                    break;
                default:
                    break;
            }
        }
    }

    free(string);
    return new_string;
}

// string.length(str s)

char *length_params_name[] = {
    "s"
};
unsigned length_params_type[] = {
    K_STRING
};
unsigned short length_params_length = (unsigned short) sizeof(length_params_type) / sizeof(unsigned);
int KAOS_EXPORT Kaos_length()
{
    char* s = kaos.getVariableString(length_params_name[0]);
    long long i = (long long) strlen(s);
    free(s);
    kaos.returnVariableInt(i);
    return 0;
}

// string.is_empty(str s)

char *is_empty_params_name[] = {
    "s"
};
unsigned is_empty_params_type[] = {
    K_STRING
};
unsigned short is_empty_params_length = (unsigned short) sizeof(is_empty_params_type) / sizeof(unsigned);
int KAOS_EXPORT Kaos_is_empty()
{
    char* s = kaos.getVariableString(is_empty_params_name[0]);
    bool b = (s[0] == '\0');
    free(s);
    kaos.returnVariableBool(b);
    return 0;
}

// string.is_numeric(str s)

bool str_is_numeric(const char * s) {
    if (s == NULL || *s == '\0')
        return false;

    unsigned char c;

    while ( ( c = *s ) && ( isdigit( c ) ) ) ++s;

    return *s == '\0';
}

char *is_numeric_params_name[] = {
    "s"
};
unsigned is_numeric_params_type[] = {
    K_STRING
};
unsigned short is_numeric_params_length = (unsigned short) sizeof(is_numeric_params_type) / sizeof(unsigned);
int KAOS_EXPORT Kaos_is_numeric()
{
    char* s = kaos.getVariableString(is_numeric_params_name[0]);
    s = escape_the_sequences_in_string_literal(s);
    bool b = str_is_numeric(s);
    free(s);
    kaos.returnVariableBool(b);
    return 0;
}

// string.is_alpha(str s)

bool str_is_alpha(const char * s) {
    if (s == NULL || *s == '\0')
        return false;

    unsigned char c;

    while ( ( c = *s ) && ( isalpha( c ) || isspace( c ) ) ) ++s;

    return *s == '\0';
}

char *is_alpha_params_name[] = {
    "s"
};
unsigned is_alpha_params_type[] = {
    K_STRING
};
unsigned short is_alpha_params_length = (unsigned short) sizeof(is_alpha_params_type) / sizeof(unsigned);
int KAOS_EXPORT Kaos_is_alpha()
{
    char* s = kaos.getVariableString(is_alpha_params_name[0]);
    s = escape_the_sequences_in_string_literal(s);
    bool b = str_is_alpha(s);
    free(s);
    kaos.returnVariableBool(b);
    return 0;
}

// string.is_alnum(str s)

bool str_is_alnum(const char * s) {
    if (s == NULL || *s == '\0')
        return false;

    unsigned char c;

    while ( ( c = *s ) && ( isalnum( c ) || isspace( c ) ) ) ++s;

    return *s == '\0';
}

char *is_alnum_params_name[] = {
    "s"
};
unsigned is_alnum_params_type[] = {
    K_STRING
};
unsigned short is_alnum_params_length = (unsigned short) sizeof(is_alnum_params_type) / sizeof(unsigned);
int KAOS_EXPORT Kaos_is_alnum()
{
    char* s = kaos.getVariableString(is_alnum_params_name[0]);
    s = escape_the_sequences_in_string_literal(s);
    bool b = str_is_alnum(s);
    free(s);
    kaos.returnVariableBool(b);
    return 0;
}


int KAOS_EXPORT KaosRegister(struct Kaos _kaos)
{
    kaos = _kaos;

    // String operations
    kaos.defineFunction("replace", K_STRING, replace_params_name, replace_params_type, replace_params_length);
    kaos.defineFunction("upper", K_STRING, upper_params_name, upper_params_type, upper_params_length);
    kaos.defineFunction("lower", K_STRING, lower_params_name, lower_params_type, lower_params_length);
    kaos.defineFunction("capitalize", K_STRING, capitalize_params_name, capitalize_params_type, capitalize_params_length);
    kaos.defineFunction("concat", K_STRING, concat_params_name, concat_params_type, concat_params_length);

    // Information functions
    kaos.defineFunction("length", K_NUMBER, length_params_name, length_params_type, length_params_length);
    kaos.defineFunction("is_empty", K_BOOL, is_empty_params_name, is_empty_params_type, is_empty_params_length);
    kaos.defineFunction("is_numeric", K_BOOL, is_numeric_params_name, is_empty_params_type, is_empty_params_length);
    kaos.defineFunction("is_alpha", K_BOOL, is_alpha_params_name, is_alpha_params_type, is_alpha_params_length);
    kaos.defineFunction("is_alnum", K_BOOL, is_alnum_params_name, is_alnum_params_type, is_alnum_params_length);

    return 0;
}
