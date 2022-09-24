//
// Created by WarmCongee on 2022/9/22.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int get_steps(std::vector<int>& nums, int sum, int target_sum, int front_flag, int back_flag){
    int sum_head = 0;
    int sum_tail = 0;

    if(sum == target_sum){
        return 1;
    } else if (sum > target_sum || front_flag > back_flag){
        return -1;
    } else {
        int a = get_steps(nums, sum+nums[front_flag], target_sum, front_flag+1, back_flag);
        int b = get_steps(nums, sum+nums[back_flag], target_sum, front_flag, back_flag-1);

        if(a == -1 && b == -1){
            return -1;
        } else if (a == -1) {
            return b+1;
        } else if (b == -1) {
            return a+1;
        } else {
            return ((a<b)?a:b)+1;
        }
    }
}


int task18(){
    int target_sum_;
    std::cin>>target_sum_;
    std::vector<int> nums;
    int temp=0;
    while(std::cin >> temp) {
        nums.push_back(temp); //填充数据
    }


    if(nums.size()>=2){
        int a = get_steps(nums, nums[0], target_sum_, 1, nums.size()-1);
        int b = get_steps(nums, nums[nums.size()-1], target_sum_, 0, nums.size()-2);
        if(a == -1 && b == -1){
            std::cout<< -1;
        } else if (a == -1) {
            std::cout<< b;
        } else if (b == -1) {
            std::cout<< a;
        } else {
            std::cout<< ((a<b)?a:b);
        }
    } else {
        if(nums[0] == target_sum_){
            std::cout<<1;
        } else {
            std::cout<<-1;
        }
    }



    return 0;
}