#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(void)
{
    struct timespec ts;

    if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
        perror("clock_gettime error");
        exit(EXIT_FAILURE);
    }

    printf("ts.tv_sec       : %ld\n", ts.tv_sec);
    printf("ts.tv_nsec      : %ld\n", ts.tv_nsec);
    printf("ts.tv_nsec/1e9  : %f\n", ts.tv_nsec/1e9);
    printf("Time Since Epoch: %f\n", ts.tv_sec + ts.tv_nsec/1e9);
    exit(EXIT_SUCCESS);
}
