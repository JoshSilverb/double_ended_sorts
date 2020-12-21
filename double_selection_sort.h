#ifndef DOUBLE_SELECTION_SORT_H
#define DOUBLE_SELECTION_SORT_H

#include <deque>
#include <utility>
#include <vector>
#include <iostream>



// [  ][  ][left][  ][  ][  ][right][end...
//   ^---^--sorted--------------^----


template <typename T, typename func = std::less<T> >
class double_selection_sort{
    func comp;
public:
    void operator()(std::vector<T> &arr){
        if(arr.size() <= 1) return;

        typename std::vector<T>::iterator left = arr.begin();
        typename std::vector<T>::iterator right = arr.end();
        // keep looping until the two sorted sections meet
        while(left < right){
            typename std::vector<T>::iterator min = left;      //one past last elt of the left sorted section
            typename std::vector<T>::iterator max = right-1;   //one before first elt of right sorted section
            
            // loop thru the unsorted array to find iterators to smallest and largest elements
            for(auto i=left; i != right; ++i){
                if(comp(*i, *min)) min = i;           //if the element is smallest in unsorted array
                if(comp(*max, *i)) max = i;           //if the element is greatest in unsorted array
            }
            
            // checks to make sure you don't accidentally swap min away
            if(min == --right){
                min = max;
            }
            std::iter_swap(max, right);       // used to have max != right-1 and min != left checks but they're a net computation cost
            std::iter_swap(min, left++);            
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
            
            //std::cerr << min - left << " @ " << max - left << "\n";

            // loop thru the unsorted array to find indices of smallest and largest elements
            for(auto i=left; i != right; ++i){
                if(comp(*i, *min)) min = i;           //if the element is smallest in unsorted array
                if(comp(*max, *i)) max = i;           //if the element is greatest in unsorted array
            }
            
            //std::cerr << "count: " << count++ << ":\n\tmin: " << *min << " max: " << *max << "\n";


            // checks to make sure you don't accidentally swap min away
            if(min == --right){
                min = max;
            }

            std::swap(*max, *right);
            std::swap(*min, *left++);
            
        }
    }
};



#endif