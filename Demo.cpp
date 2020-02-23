//
//  Demo.cpp
//  Iterable
//
//  Created by Adam Lev-Ari on 09/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include <iostream>

#include "Cycle.h"
#include "Accumulate.h"
#include "Zip_Longest.h"
#include "Permutation.h"
#include "Filter_False.h"
#include "output.h"

#include <vector>
using namespace itertools;
using namespace std;


struct lessThan
{
    template<typename T>
    bool operator()(T& i) const { return i < 3; }
};

int main(int argc, const char * argv[]) {
    
    vector<int> vecInit = {1,2,3,4};
    vector<string> vecString = {"Hello", "Bye", "Adam"};
    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};
    
    
    //Defined a final int for output
    cout << "####  Cycle:  ####" << endl;
    cout << "Finite<limit: 5 times> Cycle of numbers vector: " << endl;
    for (auto i: Cycle<vector<int>>(vecInit,5))
        cout << i;    // 1234 1234 1234 ...
    cout << endl << endl;
    
    cout << "####  Accumulate:  ####";
    cout << endl << "Accumulate of vector<string>: " << endl;
    for (auto i: Accumulate<vector<string>>(vecString) )
        cout << i << " ";
    cout << endl << endl;
    
    cout << "####  Zip_Longest:  ####";
    cout << endl << "zip longest of vector<float> & vector<int>: " << endl;
    for (auto i: Zip_Longest<vector<float>, vector<int>>(vecFloat, vecInit) )
        cout << i << " ";
    cout << endl << endl;
    
    
    cout << "####  Permutation:  ####";
    cout << endl << "Permutation of string: 'ABCD'" << endl;
    for (auto i: Permutation<string>("ABCD") )
        cout << i;
    cout << endl << endl;
    
    
    cout << "####  Filter False:  ####";
    cout << endl << "Filter all Even numbers of vector{1,2,3,4}: " << endl;
    for (auto i: Filter_False<vector<int>, lessThan>(vecInit, lessThan()) )
    cout << i << " ";
    cout << endl << endl;

    
    cout << endl;
    return 0;
}



