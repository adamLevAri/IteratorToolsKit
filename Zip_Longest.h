//
//  Zip_Longest.h
//  Iterable
//
//  Created by Adam Lev-Ari on 10/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef Zip_Longest_h
#define Zip_Longest_h

#include <utility>
#include <iostream>

using namespace std;

namespace itertools {
    template<typename T1, typename T2>
    struct Zip_Longest {
        const T1 first;
        const T2 second;
        Zip_Longest(const T1& first, const T2& second): first(first), second(second) {}
        typedef pair<decltype(*first.begin()), decltype(*second.begin())> PAIR;
        
        struct iterator {
            decltype(first.begin()) firstIt, firstItEnd;
            decltype(second.begin()) secondIt, secondItEnd;
            PAIR operator*() {
                return PAIR(*firstIt, *secondIt);
            }
            iterator& operator++() {
                ++firstIt;
                ++secondIt;
                return *this;
            }
            iterator operator++(int) {
                iterator tmp=*this;
                operator++();
                return tmp;
            }

            bool operator==(const iterator& other) {
                return firstIt==other.firstIt && secondIt==other.secondIt;
            }
            bool operator!=(const iterator& other) {
                return !(operator==(other));
            }
        };

        iterator begin() const {
            return iterator{first.begin(), first.end(), second.begin(), second.end()};
        }
        iterator end()  const {
            return iterator{first.end(), first.end(), second.end(), second.end()};
        }
    };

}


#endif /* Zip_Longest_h */
