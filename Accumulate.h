//
//  Accumulate.h
//  Iterable
//
//  Created by Adam Lev-Ari on 09/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef Accumulate_h
#define Accumulate_h
#include <iostream>
#include <sstream>

using namespace std;
namespace itertools {

    template<typename T>
        struct Accumulate {
            Accumulate(const T& val): val(val) { }
            const T val;
            typedef decltype(val.begin()) IT;
            
            struct iterator{
                IT It, ItNext, ItEnd;
                T Container;
                int index = 0;
                
                iterator(IT It, IT ItNext, IT ItEnd, T Container): It(It), ItNext(ItNext), ItEnd(ItEnd), Container(Container) {}
                
                decltype(*val.begin()) operator*() {
                    
                    return Container[index];
                }
                
                iterator& operator++() {
                    if (ItNext == ItEnd) {
                        It = ItEnd;
                        return *this;
                    }
                    Container[index] += *ItNext;
                    ++It;
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
