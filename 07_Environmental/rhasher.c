#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <rhash.h>

#include "config.h"

#ifdef READLINE
#include <readline/readline.h>
#endif


int main() {
    char *line = NULL;
    size_t len = 0;

    rhash_library_init();

#ifdef READLINE
    while (line = readline("> ")) {
#else
    while (getline(&line, &len, stdin) != -1) {
#endif

        len = strlen(line);
        if (len && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        char *command = strtok(line, " ");
        char *message = strtok(NULL, " ");

        if (!command || !message) {
            fprintf(stderr, "Bad input! Format: <hashing algorithm> <message/filename>\n");
            continue;
        }

        // convert command to uppercase
        for (size_t i = 0; i < strlen(command); i++) {
            command[i] = toupper(command[i]);
        }

        int hashing_algorithm;
        if (!strcmp(command, "MD5")) {
            hashing_algorithm = RHASH_MD5;
        } else if (!strcmp(command, "SHA1")) {
            hashing_algorithm = RHASH_SHA1;
        } else if (!strcmp(command, "TTH")) {
            hashing_algorithm = RHASH_TTH;
        } else {
            fprintf(stderr, "Bad command: %s. Available: md5, sha1, tth\n", command);
            continue;
        }

        unsigned char hash[64];
        int result = 0;
        if (message[0] == '\"') {
            result = rhash_msg(hashing_algorithm, message + 1, strlen(message) - 1, hash);
        } else {
            result = rhash_file(hashing_algorithm, message, hash);
        }
        if (result < 0) {
            fprintf(stderr, "Error while computing hash\n");
            continue;
        }

        char output[128];
        int rhash_flag = isupper(command[0]) ? RHPR_HEX : RHPR_BASE64;
        rhash_print_bytes(output, hash, rhash_get_digest_size(hashing_algorithm), rhash_flag);
        printf("%s\n", output);
    }

#ifdef READLINE
    free(line);
#endif

    return 0;
}
