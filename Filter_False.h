//
//  Filter_false.h
//  Iterable
//
//  Created by Adam Lev-Ari on 17/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef Filter_False_h
#define Filter_False_h

using namespace std;

namespace itertools {

    template<typename value_type, typename predicate_type>
        struct Filter_False {
            value_type val;
            const predicate_type pred;
            typedef decltype(val.begin()) IT;
            IT It, ItBegin, ItEnd;
            
            Filter_False(value_type& val, const predicate_type& pred): val(val), pred(pred), It(val.begin()), ItBegin(val.begin()), ItEnd(val.end()) {
                
                size_t i = 0;
                for (auto& it : val) {
                  if (pred.operator()(it)) break;
                  i++;
                }

                if (i < val.size() - 1)
                  ItBegin = val.begin() + i;
                else
                  ItBegin = ItEnd;

                It = ItBegin;
                
            }
            
            struct iterator{
                decltype(val.begin()) It, ItEnd;
                const predicate_type pred;
                
                
                iterator(IT It, IT ItEnd,const predicate_type func): It(It), ItEnd(ItEnd), pred(func) {}
                
                decltype(*val.begin()) operator*(){
                    return *It;
                }
                
                iterator operator++() {
                    ++It;

                    while (It != ItEnd && !pred(*It))
                      ++It;

                    return iterator(It, ItEnd, pred);
                }
                
                bool operator==(const iterator& other) {
                    return It==other.It;
                }
                bool operator!=(const iterator& other) {
                    return !(operator==(other));
                }
                };
                
                
                iterator begin() const {
                    return iterator{ItBegin, ItEnd, pred };
                }
                iterator end()  const {
                    return iterator{ItEnd, ItEnd, pred };
                }
                
        };
}
#endif /* Filter_False_h */
