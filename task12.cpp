//
// Created by WarmCongee on 2022/9/21.
//
#include <iostream>
#include <vector>
#include <algorithm>

int num[3];

int task12() {
    int n;
    int index = 0;
    num[0] = 0;
    num[1] = 1;
    num[2] = 1;

    int end_num;
    std::cin>>n;
    if(n < 3 ){
        std::cout<<num[n];
    } else {
        for(int i = 3; i <= n; i++){
            num[i%3] = num[0]+num[1]+num[2];
            end_num = num[i%3];
        }
        std::cout<<end_num;
    }



    return 0;
}