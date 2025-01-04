#include <stdio.h>
#include <string.h>
#include <regex.h>

#define MAX_RESULT_LENGTH 1000
#define MAX_MATCHES 10
#define MAX_ERR_SIZE 256


void regexErrorHandler(int err, regex_t *regex) {
    char buf[MAX_ERR_SIZE];
    size_t err_len = regerror(err, regex, buf, MAX_ERR_SIZE);
    fprintf(stderr, "Regex error: %.*s\n", (int)err_len, buf);
}


int main(int argc, char **argv) {
    if (argc != 4){
        fprintf(stderr, "Usage: %s <regexp> <substitution> <string>\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[1];
    const char *sub = argv[2];
    const char *input = argv[3];

    int err;

    // compile regex
    regex_t regex;
    err = regcomp(&regex, pattern, REG_EXTENDED);
    if (err != 0) {
        regexErrorHandler(err, &regex);
        regfree(&regex);
        return err;
    }

    // compare regex
    regmatch_t matches[MAX_MATCHES];
    err = regexec(&regex, input, MAX_MATCHES, matches, 0);
    if (err != 0) {
        if (err != REG_NOMATCH) {
            regexErrorHandler(err, &regex);
            regfree(&regex);
            return err;
        }
        fprintf(stdout, "%s\n", input);
        regfree(&regex);
        return 0;
    }

    // execute substitution
    char result[MAX_RESULT_LENGTH];

    const char *p_input = input;
    char *p_result = result;

    size_t prefix_len = matches[0].rm_so;
    strncpy(p_result, p_input, prefix_len);
    p_result += prefix_len;

    const char *p_sub = sub;
    while (*p_sub && p_result - result < sizeof(result) - 1) {
       const char *p_sub_next = p_sub + 1;
        if (*p_sub == '\\' && *p_sub_next >= '0' && *p_sub_next <= '9') {
            int match_i = *p_sub_next - '0';
            if (matches[match_i].rm_so == -1) {
                fprintf(stderr, "Error: Invalid reference \\%d\n", match_i);
                regfree(&regex);
                return 1;
            }

            size_t match_len = matches[match_i].rm_eo - matches[match_i].rm_so;
            strncpy(p_result, p_input + matches[match_i].rm_so, match_len);
            p_result += match_len;
    
            p_sub += 2;
        } else if (*p_sub == '\\' && *p_sub_next == '\\') {
            *p_result++ = '\\';
            p_sub += 2;
        } else {
            *p_result++ = *p_sub++;
        }
    }

    const char* suffix_start = p_input + matches[0].rm_eo;
    size_t suffix_len = strlen(suffix_start);
    strncpy(p_result, suffix_start, suffix_len);
    p_result += suffix_len;
    *p_result = '\0';

    fprintf(stdout, "%s\n", result);

    regfree(&regex);
    return 0;
}
