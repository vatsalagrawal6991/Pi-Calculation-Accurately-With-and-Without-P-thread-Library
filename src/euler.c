#include <stdio.h>
#include <math.h>
typedef long long int lli;

lli me;
double spie;
int t2;
double b1,c1;

void euler() {
    lli i=0;
    double a,b,c;
    for(i=0;i<me;i++){
        a=(2*i)+1;
        b=pow(b1,a);
        c=pow(c1,a);
        if(i%2==0){
            spie=spie+((b+c)/a);
        }
        else{
            spie=spie-((b+c)/a);
        }
    }
}