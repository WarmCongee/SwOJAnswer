//
// Created by warmcongee on 22-10-4.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


bool find_source(int n, int k){
    if(n == 1){
        return false;
    } else if(k==std::pow(2,n-1)){
        return true;
    } else if(k<std::pow(2,n-1)){
        return find_source(n-1,k);
    } else if(k>std::pow(2,n-1)){
        return !find_source(n-1, std::pow(2,n)-k);
    }
}

int main(){
    int n = 0;
    int k = 0;
    std::cin >> n >> k;

    if(find_source(n,k)){
        std::cout<<1;
    } else {
        std::cout<<0;
    }

    return 0;
}