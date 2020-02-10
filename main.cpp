//
//  main.cpp
//  Iterable
//
//  Created by Adam Lev-Ari on 09/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include <iostream>

#include "Cycle.h"
#include "chain.hpp"
#include "Accumulate.h"
#include "zip_longest.h"
#include "output.h"

#include <vector>
using namespace itertools;
using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> vecInit = {1,2,3,4};
    vector<string> vecString = {"Hello", "Bye", "Nathan", "Adam"};
    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};
    
    /*
    //Defined a final int for output
    cout << "####  Cycle:  ####";
    cout << endl << "Finite<5> Cycle of numbers vector: " << endl;
    for (auto i: Cycle<vector<int>>(vecInit,5))
        cout << i;    // 1234 1234 1234 ...
    cout << endl;
    
    cout << endl << endl << "Finite<5> Cycle of string: " << endl;
    for (auto i: Cycle<string>("Hello",5))
        cout << i;    // 1234 1234 1234 ...
    cout << endl;
    
    cout << endl << endl << "Finite<5> Cycle of float vector: " << endl;
    for (auto i: Cycle<vector<float>>(vecFloat,5))
        cout << i << " ";    // 1234 1234 1234 ...
    cout << endl;
     */
    
    
    cout << endl << endl << "Accumulate of numbers: " << endl;
    for (auto i: Accumulate<vector<int>>(Cycle<vector<int>>(vecInit,5)))
        cout << i << " ";    // 1 3 6 10
    
    
    
    
                                
    cout << endl;
     
    
    return 0;
}



