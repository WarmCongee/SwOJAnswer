//
// Created by WarmCongee on 2022/9/19.
//
#include <iostream>
#include <vector>
#include <algorithm>

int get_sum(int a){
    int count = 0;
    for(int i = 1; i <= a; i++){
        count+=i;
    }
    return count;
}

int task3(){
    int n;
    std::cin>>n;

    int weeks = n / 7;
    int days = n % 7;

    int num1 = weeks*28+(get_sum(weeks)-weeks)*7;
    int num2 =  weeks*days +get_sum(days);
    std::cout<< num1+num2;
    return 0;
}

