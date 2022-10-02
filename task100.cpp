//
// Created by WarmCongee on 2022/9/20.
//
#include <iostream>
#include <vector>
#include <algorithm>


bool calculate(int num_a, std::vector<std::tuple<int, bool>> num_map) {
    bool end_flag = true;
    for (auto var: num_map) {
        if (!std::get<1>(var)) {
            end_flag = false;
            break;
        }
    }

    if (num_a == 24 && end_flag) {
        return true;
    } else if (end_flag) {
        return false;
    } else {
        bool re_flag = false;
        for (int i = 0; i < num_map.size(); i++) {
            if (!std::get<1>(num_map[i])) {
                std::vector<std::tuple<int, bool>> next_num_map(num_map);
                std::get<1>(next_num_map[i]) = true;
                if (calculate(num_a + std::get<0>(next_num_map[i]), next_num_map) ||
                    calculate(num_a - std::get<0>(next_num_map[i]), next_num_map) ||
                    calculate(num_a * std::get<0>(next_num_map[i]), next_num_map) ||
                    calculate(num_a / std::get<0>(next_num_map[i]), next_num_map)) {
                    re_flag = true;
                }
            }
        }
        return re_flag;
    }

}

int task100() {
    int nums[4];
    std::cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
    std::vector<std::tuple<int, bool>> num_map_;
    for(int i = 0; i < 4; i++){
        num_map_.emplace_back(nums[i], false);
    }

    bool result_flag = false;
    for (int i = 0; i < num_map_.size(); i++) {
        if (!std::get<1>(num_map_[i])) {
            std::vector<std::tuple<int, bool>> next_num_map(num_map_);
            std::get<1>(next_num_map[i]) = true;
            if (calculate(std::get<0>(next_num_map[i]), next_num_map)) {
                result_flag =  true;
                break;
            }
        }
    }

    if(result_flag) {
        std::cout<<"true";
    } else {
        std::cout<<"false";
    }

    return 0;
}