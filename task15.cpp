//
// Created by WarmCongee on 2022/9/21.
//
#include <iostream>
#include <vector>
#include <algorithm>

int count_cut(int num){
    if(num == 1){
        return 0;
    } else {
        if(num%2 == 0){
            return count_cut(num/2)+1;
        } else {
            int temp_a = count_cut(num+1)+1;
            int temp_b = count_cut(num-1)+1;
            return temp_a > temp_b?temp_b:temp_a;
        }
    }
}

int task15(){

    int n;
    std::cin>>n;

    std::cout<<count_cut(n);
    return 0;
}
