#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    struct timespec start;
    struct timespec end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    pid pid1 = fork();
    struct sched_param param1;
    param1.sched_priority = 0;
    sched_setscheduler(0, SCHED_OTHER, &param1);

    if(pid1 ==0){
        execl("./counting_program", "counting_program", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else if(pid1 <0){
        perror("ERROR IN FORK!!!");
        exit(EXIT_FAILURE);
    }
    waitpid(pid1, NULL, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double execution_time = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Process 1 Execution Time : %.4f seconds\n", execution_time,";", param1);
    return 0;
}
