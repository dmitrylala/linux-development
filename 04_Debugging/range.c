#include <stdio.h>
#include <stdlib.h>


struct Range
{
    int start, stop, step;
};

void init_range(struct Range *r, int argc, char *argv[])
{
    if (argc == 2) {
        r->stop = atoi(argv[1]);
        return;
    }

    r->start = atoi(argv[1]);
    r->stop = atoi(argv[2]);

    if (argc == 4) {
        r->step = atoi(argv[3]);
    }

    return;
}

int main(int argc, char *argv[]) {
    if ((argc == 1) || (argc > 4)) {
        fprintf(
            stderr,
            "Provided wrong number of parameters: %d\n"\
            "Should be from 1 to 3 inclusive: stop, start stop, or start stop step\n",
            argc - 1
        );
        return 1;
    }

    struct Range r = { .start = 0, .stop = 0, .step = 1 };
    init_range(&r, argc, argv);

    for (int i = r.start; i < r.stop; i += r.step) {
        printf("%d\n", i);
    }
}
