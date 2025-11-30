// Online C compiler to run C program online
#include <stdio.h>

void calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int totalPlanets) {
    if(fuel <= 0){
        printf("ended due to less fuel");
        return;
    }
    if(planet > totalPlanets){
        printf("all planets have been visited");
        return;
    }
    else{
        fuel -= consumption;
        fuel += recharge ;
        if(planet %4 == 0){
            fuel += solarBonus;
        }
        printf("planet %d : remaining fuel %d\n" , planet , fuel);
      calculateFuel(fuel , consumption , recharge , solarBonus , planet+1 ,totalPlanets);
    }
}

int main() {
    int fuel = 100;
    int consumption = 50;
    int recharge = 30;
    int solarBonus = 40;
    int planet = 1;
    int totalPlanets = 8;
    calculateFuel(fuel , consumption , recharge , solarBonus , planet ,totalPlanets);
    return 0;
}