//
// Created by WarmCongee on 2022/9/26.
//
#include <iostream>
#include <vector>

int list[210];

std::vector<int> rightBigger(std::vector<int>& nums) {
    std::vector<int> res(nums.size(),0);

    int count = 0;
    for(int i = nums.size()-1; i >=0; i--){
        list[nums[i]+104] += 1;
        count = 0;
        for(int j = 0; j < nums[i]+104; j++){
            count += list[j];
        }
        res[i] = count;
    }
    return res;
}

int task19() {

    std::vector<int> nums;
    int temp = 0;
    while (std::cin >> temp)
    {
        nums.push_back(temp);
    }

    std::vector<int> countR = rightBigger(nums);
    for (int i = 0; i < countR.size(); i++) {
        std::cout << countR[i] << " ";
    }

    return 0;

}
