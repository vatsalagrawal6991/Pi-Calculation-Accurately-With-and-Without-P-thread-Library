#include <stdio.h>
typedef long long int lli;

lli ml;
double spil;
int t1;

void leibniz() {
    lli i=0;
    double a;
    for(i=0;i<ml;i++){
        if(i%2==0){
            a=(2*i)+1;
           spil=spil+(1/a);
        }
        else{
            a=(2*i)+1;
            spil=spil-(1/a);
        }
    }
}