#ifndef DATA_STRUCTURE_INFIX_H
#define DATA_STRUCTURE_INFIX_H

// TODO 中缀表达式转前缀表达式
//  先把中缀表达式反转，左括号替换为右括号，右括号替换为左括号
//  再执行一次和中缀转后缀相似的算法，唯一的不同之处是栈顶运算符必须大于当前运算符的等级才弹出
//  最后把结果再反转过来得到最终结果
//  extern void infix_to_prefix(const char *infix, char *pefix);

extern void infix_to_postfix(const char *infix, char *postfix);

extern int calculate_infix(const char *infix);

extern int calculate_postfix(const char *postfix);

#endif