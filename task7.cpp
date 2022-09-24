//
// Created by WarmCongee on 2022/9/20.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

void could_div(int num, int k){
    int temp_a = 0;
    int count = 0;
    int i = 0;
    for(i = 1; i <= 9; i++){
        if((i*k)%10 == num%10){
            count = i;
            break;
        }
    }
    if(i == 10){
        std::cout<<-1;
    } else {
        if(k*i <= num){
            std::cout<<count;
        } else {
            std::cout<<-1;
        }

    }

}

int task7(){
    int num;
    int k;
    std::cin>>num>>k;
    could_div(num,k);
}