//
// Created by WarmCongee on 2022/9/19.
//
#include <iostream>
#include <vector>
#include <algorithm>

bool in_vector(std::vector<int> nums, int num) {
    bool flag = false;
    for (int i = (nums.size() - 1); i >= 0; i--) {
        if (nums[i] == num) {
            flag = true;
            break;
        }
    }
    return flag;
}

int task2() {
    int n;
    int flag_n;
    std::cin >> n;
    std::cin >> flag_n;
    std::vector<int> nums;

    int temp;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        nums.push_back(temp);
    }
    std::sort(nums.begin(), nums.end(), [](int a, int b) -> bool { return a > b; });


    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] - flag_n < 0) {
            break;
        } else {
            if (in_vector(nums, nums[i] - flag_n)) { count++; }
        }
    }
    std::cout << count;
}

