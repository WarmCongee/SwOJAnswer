//
// Created by warmcongee on 22-10-2.
//
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

bool judge(std::vector<int> nums) {
    if(nums.size() <= 2){
        return true;
    } else {
        bool result = true;
        bool in_right = true;
        int right_left_index = -1;
        for(int i = 0; i<=nums.size()-2; i++){
            if(nums.at(i)>nums.at(nums.size()-1) && in_right){
                right_left_index = i;
                in_right = false;
            }
            if(!in_right && nums.at(i)<nums.at(nums.size()-1)){
                result = false;
            }
        }

        if(result){
            if(right_left_index == -1 || right_left_index == 0){
                std::vector<int> right(nums.begin(),nums.end()-1);
                std::vector<int> left;
                return (judge(right) && judge(left));
            } else {
                std::vector<int> right(nums.begin(),nums.begin()+right_left_index-1);
                std::vector<int> left(nums.begin()+right_left_index,nums.end()-1);
                return (judge(right) && judge(left));
            }
        } else {
            return false;
        }

    }
}

/*bool helpVerifyPostorder(int* postorder, int left, int right){
    if(right - left <= 1){
        return true;
    }

    int mid = left;
    for(mid = left; mid < right && postorder[mid] < postorder[right]; mid++);


     for(int i = mid; mid < right; mid++){
         if(postorder[mid] < postorder[right]){
             return false;
         }
     }

     return helpVerifyPostorder(postorder, left, mid - 1) && helpVerifyPostorder(postorder, mid, right - 1);
}*/

vector<string> split(const string& str, const string& delim) {
    vector<string> res;
    if("" == str) return res;
    char * strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());

    char * d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while(p) {
        string s = p;
        res.push_back(s);
        p = strtok(NULL, d);
    }

    return res;
}


int main(){
    std::string str;
    std::cin>>str;
    int nums[1000];
    int nums_index = 0;

    string new_str(str.begin()+1,str.end()-1);
    vector<string> str_nums = split(new_str, ",");

    for (auto var : str_nums){
        nums[nums_index]=stoi(var);
        nums_index++;
    }

    if(helpVerifyPostorder(nums,0,nums_index-1)){
        std::cout<<"true";
    } else {
        std::cout<<"false";
    }
    return 0;
}