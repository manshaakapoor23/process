#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    struct timespec start;
    struct timespec end;
    clocl_gettime(CLOCK_MONOTONIC, &start);
    pid pid3 = fork();
    struct sched_param param3;
    param1.sched_priority = 0;
    sched_setscheduler(0, SCHED_FIFO, &param3);

    if(pid3 ==0){
        execl("./counting_program", "counting_program", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else if(pid3 <0){
        perror("ERROR IN FORK!!!");
        exit(EXIT_FAILURE);
    }
    waitpid(pid3, NULL, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double execution_time = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Process 1 Execution Time : %.4f seconds\n", execution_time,";", param3);
    return 0;
}
