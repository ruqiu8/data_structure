#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "infix.h"

void test_postfix_conversion() {
    printf("Testing infix_to_postfix...\n");
    char postfix[100];

    infix_to_postfix("3 + 4", postfix);
    assert(strcmp(postfix, "3 4 + ") == 0);

    infix_to_postfix("(1+2)*3", postfix);
    assert(strcmp(postfix, "1 2 + 3 * ") == 0);

    printf("Postfix conversion passed!\n");
}

void test_infix_calculation() {
    printf("Testing calculate_infix...\n");

    assert(calculate_infix("3 + 4") == 7);
    assert(calculate_infix("5 * (6 + 2)") == 40);
    assert(calculate_infix("8 / 4 + 2") == 4);
    assert(calculate_infix("(1 + 2) * (3 + 4)") == 21);

    printf("Infix calculation passed!\n");
}

void test_postfix_calculation() {
    printf("Testing calculate_postfix...\n");

    assert(calculate_postfix("3 4 + ") == 7);
    assert(calculate_postfix("1 2 + 3 * ") == 9);

    printf("Postfix calculation passed!\n");
}

int main() {
    test_postfix_conversion();
    test_postfix_calculation();
    test_infix_calculation();

    printf("\nAll tests passed successfully!\n");
    return 0;
}