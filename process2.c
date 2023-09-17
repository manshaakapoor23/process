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
    pid pid2 = fork();
    struct sched_param param2;
    param1.sched_priority = 0;
    sched_setscheduler(0, SCHED_RR, &param2);

    if(pid2 ==0){
        execl("./counting_program", "counting_program", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else if(pid2 <0){
        perror("ERROR IN FORK!!!");
        exit(EXIT_FAILURE);
    }
    waitpid(pid2, NULL, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double execution_time = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Process 1 Execution Time : %.4f seconds\n", execution_time,";", param2);
    return 0;
}
