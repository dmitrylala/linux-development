#include <stdio.h>
#include <stdlib.h>
#include <libintl.h>
#include <locale.h>

#include "../lib/libpalindrome.h"
#include "config.h"

#define _(STRING) gettext(STRING)
#define MAX_LENGTH 100


/** @mainpage Guess whether string is palindrome

    The user inputs some string and the programs tells whether string
    is palindrome or not.

    Usage:
    \code{.unparsed}
    guess <string>
    \endcode
*/
int main(int argc, char *argv[]) {
	setlocale (LC_ALL, "");
	bindtextdomain (PACKAGE, LOCALE_PATH);
	textdomain (PACKAGE);

    printf(_("Check if your string is a palindrome!\n"));
    printf(_("Enter your string: "));

    char line[MAX_LENGTH], *input;
    if ((input = fgets(line, MAX_LENGTH, stdin)) == NULL) {
        printf(_("Error reading string\n"));
        return EXIT_FAILURE;
    }
    input[strlen(input)-1] = '\0';

    if (is_palindrome(input)) {
        printf(_("It is palindrome!\n"));
    } else {
        printf(_("It is not palindrome :(\n"));
    }

    return EXIT_SUCCESS;
}
