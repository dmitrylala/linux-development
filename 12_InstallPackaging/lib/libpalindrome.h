#pragma once

#include <string.h>
#include <ctype.h>


/**
 * @brief Checks whether a string is a palindrome.
 *
 * This function determines whether arbitrary string is palindrome,
 * all non-alpanumeric characters are ignored, chars are compared lowercase.
 *
 * @param s Input string.
 * @return 0 or 1 indicating whether s is palindrome.
 */
int is_palindrome(const char *s);
