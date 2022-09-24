//
// Created by WarmCongee on 2022/9/20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int task5()
{
    int N,n=1,s=0,i,x,t,p;
    double y;
    std::cin>>N;
    for(x=1,t=N;1;x++){
        t=t/10;
        if(t==0) break;
    }
    for(;N>100;){
        y=pow(10,x-1);
        p=N/(int)y;
        if(p==1) s+=(x-1)*(y/10)+1+N-y*p;
        if(p>=2) s+=p*(x-1)*(y/10)+y;
        x--;
        N-=y*p;
    }
    for(;n<=N;n++){
        for(i=n;i>=1;){
            if(i%10==1) s++;
            i/=10;
        }
    }
    std::cout<<s;
    return 0;
}
