//
// Created by WarmCongee on 2022/9/19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int nums[100];
int index = 0;

int task4(){
    int n;
    std::cin >> n;

    int count = 0;
    int temp = n;

    if(n%2 != 1 && n!=2){
        for(int i = 1; i < n/2; i++){
            if(temp-i*2 > 2*i){
                nums[index] = i*2;
                temp = temp-i*2;
                index++;
            } else {
                nums[index] = temp;
                break;
            }
        }

        std::cout<<"[";
        if(index == 0){
            std::cout<<nums[0];
        } else {

            for(int i = 0; i<index; i++){
                std::cout<<nums[i]<<", ";
            }
            std::cout<<nums[index];
        }
        std::cout<<"]";
    } else if(n ==2 ){
        std::cout<<"[2]";
    } else {
        std::cout<<"[]";
    }

    return 0;
}
