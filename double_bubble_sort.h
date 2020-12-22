#ifndef DOUBLE_BUBBLE_SORT_H
#define DOUBLE_BUBBLE_SORT_H

#include <deque>
#include <utility>
#include <vector>
#include <iostream>



// [  ][  ][left][  ][  ][  ][right][end...
//   ^---^--sorted--------------^----

template <typename T, typename func = std::less<T>, typename BidirIt = typename std::vector<T>::iterator>
class double_bubble_sort{
    func comp;
public:
    void operator()(std::vector<T> &arr){
        func comp;
        bool sorted = false;
        while(!sorted){
            sorted = true;
            for(int j=1; j<arr.size(); ++j){
                if(comp(arr[j], arr[j-1])){
                    std::swap(arr[j], arr[j-1]);
                    sorted = false;
                }
                int k=arr.size()-j;
                if(comp(arr[k], arr[k-1])){
                    std::swap(arr[k], arr[k-1]);
                    sorted = false;
                }
            }
        }
    }

    void operator()(T* arr, size_t n){
        func comp;
        bool sorted = false;
        while(!sorted){
            sorted = true;
            for(int j=1; j<n; ++j){
                if(comp(arr[j], arr[j-1])){
                    std::swap(arr[j], arr[j-1]);
                    sorted = false;
                }
                int k=n-j;
                if(comp(arr[k], arr[k-1])){
                    std::swap(arr[k], arr[k-1]);
                    sorted = false;
                }
            }
        }
    }


    void operator()(BidirIt begin, BidirIt end){
        func comp;
        bool sorted = false;
        
        
        while(!sorted){
            sorted = true;
            BidirIt l1 = begin;
            l1++;
            BidirIt l2 = begin;
            BidirIt r2 = end;
            r2--;
            r2--;
            BidirIt r1 = end;
            r1--;
            int c = 1;
            while(l1 != end){
                if(comp(*l1, *l2)){
                    std::swap(*l1, *l2);
                    sorted = false;
                }

                if(comp(*r1, *r2)){
                    std::swap(*r1, *r2);
                    sorted = false;
                }
                l1++; l2++; r1--; r2--;
                //std::cout << c++ << " ";
            }
            // std::cout << std::endl;
            // for(auto k=begin; k!=end; ++k) std::cout << *k << " ";
            // std::cout << std::endl; 
        }
    }
};

#endif