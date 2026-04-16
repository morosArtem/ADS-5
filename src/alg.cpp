// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int getPriority(char op) {
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> stack;
    std::string result;

    for (size_t i = 0; i < inf.length(); i++) {
        char c = inf[i];
        if (isDigit(c)) {
            while (i < inf.length() && isDigit(inf[i])) {
                result += inf[i];
                i++;
            }
            result += ' ';
            i--;
        }

        else if (c == '(') {
            stack.push(c);
        }

        else if (c == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                result += stack.pop();
                result += ' ';
            }
            stack.pop();
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!stack.isEmpty() && getPriority(stack.top()) >= getPriority(c)) {
                result += stack.pop();
                result += ' ';
            }
            stack.push(c);
        }
    }
    while (!stack.isEmpty()) {
        result += stack.pop();
        result += ' ';
    }
    if (!result.empty() && result[result.length() - 1] == ' ') {
        result.erase(result.length() - 1);
    }

    return result;
}

int eval(const std::string& pref) {
    TStack<int, 100> stack;

    for (size_t i = 0; i < pref.length(); i++) {
        char c = pref[i];

        if (isDigit(c)) {
            int num = 0;
            while (i < pref.length() && isDigit(pref[i])) {
                num = num * 10 + (pref[i] - '0');
                i++;
            }
            stack.push(num);
            i--;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = stack.pop();
            int a = stack.pop();
            int res = 0;

            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;

            stack.push(res);
        }
    }

    return stack.pop();
}
