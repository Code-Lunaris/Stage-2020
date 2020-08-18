#include <stdio.h>
#include <ptask.h>
#include <pthread.h>
#include <time.h>
#include <tstat.h>
#include <calibrate.h>

#define true 1
#define false 0


int a, b, c;

int  ok_a;
int ok_b;

ptask inc_a(void){

    //ptask_wait_for_activation();

    while(a<10000){
        a++;
        c++;
        ptask_wait_for_period();
    }

    ok_a = true;

    return;
}

ptask inc_b(void){

    //ptask_wait_for_activation();

    while(b<1000){
        b++;
        c++;
        ptask_wait_for_period();
    }

    ok_b = true;

    return;
}


int main()
{
    a = b = c = 0;
    ok_a = ok_b = false;
    int res;

    ptask_init(SCHED_FIFO, GLOBAL, PRIO_INHERITANCE);
    res = ptask_create_prio(inc_a, 5, 1, NOW);
    res = ptask_create_prio(inc_b, 5, 1, NOW);

    while(!ok_a && !ok_b);

    printf("%d + %d = %d", a, b, c);
    

    return 0;
}

