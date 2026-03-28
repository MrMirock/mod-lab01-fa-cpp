// Copyright 2022 UNN-IASR
// main.cpp
#include <iostream>
#include "fun.h"

int main() {
    std::cout << "=== Тесты для faStr1 (слова без цифр) ===\n";
    const char *t1[] = {
        "Hello 123 world!",
        "abc def 789",
        "   one two three   ",
        "12345",
        "no digits here",
        "mix3d w0rd with numb3rs",
        "",
        "   ",
        "a1 b2 c3 d4",
        "test"
    };
    for (const char *s : t1) {
        std::cout << "\"" << s << "\" -> " << faStr1(s) << std::endl;
    }

    std::cout << "\n=== Тесты для faStr2 "
              << "(заглавная первая, остальные строчные лат.) ===\n";
    const char *t2[] = {
        "Hello world! 123 abc",
        "Apple Banana Cat",
        "Hello World!",
        "A a B b",
        "A1b2 C3d4",
        "Correct Word",
        "Not correct word",
        "ALLCAPS",
        "lowercase",
        "   First   Second   ",
        "",
        "   "
    };
    for (const char *s : t2) {
        std::cout << "\"" << s << "\" -> " << faStr2(s) << std::endl;
    }

    std::cout << "\n=== Тесты для faStr3 "
              << "(средняя длина слова, округление) ===\n";
    const char *t3[] = {
        "   Hello   world   ",
        "a bb ccc dddd",
        "one two three four five",
        "short longg",
        "a",
        "abc def",
        "   ",
        "",
        "word",
        "a bb ccc",
        "test for rounding",
        "abcde fghij"
    };
    for (const char *s : t3) {
        std::cout << "\"" << s << "\" -> " << faStr3(s) << std::endl;
    }

    return 0;
}
