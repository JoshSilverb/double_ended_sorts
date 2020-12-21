#ifndef DOUBLE_SELECTION_SORT_H
#define DOUBLE_SELECTION_SORT_H

#include <deque>
#include <utility>
#include <vector>
#include <iostream>

template <typename T, typename func = std::less<T> >
class double_selection_sort{

    func comp;

// [  ][  ][left][  ][  ][  ][right][end...
//   ^---^--sorted--------------^----

public:
    void operator()(std::vector<T> &arr){
        if(arr.size() <= 1) return;

        typename std::vector<T>::iterator left = arr.begin();
        typename std::vector<T>::iterator right = arr.end();
        int count = 0;
        // keep looping until the two sorted sections meet
        while(left < right){
            typename std::vector<T>::iterator min = left;      //one past last elt of the left sorted section
            typename std::vector<T>::iterator max = right-1;   //one before first elt of right sorted section
            
            //std::cerr << min - arr.begin() << " @ " << max - left << "\n";

            // loop thru the unsorted array to find indices of smallest and largest elements
            for(auto i=left; i != right; ++i){
                //std::cerr << "i: " << i-arr.begin() << " *i: " << *i << "\n";
                if(comp(*i, *min)){           //if the element is smallest in unsorted array
                    //std::cerr << *i << " < " << *min << "\n";
                    min = i;
                }
                if(comp(*max, *i)){           //if the element is greatest in unsorted array
                    //std::cerr << *i << " > " << *max << "\n";
                    max = i;
                }
            } //finds biggest and smallest indices
            
            //std::cerr << "count: " << count++ << ":\n\tmin: " << *min << " max: " << *max << "\n";

            // checks to make sure you don't accidentally swap min away
            if(min == --right){
                min = max;
            }
            std::iter_swap(max, right);       // used to have max != right-1 and min != left checks but they're a net computation cost
            std::iter_swap(min, left++);
            
            //for(auto l : arr) std::cout << l << " ";
            //std::cout << "\n";

            
        }
    }


    void operator()(T* arr, size_t n){
        if(n <= 1) return;

        T* left = arr;
        T* right = arr + n;
        int count = 0;
        // keep looping until the two sorted sections meet
        while(left < right){
            T* min = left;      //one past last elt of the left sorted section
            T* max = right-1;   //one before first elt of right sorted section
            
            std::cerr << min - left << " @ " << max - left << "\n";

            // loop thru the unsorted array to find indices of smallest and largest elements
            for(auto i=left; i != right; ++i){
                std::cerr << "i: " << i-arr << " *i: " << *i << "\n";
                if(comp(*i, *min)){           //if the element is smallest in unsorted array
                    std::cerr << *i << " < " << *min << "\n";
                    min = i;
                }
                if(comp(*max, *i)){           //if the element is greatest in unsorted array
                    std::cerr << *i << " > " << *max << "\n";
                    max = i;
                }
            } //finds biggest and smallest indices
            
            std::cerr << "count: " << count++ << ":\n\tmin: " << *min << " max: " << *max << "\n";

            if(right != max) std::swap(*max, --(*right));
            if(min != left) std::swap(*min, *left++);
            
            for(T* i=arr; i<arr+n; ++i) std::cout << *i << " ";
            std::cout << "\n";

            
        }
    }
};



#endif