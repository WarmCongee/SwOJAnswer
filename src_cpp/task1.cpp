//
// Created by WarmCongee on 2022/9/19.
//
#include <iostream>
#include <vector>
#include <algorithm>


int task1(){
    int n;
    std::cin >> n;
    std::vector<int> nums;
    for(int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }
    std::sort(nums.begin(), nums.end(), [](int a, int b)-> bool {return a > b;});

    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        if (count < nums[i]){
            count++;
        }
    }
    std::cout << count;

    return 0;
}

