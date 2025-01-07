#include <check.h>
#include "../lib/libpalindrome.h"


#test palindrome
    ck_assert_int_eq(is_palindrome("ahaha"), 1);

#test not_palindrome
    ck_assert_int_eq(is_palindrome("ahah"), 0);

#test empty
    ck_assert_int_eq(is_palindrome(""), 1);

#test ignored_non_alphanum
    ck_assert_int_eq(is_palindrome("ha ah"), 1);
