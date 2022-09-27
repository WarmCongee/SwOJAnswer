//
// Created by WarmCongee on 2022/9/28.
//
#include <iostream>
#include <vector>
#include <string>

int main() {
    int num[2];
    int n;
    int index = 0;
    num[0] = 0;
    num[1] = 1;

    int end_num;
    std::cin>>n;
    if(n < 2 ){
        std::cout<<num[n];
    } else {
        for(int i = 2; i <= n; i++){
            num[i%2] = num[0]+num[1];
            end_num = num[i%2];
        }
        std::cout<<end_num;
    }

    return 0;
}