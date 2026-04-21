#include "infix.h"

#include <ctype.h>

#include "char_seq_stack.h"
#include "int_link_stack.h"

static int priority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }

    if (op == '*' || op == '/') {
        return 2;
    }

    return 0;
}

static void process_op(IntLinkStack *num_stack, CharSeqStack *op_stack) {
    int b, a, res;
    char op;

    // 弹出两个操作数
    int_link_stack_pop(num_stack, &b);
    int_link_stack_pop(num_stack, &a);
    // 弹出操作符
    char_seq_stack_pop(op_stack, &op);

    switch (op) {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        default:
            res = 0;
            break;
    }
    // 将结果压回操作数栈
    int_link_stack_push(num_stack, &res);
}

void infix_to_postfix(const char *infix, char *postfix) {
    CharSeqStack *stack = char_seq_stack_create();
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char c = infix[i];

        if (c == ' ') {
            i++;
            continue;
        }
        if (isdigit(c)) {
            postfix[j++] = c;
            postfix[j++] = ' '; // 分隔
        } else if (c == '(') {
            char_seq_stack_push(stack, &c);
        }
        // 右括号
        else if (c == ')') {
            char top;
            while (!char_seq_stack_empty(stack)) {
                char_seq_stack_pop(stack, &top);
                if (top == '(') {
                    break;
                }

                postfix[j++] = top;
                postfix[j++] = ' ';
            }
        } else {
            char top;
            while (!char_seq_stack_empty(stack)) {
                char_seq_stack_peek(stack, &top);
                if (priority(top) >= priority(c)) {
                    char_seq_stack_pop(stack, &top);
                    postfix[j++] = top;
                    postfix[j++] = ' ';
                } else {
                    break;
                }
            }
            char_seq_stack_push(stack, &c);
        }
        i++;
    }
    char top;
    while (!char_seq_stack_empty(stack)) {
        char_seq_stack_pop(stack, &top);
        postfix[j++] = top;
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
    char_seq_stack_destroy(&stack);
}

int calculate_infix(const char *infix) {
    IntLinkStack *num_stack = int_link_stack_create();
    CharSeqStack *op_stack = char_seq_stack_create();
    int i = 0;
    while (infix[i] != '\0') {
        char c = infix[i];

        if (c == ' ') {
            i++;
            continue;
        }
        if (isdigit(c)) {
            int val = c - '0';
            int_link_stack_push(num_stack, &val);
        } else if (c == '(') {
            char_seq_stack_push(op_stack, &c);
        } else if (c == ')') {
            char top_op;
            char_seq_stack_peek(op_stack, &top_op);
            while (!char_seq_stack_empty(op_stack) && top_op != '(') {
                process_op(num_stack, op_stack);
                if (!char_seq_stack_empty(op_stack)) {
                    char_seq_stack_peek(op_stack, &top_op);
                }
            }
            // 弹出 (
            char_seq_stack_pop(op_stack, &top_op);
        } else {
            char top_op;
            while (!char_seq_stack_empty(op_stack)) {
                char_seq_stack_peek(op_stack, &top_op);
                if (top_op != '(' && priority(top_op) >= priority(c)) {
                    process_op(num_stack, op_stack);
                } else {
                    break;
                }
            }
            char_seq_stack_push(op_stack, &c);
        }
        i++;
    }
    while (!char_seq_stack_empty(op_stack)) {
        process_op(num_stack, op_stack);
    }

    int final_res;
    int_link_stack_pop(num_stack, &final_res);

    // 销毁栈释放内存
    int_link_stack_destroy(&num_stack);
    char_seq_stack_destroy(&op_stack);

    return final_res;
}

int calculate_postfix(const char *postfix) {
    IntLinkStack *stack = int_link_stack_create();
    int i = 0;
    int res;
    while (postfix[i] != '\0') {
        char c = postfix[i];
        if (c == ' ') {
            i++;
            continue;
        }
        if (isdigit(c)) {
            IntElemType a = c - '0';
            int_link_stack_push(stack, &a);
        } else {
            IntElemType b, a;
            int_link_stack_pop(stack, &b);
            int_link_stack_pop(stack, &a);
            switch (c) {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    res = a / b;
                    break;
            }
            int_link_stack_push(stack, &res);
        }
        i++;
    }
    int_link_stack_pop(stack, &res);
    int_link_stack_destroy(&stack);
    return res;
}