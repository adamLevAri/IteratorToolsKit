//
//  Accumulate.h
//  Iterable
//
//  Created by Adam Lev-Ari on 09/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef Accumulate_h
#define Accumulate_h
#include <stdio.h>
#include <sstream>

using namespace std;
namespace itertools {

    template<typename T>
        struct Accumulate {
            Accumulate(const T& val): val(val) { }
            const T val;
            
            
            struct iterator{
                decltype(val.begin()) It, ItNext, ItEnd;
                T Container;
                //decltype(Container.begin()) ItContainer;
                int index = 0;
                
                decltype(*val.begin()) operator*() {
                    
                    return Container[index];
                }
                
                iterator& operator++() {
                    Container[index] += *ItNext;
                    ++It;
                    
                    if (ItNext == ItEnd) {
                        It = ItEnd;
                    }
                    ++ItNext;
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
                    return iterator{val.begin(), ++val.begin() , val.end(), val };
                }
                iterator end()  const {
                    return iterator{val.end(), val.end(), val.end(), val };
                }
        };
}

#endif /* Accumulate_h */
