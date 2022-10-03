//
// Created by WarmCongee on 2022/9/22.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int effectiveSub(std::vector<int>& nums);

int task16() {
    string str;

    getline(cin, str);

    vector<int> chars;
    for(int i = 0; i < str.length(); i++){
        if(str.at(i) != ' ' && str.at(i) != 'q') {
            chars.push_back(str.at(i) - 48);
        }
    }


    std::cout<<effectiveSub(chars);

    return 0;

}

int effectiveSub(std::vector<int>& nums) {
    int sum = nums.size();
    int re = 0;
    for(int i = 1; i <= sum; i++){

        for(int j = 0; j <= sum-i; j++){
            int count_0 = 0;
            int count_1 = 0;
            for(int k = j; k < j+i; k++){
                if(nums[k]){
                    count_1++;
                } else {
                    count_0++;
                }
            }

            if(count_1>count_0){
                re++;
            }
        }
    }
    return re;
}



