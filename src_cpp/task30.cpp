//
// Created by warmcongee on 22-10-4.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::string describe_str(int n){
    if(n == 1){
        return "1";
    } else {
        std::string temp = describe_str(n-1);
        std::string re_str = "";
        char last_char;
        int count = 0;
        for(int i = 0; i < temp.length(); i++){
            if(!i || temp[i] == last_char){
                last_char = temp[i];
                count++;
            } else if(temp[i] != last_char){
                re_str = re_str + std::to_string(count) + last_char;
                count = 1;
                last_char = temp[i];
            } else {
                last_char = temp[i];
                count++;
            }
        }
        re_str = re_str + std::to_string(count) + last_char;

        return re_str;
    }
}

int main(){
    int n = 0;
    std::cin >> n;

    std::cout<< describe_str(n);
    return 0;
}