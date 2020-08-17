#include <stdio.h>
#include <ptask.h>
#include <pthread.h>
#include <time.h>
#include <tstat.h>
#include <calibrate.h>

#define true 1
#define false 0

#define MODE_OFF 0
#define MODE_RUN 1
#define MODE_MEAS 2

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

ptask task(){

    //ptask_wait_for_activation();

    while(1){
        //sleep(1); // ne jamais appeler sleep dans une RL task
        //la tâche peut dépasser sa dealdline
        work_for(1,SEC);
        printf("Hello from %d task\n", ptask_get_index());
        ptask_wait_for_period();
    }


}

int main_1()
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


int main(){

    int cpt =0;
    int tid;
    tspec meas;
    rtmode_t mymodes;
    tpars param;

    calibrate();

    // init
    ptask_init(SCHED_FIFO, GLOBAL, PRIO_INHERITANCE);
    rtmode_init(&mymodes, 2);

    //création des paramètres de la tâches
    ptask_param_init(param);
    ptask_param_period(param, 2, SEC);
    ptask_param_priority(param, 4);
    ptask_param_argument(param, &cpt); 
    ptask_param_measure(param);

    //configurations des modes
    ptask_param_modes(param, mymodes);
    ptask_param_mode_add(param, MODE_RUN);

    tid = ptask_create_param(task, &param);


    //assert(tid!=-1);
    //printf("%d\n", tid);

    rtmode_changemode(&mymodes, MODE_RUN);

    while(1){
        sleep(6);
        rtmode_changemode(&mymodes, MODE_MEAS);
        meas = ptask_get_wcet(tid);
        printf("maximum excecution time %ld \n", tspec_to(&meas, SEC));
        meas = ptask_get_avg(tid);
        printf("averange time %ld\n", tspec_to(&meas, SEC));
        printf("\n---------------------\n");
        rtmode_changemode(&mymodes, MODE_RUN);
    }


    return 0;
}
