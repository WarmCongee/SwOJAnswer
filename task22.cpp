//
// Created by WarmCongee on 2022/9/27.
//
#include <iostream>
#include <vector>
#include <string>


bool num_flag[1000000001];

int get_unique_num(int num, int left, bool left_start){
    bool flag = false;
    if(left==1){
        for(int i = 1; i <= num; i++){
            if(!num_flag[i]){
                return i;
            }
        }
    } else {
        if(left%2){
            left = (left-1)/2;
        } else {
            left = left/2;
        }
        if(left_start){
            int i = 1;
            while (i<=num){
                if(!num_flag[i]){
                    flag = !flag;
                    if(flag){
                        num_flag[i] = true;
                    }
                }
                i++;
            }
        } else {
            int i = num;
            while (i >= 1){
                if(!num_flag[i]){
                    flag = !flag;
                    if(flag){
                        num_flag[i] = true;
                    }
                }
                i--;
            }
        }
        return get_unique_num(num, left, !left_start);
    }

}

int main(){
    int n;
    std::cin>>n;
    std::cout<<get_unique_num(n, n, true);

    return 0;
}