#ifndef DOUBLE_SELECTION_SORT_H
#define DOUBLE_SELECTION_SORT_H

#include <deque>
#include <utility>
#include <vector>
#include <iostream>



// [  ][  ][left][  ][  ][  ][right][end...
//   ^---^--sorted--------------^----


template <typename T, typename func = std::less<T>, typename ForwardIt = typename std::vector<T>::iterator >
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
            
            // loop thru the unsorted array to find indices of smallest and largest elements
            for(auto i=left; i != right; ++i){
                if(comp(*i, *min)) min = i;           //if the element is smallest in unsorted array
                if(comp(*max, *i)) max = i;           //if the element is greatest in unsorted array
            }

            // checks to make sure you don't accidentally swap min away
            if(min == --right){
                min = max;
            }

            std::swap(*max, *right);
            std::swap(*min, *left++);
            
        }
    }


    void operator()(ForwardIt begin, ForwardIt end){
        if(begin == end) return;    // length = 0
        ForwardIt right = begin;
        right++;
        if(right == end) return;    // length = 1

        ForwardIt half = begin;     // right=arr[1] half=arr[0]
        while(right != end){
            right++; half++;
            if(right == end) break;
            right++;
        }                           // right=arr[len-1] half=arr[(int)len/2]
        // right = end
        // half  = halway between (rounded down: at the end half=left or half=left-1)
        

        ForwardIt left = begin;
        right = end;

        // keep looping until the two sorted sections meet
        // half is a ForwardIt to the middle element rounded down so if right misses left on odd len container it will hit half
        while(left != right && half != right){
            ForwardIt min = left;      //one past last elt of the left sorted section
            ForwardIt max = left;
            ForwardIt temp = max;
            temp++;
            while(temp != right){   //loop until max is one before first elt of right sorted section
                temp++;
                max++;
            }
            ForwardIt secondLast = max;
            
            // loop thru the unsorted array to find iterators to smallest and largest elements
            for(ForwardIt i=left; i != right; ++i){
                if(comp(*i, *min)) min = i;           //if the element is smallest in unsorted array
                if(comp(*max, *i)) max = i;           //if the element is greatest in unsorted array
            }
            
            // checks to make sure you don't accidentally swap min away
            if(min == secondLast){
                min = max;
            }
            right = secondLast;
            std::swap(*max, *right);       // used to have max != right-1 and min != left checks but they're a net computation cost
            std::swap(*min, *left++);            
        }
    }
};



#endif