//
//  Permutation.h
//  Iterable
//
//  Created by Adam Lev-Ari on 11/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef Permutation_h
#define Permutation_h
//TODO: fix tempval size & set<generic> of operator*()

#include <set>
#include <iostream>
#include <type_traits>

using namespace std;

namespace itertools {

    template<typename T>
    struct Permutation {
        
        const T val;
        typedef decltype(val.begin()) IT;
        
        IT It;
        uint SIZE = 0;

        Permutation(const T& val, uint size = 0): val(val), SIZE(size) {
            if (size == 0){
                for (IT i=val.begin(); i!=val.end(); ++i)
                    ++SIZE;
            }
        }

        struct iterator {
            IT It;
            uint valLength;
            T val;
            bool firstIteration = true;
            uint i,j;
            
            iterator(IT It, uint size, T value): It(It), valLength(size), val(value) {}
            
            set<string> operator*() {
                set<string> result;
                uint tempval [valLength];
                    
                
                if (firstIteration){
                    firstIteration = false;
                    for (int i=0; i<valLength; i++) {
                        tempval[i] = i;
                    }
                    tempval[valLength] = valLength;
                    i = 0;
                }
                    
                while(i < valLength){
                    if (tempval[i]!=0)
                        tempval[i]--;
                    
                    j = i % 2 * tempval[i];
                    iter_swap(val.begin()+j, val.begin()+i);
                    result.insert(print(val));
                    i = 1;
                    while(!tempval[i]){
                        tempval[i] = i;
                        i++;
                        
                    }
                }
                return result;
            }
            
            string print(T v){
                ostringstream os;
                for(auto i: v)
                    os << i << " ";
                return os.str();
                
            }
            
            iterator& operator++() {
                ++It;
                return *this;
            }
            bool operator==(const iterator& other) {
                return It==other.It;
            }
            bool operator!=(const iterator& other) {
                return !(operator==(other));
            }
        };
        iterator begin() const {
            return iterator{val.begin(), SIZE, val};
        }
        iterator end()   const {
            return iterator{val.end(), SIZE, val};
        }
    };
}

#endif /* Permutation_h */
