//
// Created by WarmCongee on 2022/9/26.
//

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> split_str(std::string expression){
    std::string str(expression.begin()+2,expression.end()-1);
    std::vector<std::string> str_vec;
    int begin_index = 0;
    int end_index = 0;
    int count = 0;
    for(int i = 0; i < str.length(); i++){
        end_index = i;
        if(str[i]=='('){
            count++;
        } else if(str[i]==')'){
            count--;
        }
        if(count == 0 && str[i]==','){
            std::string new_str(str.begin()+begin_index,str.begin()+end_index);
            str_vec.push_back(new_str);
            begin_index = i+1;
        }
    }
    std::string new_str(str.begin()+begin_index,str.end());
    str_vec.push_back(new_str);
    return str_vec;
}

bool trueOrFalse(std::string expression) {
    if(expression.length() == 1){
        return (expression == "t");
    }
    bool re_flag;
    if(expression[0] == '!') {
        std::string str(expression.begin()+2,expression.end()-1);
        return !trueOrFalse(str);
    } else if(expression[0] == '&') {
        re_flag = true;
        std::vector<std::string> str_vec = split_str(expression);

        for (auto var: str_vec){
            if(!trueOrFalse(var)){
                re_flag = false;
            }
        }
        return re_flag;
    } else {
        re_flag = false;
        std::vector<std::string> str_vec = split_str(expression);
        for (auto var: str_vec){
            if(trueOrFalse(var)){
                re_flag = true;
            }
        }
        return re_flag;
    }


}

int task19() {
    std::string str;
    std::cin >> str;
    std::cout << trueOrFalse(str) << std::endl;

    return 0;

}
