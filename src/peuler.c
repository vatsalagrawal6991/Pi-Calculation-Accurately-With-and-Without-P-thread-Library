#include <stdio.h>
#include <math.h>
#include <semaphore.h>
typedef long long int lli;

sem_t s2;
lli me;
double ppie;
int t2;
double b1,c1;
lli rb;

void *peuler(void* i) {
    int ii=(int)i;
    double a,b,c,pi=0.0;
    lli lb=ii*rb;
    lli ub=lb+rb;
    for(;lb<ub;lb++){
        a=(2*lb)+1;
        b=pow(b1,a);
        c=pow(c1,a);
        if(lb%2==0){
            pi=pi+((b+c)/a);
        }
        else{
            pi=pi-((b+c)/a);
        }
    }
    sem_wait(&s2);
    fflush(stdout);
    ppie=ppie+pi;
    sem_post(&s2);
}