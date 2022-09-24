//
// Created by WarmCongee on 2022/9/21.
//
#include <iostream>
#include <vector>
#include <algorithm>

int task12(){
    int num_a, num_b;
    std::cin>>num_a>>num_b;

    bool re_flag = false;
    int temp = num_a;
    if( num_b == 0){
        re_flag = false;
    } else if( temp == 1){
        if (num_b != 0){
            re_flag = true;
        } else {
            re_flag = false;
        }
    } else {
        while (temp != 0){
            if(temp == 1){
                re_flag = true;
                break;
            } else if(temp % num_b != 0) {
                re_flag = false;
                break;
            }
            temp /= num_b;
        }
    }

    if(re_flag){
        std::cout<<1;
    } else {
        std::cout<<0;
    }

    return 0;
}