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
    void operator()(std::vector<T> &arr, size_t n){
        if(n<=1) return;

        size_t left = 0;
        size_t right = n;
        int count = 0;
        while(left < right){
            //one past last elt of the left sorted section
            size_t min = left;
            //one before first elt of right sorted section
            size_t max = right-1;

            for(size_t i=left+1; i<right; ++i){
                std::cerr << "i: " << i << " right: " << right << std::endl;
                if(comp(arr[i], arr[min])){
                    std::cerr << arr[i] << " < " << arr[min] << "\n";
                    min = i;
                }
                if(comp(arr[max], arr[i])){
                    std::cerr << arr[i] << " > " << arr[max] << "\n";
                    max = i;
                }
            } //finds biggest and smallest indices
            
            std::cerr << "count: " << count++ << ":\n\tmin: " << min << " - " << arr[min] << " | max: " << max << " - " << arr[max] << "\n";

            if(min != max){
                if(max != right-1) std::swap(arr[max], arr[right-1]);
                right--;
            }
            if(min != left) std::swap(arr[min], arr[left]);
            left++;
            
            for(int l=0; l<5; ++l) std::cout << arr[l] << " ";
            std::cout << "\n";

            
        }
    }
};



#endif