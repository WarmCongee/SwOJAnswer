//
// Created by WarmCongee on 2022/9/27.
//
#include <iostream>
#include <vector>
#include <string>



int get_unique_num(int n) {
    return n == 1 ? 1 : 2 * (n / 2 + 1 - get_unique_num(n / 2));
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<get_unique_num(n);

    return 0;
}