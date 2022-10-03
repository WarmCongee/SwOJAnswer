//
// Created by WarmCongee on 2022/9/20.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

int n;
std::queue<int> my_queue;



int task6(){
    std::cin>>n;

    int count = 0;
    int temp_sum = 0;

    int i = 1;
    while(i <= n+1){

        if(temp_sum == n){
            count++;
            temp_sum = temp_sum - my_queue.front();
            my_queue.pop();
        } else if(temp_sum > n){
            temp_sum = temp_sum - my_queue.front();
            my_queue.pop();
            if(temp_sum == n){
                count++;
                temp_sum = temp_sum - my_queue.front();
                my_queue.pop();
            }
        } else {
            my_queue.push(i);
            temp_sum+=i;
            i++;
            continue;
        }

    }

    std::cout<<count;

    return 0;
}
