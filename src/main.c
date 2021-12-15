#include <stdio.h>
#include <stdlib.h>
#include "leibniz.h"
#include "euler.h"
#include "pleibniz.h"
#include "peuler.h"
#include "time.h"
#include <pthread.h>
#include <semaphore.h>
#include <math.h>
typedef long long int lli;

sem_t s1,s2;
lli ml=1000000000,me=1000;
double spil=0.0,spie=0.0,ppie=0.0,ppil=0.0;
int t1=10,t2=10;
lli ra=0,rb=0;
double b1=1.0/2.0;
double c1=1.0/3.0;
const double pie=atan(1.0)*4;


int main(int argc, char **argv){
    if (argc==3){
        t1=atoll(argv[1]);
        t2=atoll(argv[1]);
        me=atoll(argv[2]);
        ml=atoll(argv[2]);
    }
    if (argc==5){
        ml=atoll(argv[3]);
        me=atoll(argv[4]);
        t1=atoi(argv[1]);
        t2=atoi(argv[2]);
    }
    if (argc==4){
        ml=atoll(argv[2]);
        me=atoll(argv[3]);
        t1=atoi(argv[1]);
        t2=atoi(argv[1]);
    }
    //for(me=10;me>0;me=me+100){
    spil=0.0,spie=0.0,ppie=0.0,ppil=0.0;
    int i=0;
    ra=ml/t1;
    rb=me/t2;

    double pstl,penl,pttl1,pttl2,psei;
    pthread_t th1[t1],th2[t2];
    sem_init(&s1,0,1);
    sem_init(&s2,0,1);
    pstl=Time();
    for(i=0;i<t1;i++){
        pthread_create(&(th1[i]),NULL,pleibniz,(void*)i);
    }

    for(i=0;i<t1;i++){
        pthread_join(th1[i],NULL);
    }
    psei=Time();
    for(i=0;i<t2;i++){
        pthread_create(&(th2[i]),NULL,peuler,(void*)i);
    }
    for(i=0;i<t2;i++){
        pthread_join(th2[i],NULL);
    }
    penl=Time();
    pttl2=penl-psei;
    printf("Parallel Time for Euler is   :    %lf\n",pttl2);
    pttl1=psei-pstl;
    printf("Parallel Time for Leibniz is :    %lf\n",pttl1);


    double sstl,senl,sttl1,sttl2,stli;
    sstl=Time();
    leibniz();
    stli=Time();
    euler();
    senl=Time();
    sttl2=senl-stli;
    printf("Serial Time for Euler    is  :    %lf\n",sttl2);
    sttl1=stli-sstl;
    printf("Serial Time for Leibniz  is  :    %lf\n",sttl1);
    printf("\n");


    int e=0;
    double su1=sttl1/pttl1;
    double su2=sttl2/pttl2;
    printf("SpeedUp (Parallel V/S Serial) for Leibniz is:    %lf\n",su1);
    printf("SpeedUp (Parallel V/S Serial) for Euler   is:    %lf\n",su2);
    printf("\n");
    printf("Value of           pi     is :    %0.55lf\n",pie);
    printf("\n");
    ppil=4*ppil;
    printf("Parallel Value of leibniz is :    %0.55lf\n",ppil);
    double error=pie-ppil;
    double acc=(ppil/pie)*100.0;
    frexp(error,&e);
    printf("            Error         is :    %G\n",error);
    printf("            Accuracy      is :    %0.55lf %% \n",acc);
    printf("            Exact No of bits :    %d  bits (not in decimal)\n", abs(e));
    ppie=4*ppie;
    printf("Parallel Value of Euler   is :    %0.55lf\n",ppie);
    error=pie-ppie;
    acc=(ppie/pie)*100.0;
    frexp(error,&e);
    printf("           Error          is :    %G\n",error);
    printf("           Accuracy       is :    %0.55lf %% \n",acc);
    printf("           Exact No of bits  :    %d  bits (not in decimal)\n",abs(e));
    spil=4*spil;
    printf("Serial   Value of Leibniz is :    %0.55lf\n",spil);
    error=pie-spil;
    acc=(spil/pie)*100.0;
    frexp(error,&e);
    printf("           Error          is :    %G\n",error);
    printf("           Accuracy       is :    %0.55lf %% \n",acc);
    printf("           Exact No of bits  :    %d  bits (not in decimal)\n",abs(e));
    spie=4*spie;
    printf("Serial   Value of Euler   is :    %0.55lf\n",spil);
    error=pie-spie;
    acc=(spie/pie)*100.0;
    frexp(error,&e);
    printf("           Error          is :    %G\n",error);
    printf("           Accuracy       is :    %0.55lf %% \n",acc);
    printf("           Exact No of bits  :    %d  bits (not in decimal)\n",abs(e));


    /*double error=pie-(4*ppie);
    printf("%lli    %lf     %lf  %lf    %G\n",me,pttl,sttl,4*spie,error);*/
    sem_destroy(&s1);
}
