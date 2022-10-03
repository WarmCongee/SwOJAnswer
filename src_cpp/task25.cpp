//
// Created by warmcongee on 22-9-30.
//
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

/**
 * 这题自己怎么做都wa，电脑里有不干净的东西，用别人的题解洗一洗
 * 来源于题解：https://www.cnblogs.com/qizong007/p/14589383.html
 */
int POW(int a, int b) {

    int MOD = 1e9 + 7;
    int res = 1;
    while(b>0) {
        if(b & 1) {
            res = ((long long)res * a) % MOD;
        }
        a = ((long long)a * a) % MOD;
        b = b >> 1;
    }
    return res;
}

int maxNiceDivisors(int n) {

    int MOD = 1e9 + 7;
    if(n % 3 == 0) {
        return POW(3,n/3);
    }
    else if(n % 3 == 1){
        if(n==1) return 1;
        return ((long long)POW(3,n/3-1) << 2) % MOD;
    }
    else if(n % 3 == 2){
        return ((long long)POW(3,n/3) << 1) % MOD;
    }
    return -1;
}

int task25(){
    int n;
    std::cin>>n;



    std::cout<<maxNiceDivisors(n);
    return 0;
}