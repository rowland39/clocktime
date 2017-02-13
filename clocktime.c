#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(void)
{
    time_t tsec;
    struct timespec ts;

    if ((tsec = time(NULL)) == ((time_t) -1)) {
        perror("time error");
        exit(EXIT_FAILURE);
    }

    if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
        perror("clock_gettime error");
        exit(EXIT_FAILURE);
    }

    printf("\nTime Test\n");
    printf("---------\n");
    printf("tsec = time(NULL)\n");
    printf("clock_gettime(CLOCK_REALTIME, &ts)\n\n");
    printf("tsec             = %ld s\n", tsec);
    printf("ts.tv_sec        = %ld s\n", ts.tv_sec);
    printf("ts.tv_nsec       = %ld ns\n", ts.tv_nsec);
    printf("ts.tv_nsec/1e9   = %f s\n", ts.tv_nsec/1e9);
    printf("Time Since Epoch = %f s\n\n", ts.tv_sec + ts.tv_nsec/1e9);
    exit(EXIT_SUCCESS);
}
