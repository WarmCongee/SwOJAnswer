//
// Created by WarmCongee on 2022/9/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

char chars[50];

char int_to_char(int a){
    return char(a+65);
}

int task10(){
    int n;
    int index = 0;
    std::cin >> n;

    int temp = n;
    while (temp > 0){
        chars[index] = int_to_char((temp-1)%26);
        index++;
        temp = (temp-1)/26;
    }

    for(int i = index-1; i >= 0; i--){
        std::cout.put(chars[i]);
    }

    return 0;
}