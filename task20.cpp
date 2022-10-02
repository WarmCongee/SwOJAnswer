//
// Created by WarmCongee on 2022/9/27.
//
#include <iostream>
#include <vector>
#include <string>



std::string NUM_1[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                        "Eight","Nine", "Ten"};
std::string NUM_10[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
                        "Eighty", "Ninety"};

std::string NUM_TH[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                        "Seventeen", "Eighteen", "Nineteen"};

std::string translateNumber(int num) {
    std::string re_str;
    if (num >= 1000000000)
        re_str = translateNumber(num / 1000000000) + " Billion " + translateNumber(num % 1000000000);
    else if (num >= 1000000) {
        re_str = translateNumber(num / 1000000) + " Million " + translateNumber(num % 1000000);
    } else if (num >= 1000) {
        re_str = translateNumber(num / 1000) + " Thousand " + translateNumber(num % 1000);
    } else if (num >= 100) {
        re_str = translateNumber(num / 100) + " Hundred " + translateNumber(num % 100);
    } else if (num >= 20) {
        re_str = NUM_10[num / 10] + " " + NUM_1[num % 10];
    } else if (num >= 11) {
        re_str = NUM_TH[num % 10];
    } else{
        re_str = NUM_1[num];
    }
    if(re_str[re_str.length()-1] == ' '){
        std::string new_str(re_str.begin(),re_str.end()-1);
        re_str = new_str;
    }
    return re_str;
}



int task20() {

    int n;
    std::cin >> n;
    if(n == 0){
        std::cout << "Zero" << std::endl;
    } else {
        std::cout << translateNumber(n) << std::endl;
    }


    return 0;

}