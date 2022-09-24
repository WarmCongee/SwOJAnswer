//
// Created by WarmCongee on 2022/9/21.
//
#include <iostream>

int task14(){
    int n;
    std::cin>>n;
    if(n%2){
        std::cout<<(n+1)/2*n;
    } else {
        std::cout<<(n+1+1)/2*(n+1) - (n+1);
    }

    return 0;
}