// Online C compiler to run C program online
#include <stdio.h>

float repay(float loan , float rate , int years){
    if( years == 0){
        printf("time period ended");
        return loan;
    }
    if(loan <= 0){
        printf("all clear");
        return 0;
    }
    else{
        float payment = loan/years;
        loan -= payment;
        loan += loan*rate;
        printf("\nYEAR %d: remaining amount:%.2f\n " , years , loan);
       return payment +  repay(loan , rate , years-1);
       // year sahi kro
    }
}

int main() {
    int years = 3;
    float loan = 100000;
    float rate = 0.05;
    
   repay(loan , rate , years );

    return 0;
}