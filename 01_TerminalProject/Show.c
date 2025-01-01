#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ncurses.h>

#define MAX_LENGTH 128 


char **load_content(const FILE *fp, int *n_lines) {
    char **lines = NULL;
    char buffer[MAX_LENGTH];
    *n_lines = 0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        lines = realloc(lines, (*n_lines + 1) * sizeof(char *));
        lines[*n_lines] = strdup(buffer);
        (*n_lines)++;
    }

    return lines;
}


void free_content(char **lines, int n_lines) {
    for (int i = 0; i < n_lines; ++i) {
        free(lines[i]);
    }
    free(lines);
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *fname = argv[1];
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        fprintf(stderr, "Error loading file: %s\n", fname);
        return 1;
    }

    int n_lines;
    char **lines = load_content(fp, &n_lines);
    fclose(fp);

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int h, w;
    getmaxyx(stdscr, h, w);
    int lines_per_page = h - 2;

    int cur_line = 0;
    int c;
    while (true) {
        werase(stdscr);
        mvprintw(0, 0, "File: %s", fname);

        for (int i = 0; i < lines_per_page && (cur_line + i) < n_lines; i++) {
            mvprintw(i + 2, 0, "%.1024s", lines[cur_line + i]);
        }

        refresh();
        c = getch();

        // esc
        if (c == 27) {
            break;
        }

        if ((c == ' ' || c == KEY_DOWN) && (cur_line + lines_per_page) < n_lines) {
            cur_line += 1;
        } else if (c == KEY_UP && cur_line > 0) {
            cur_line -= 1;
        }
    }

    endwin();
    free_content(lines, n_lines);

    return 0;
}
