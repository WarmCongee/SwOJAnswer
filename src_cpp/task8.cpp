//
// Created by WarmCongee on 2022/9/20.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>




bool is_power(std::vector<int> n){
    int num = 0;
    bool flag = false;
    if(n[0] == 0){
        flag = false;
    } else {
        num = num + n[0];
        for (int i = 1; i < n.size(); i++){
            num = num*10 + n[i];
        }
        while (num%2 != 1){
            num = num/2;
        }
        if(num == 1){
            flag = true;
        }
    }
    return flag;

}

int task8(){
    std::string s;
    std::cin >> s;
    std::vector<int> nums;
    for(int i = 0; i < s.size(); i++){
        nums.push_back((int)s[i]-48);
    }
    int flag_n = false;
    do {
        if(is_power(nums)){
            flag_n = true;
        }
    } while (next_permutation(nums.begin(),nums.end()));

    if(flag_n){
        std::cout<<"true";
    } else {
        std::cout<<"false";
    }
    return 0;
}