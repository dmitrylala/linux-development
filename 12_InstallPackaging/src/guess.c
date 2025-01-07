#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libintl.h>
#include <locale.h>
#include "config.h"

#define _(STRING) gettext(STRING)


int main(int argc, char *argv[]) {
	setlocale (LC_ALL, "");
	bindtextdomain (PACKAGE, LOCALE_PATH);
	textdomain (PACKAGE);

	printf(_("Think of a number from 1 to 100.\n"));

    int left = 1;
    int right = 100;
    char answer[5];
	while (left < right) {
        int mid = (left + right) / 2;
    
		printf(_("Is your number greater than %d?\n"), mid);
        if (scanf("%s", answer) < 0) {
            return EXIT_FAILURE;
        }

        if (strcmp(answer, _("yes")) == 0) {
            left = mid + 1;
        } else if (strcmp(answer, _("no")) == 0) {
            right = mid;
        } else {
            printf(_("Please type yes or no.\n"));
        }
    }

    printf(_("Your number is %d.\n"), left);

    return EXIT_SUCCESS;
}
