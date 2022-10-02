//
// Created by WarmCongee on 2022/9/22.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string caculateRes(string str);
char get_one_answer(vector<char> chars_);

int task15()

{

    string str;

    cin>>str;

    cout<<caculateRes(str);

    return 0;

}

string caculateRes(string str) {
    vector<char> chars;
    for(int i = 0; i < str.size(); i++){
        chars.push_back(str.at(i));
    }
    string s(1,get_one_answer(chars));
    return s;
}

char get_one_answer(vector<char> chars_){
    if(chars_[1] != '?'){
        return chars_[0];
    } else {
        if(chars_[0] == 'F' || chars_[0] == '0'){

            int count = 0;
            bool flag = false;
            for(int i = 0; i < (chars_.size()-1)/2; i++){

                if(chars_[(i+1)*2-1] == '?'){
                    count++;
                } else if(chars_[(i+1)*2-1] == ':'){
                    count--;
                }
                if(flag && count == 0){
                    vector<char> new_chars_(chars_.begin()+(i+1)*2,chars_.end());
                    return get_one_answer(new_chars_);
                }
                flag = true;
            }
        } else {
            vector<char> new_chars_(chars_.begin()+2,chars_.end());
            return get_one_answer(new_chars_);
        }
    }
}



