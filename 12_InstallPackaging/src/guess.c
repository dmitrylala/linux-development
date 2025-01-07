#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libintl.h>
#include <locale.h>
#include <ctype.h>

#include "config.h"

#define _(STRING) gettext(STRING)
#define MAX_LENGTH 100


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


int main(int argc, char *argv[]) {
	setlocale (LC_ALL, "");
	bindtextdomain (PACKAGE, LOCALE_PATH);
	textdomain (PACKAGE);

    printf(_("Check if your string is a palindrome!\n"));

    char input[MAX_LENGTH];
    printf(_("Enter your string: "));
    fgets(input, MAX_LENGTH, stdin);
    input[strlen(input)-1] = '\0';

    if (is_palindrome(input)) {
        printf(_("It is palindrome!\n"));
    } else {
        printf(_("It is not palindrome :(\n"));
    }

    return EXIT_SUCCESS;
}
