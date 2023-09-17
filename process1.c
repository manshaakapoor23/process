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
    pid parent_pid = fork();
    struct sched_param param1;
    param1.sched_priority = 0;
    sched_setscheduler(0, SCHED_OTHER, &param1);

    if(parent_pid ==0){
        execl("./counting_program", "counting_program", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else if(pid <0){
        perror("ERROR IN FORK!!!");
        exit(EXIT_FAILURE);
    }
    waitpid(parent_pid, NULL, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double execution_time = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Process 1 Execution Time : %.4f seconds\n", execution_time,";", param1);
    return 0;
}
