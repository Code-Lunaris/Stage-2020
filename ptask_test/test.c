#include <stdio.h>
#include <ptask.h>
#include <pthread.h>
#include <time.h>
#include <assert.h>



ptask mytask(void){

    while(1){
        printf("Task %d is running\n", ptask_get_index());
        ptask_wait_for_period();
    }
}



int main()
{
    int tid1, tid2;

    ptask_init(SCHED_FIFO, GLOBAL, PRIO_INHERITANCE);
    tid1 = ptask_create_prio(mytask, 5000, 2, NOW);   // tâche périodique de période 5 secondes (5000 ms)
    tid2 = ptask_create_prio(mytask, 1000, 1, NOW);   // tâche péiodique de période 1 seconde (1000 ms)

    assert(tid1 != -1 && tid2 != -1);

    while(1);
    

    return 0;
}

