#include <stdio.h>
#include <stdlib.h>

#include "print_module.h"
#include "documentation_module.h"

int main() {
    print_log(print_char, Module_load_success_message);

    int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    // Output availability for each document....
    if (availability_mask[0])
        printf("Linked lists: available\n");
    else
        printf("Linked lists: unavailable\n");

    if (availability_mask[1])
        printf("Queues: available\n");
    else
        printf("Queues: unavailable\n");

    if (availability_mask[2])
        printf("Maps: available\n");
    else
        printf("Maps: unavailable\n");

    if (availability_mask[3])
        printf("Binary Trees: available");
    else
        printf("Binary Trees: unavailable");

    free(availability_mask);
    return 0;
}
