// fun.cpp
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    int i = 0;
    bool inWord = false;
    bool hasDigit = false;

    while (str[i] != '\0') {
        char c = str[i];
        if (c == ' ') {
            if (inWord && !hasDigit) {
                count++;
            }
            inWord = false;
            hasDigit = false;
        } else {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
            if (c >= '0' && c <= '9') {
                hasDigit = true;
            }
        }
        i++;
    }
    if (inWord && !hasDigit) {
        count++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    int i = 0;
    bool inWord = false;
    bool firstChar = true;
    bool valid = true;

    while (str[i] != '\0') {
        char c = str[i];
        if (c == ' ') {
            if (inWord && valid) {
                count++;
            }
            inWord = false;
            firstChar = true;
            valid = true;
        } else {
            if (!inWord) {
                inWord = true;
                firstChar = true;
                valid = true;
            }
            if (firstChar) {
                if (!(c >= 'A' && c <= 'Z')) {
                    valid = false;
                }
                firstChar = false;
            } else {
                if (!(c >= 'a' && c <= 'z')) {
                    valid = false;
                }
            }
        }
        i++;
    }
    if (inWord && valid) {
        count++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int totalLen = 0;
    unsigned int wordCount = 0;
    int i = 0;
    bool inWord = false;
    unsigned int curLen = 0;

    while (str[i] != '\0') {
        char c = str[i];
        if (c == ' ') {
            if (inWord) {
                totalLen += curLen;
                wordCount++;
                inWord = false;
                curLen = 0;
            }
        } else {
            if (!inWord) {
                inWord = true;
                curLen = 0;
            }
            curLen++;
        }
        i++;
    }
    if (inWord) {
        totalLen += curLen;
        wordCount++;
    }

    if (wordCount == 0) {
        return 0;
    }

    double avg = static_cast<double>(totalLen) / wordCount;
    unsigned int result = static_cast<unsigned int>(avg + 0.5);
    return result;
}
