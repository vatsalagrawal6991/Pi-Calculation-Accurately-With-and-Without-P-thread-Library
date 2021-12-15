#include <stdio.h>
#include <semaphore.h>
typedef long long int lli;

sem_t s1;
lli ml;
double ppil;
int t1;
lli ra;

void *pleibniz(void* i) {
    int ii=(int)i;
    double pi=0.0,a;
    lli lb=ii*ra;
    lli ub=lb+ra;
    for(;lb<ub;lb++){
        if(lb%2==0){
            a=(2*lb)+1;
            pi=pi+(1/a);
        }
        else{
            a=(2*lb)+1;
            pi=pi-(1/a);
        }
    }
    sem_wait(&s1);
    fflush(stdout);
    ppil=ppil+pi;
    sem_post(&s1);
}
