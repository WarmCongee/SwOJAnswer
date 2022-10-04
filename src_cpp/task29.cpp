//
// Created by warmcongee on 22-10-4.
//
#include <iostream>
#include <vector>
#include <algorithm>

int count = 0;

void load_list(std::vector<int>& nums, int start, bool& end){
    if(start == (nums.size()-1)){
        for (auto var: nums){
            std::cout<<var;
        }
        std::cout<<std::endl;
        return;
    }

    for (int i = start; i<=nums.size()-1; i++){
        std::swap(nums[i],nums[start]);
        if(i>start && i-start>=2){
            for(int j = i; j > start+1; j--){
                std::swap(nums[j],nums[j-1]);
            }
        }


        load_list(nums, start+1, end);
        if(i>start && i-start>=2){
            for(int j = start+1; j < i; j++){
                std::swap(nums[j],nums[j+1]);
            }
        }

        std::swap(nums[i],nums[start]);
    }
}


int main(){
    int n = 0;
    std::cin>>n;
    std::vector<int> nums;
    for (int i = 0; i<n; i++){
        nums.push_back(i+1);
    }
    bool flag = false;
    load_list(nums, 0, flag);


    return 0;
}