#include "libpalindrome.h"


int is_palindrome(const char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // skip non-alphanumeric symbols
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        
        // compare lowercase
        if (tolower(s[left]) != tolower(s[right])) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}
