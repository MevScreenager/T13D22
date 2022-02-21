#include <stdarg.h>
#include <stdlib.h>
#include "documentation_module.h"

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    int *result;
    if (document_count < 15)
        result = calloc(15, sizeof(int));
    else
        result = calloc(document_count, sizeof(int));

    va_list ap;
    va_start(ap, document_count);
    for (int i = 0; i < document_count; i++) {
        char* str = va_arg(ap, char*);
        result[i] = validate(str);
    }
    va_end(ap);

    return result;
}
