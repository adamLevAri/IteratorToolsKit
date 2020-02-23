//
//  Cycle.hpp
//  Iterable
//
//  Created by Adam Lev-Ari on 09/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef Cycle_h
#define Cycle_h

#include <iostream>

using namespace std;

namespace itertools {

    template<typename T>
        struct Cycle {
            Cycle(const T& val, const int numOfIterate): val(val), numOfIterate(numOfIterate){ }
            const T val;
            int numOfIterate = 0;
            
            struct iterator {
                decltype(val.begin()) It, ItEnd, ItStart;
                int numOfIterate = 0;
                
                decltype(*val.begin()) operator*() {
                    return *It;
                }
                
                iterator& operator++() {
                    ++It;
                    if (It == ItEnd && numOfIterate-2 >= 0) {
                        It = ItStart;
                        //cout << " | ";
                        numOfIterate--;
                    }
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
                    return iterator{val.begin(), val.end(), val.begin(), numOfIterate};
                }
                iterator end()  const {
                    return iterator{val.end(), val.end(), val.begin(), numOfIterate};
                }
        };
}



#endif /* Cycle_h */
