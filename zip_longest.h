//
//  zip_longest.h
//  Iterable
//
//  Created by Adam Lev-Ari on 10/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef zip_longest_h
#define zip_longest_h

#include <utility>
#include <iostream>

namespace itertools {
    template<typename T1, typename T2>
    struct zip_longest {
        const T1 first;
        const T2 second;
        zip_longest(const T1& first, const T2& second): first(first), second(second) {}
        typedef std::pair<decltype(*first.begin()), decltype(*second.begin())> PAIR;
        struct iterator {
            decltype(first.begin()) firstIterator, firstEnd;
            decltype(second.begin()) secondIterator, secondEnd;
            PAIR operator*() {
                return PAIR(*firstIterator, *secondIterator);
            }
            iterator& operator++() {
                ++firstIterator;
                ++secondIterator;
                return *this;
            }
            iterator operator++(int) {
                iterator tmp=*this;
                operator++();
                return tmp;
            }

            bool operator==(const iterator& other) {
                return firstIterator==other.firstIterator && secondIterator==other.secondIterator;
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


#endif /* zip_longest_h */
