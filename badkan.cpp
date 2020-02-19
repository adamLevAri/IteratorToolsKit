//
//  badkan.cpp
//  CutAndChoose
//
//  Created by Adam Lev-Ari on 21/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include "badkan.hpp"
#include <iostream>


int main(){

    vector<int> vecInit = {1,2,3,4};
    vector<string> vecString = {"Hello", "Bye", "Nathan", "Adam"};
    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};
    vector<string> resualt = {"Hello", "HelloBye", "HelloByeNathan", "HelloByeNathanAdam"};
    int index = 0;
    
    badkan::TestCase testcase1;
    
    for (auto i: Accumulate<vector<string>>(vecString)){
        testcase1.setname("Filter_False tests")
        .CHECK_OUTPUT(i, resualt.at(index))
        .print();
        index++;
    }
    
    return 0;
}

