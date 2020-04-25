#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Chaos.h"

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

int KAOS_EXPORT KaosRegister(struct Kaos _kaos)
{
    kaos = _kaos;
    kaos.defineFunction("replace", K_STRING, replace_params_name, replace_params_type, replace_params_length);

    return 0;
}
