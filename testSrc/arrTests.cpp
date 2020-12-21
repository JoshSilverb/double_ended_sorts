#include "double_selection_sort.h"
#include <vector>
#include <random>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;


struct Duck{
    int age;
    char letter;
    Duck(int a, char c) : age(a), letter(c) {}
    Duck() : age(0), letter('z') {}
};
struct DuckLess{
    bool operator()(Duck &lhs, Duck &rhs){
        return lhs.age < rhs.age;
    }
};


void basic_custom_object();
void basic_int();
void extra_test();
void small_vector();
void big_vector();

int main(int argc, char** argv){
    srand (time(NULL));
    
    basic_int();
    basic_custom_object();
    extra_test();
    small_vector();
    if(argc == 2 && *argv[1] == 'y') big_vector();

}

void basic_int(){
    cout << "Running basic_int()" << endl;
    double_selection_sort<int> dss;
    size_t size = 10;

    int arr[10];
    cout << "dataVec: ";
    for(int i=0; i<size; ++i){
        int pushVal = rand() % 100;
        arr[i] = pushVal;
        cout << pushVal << " ";
    }
    cout << endl;

    dss(arr, size);

    cout << "Vector: ";
    for(int i=0; i<size; ++i){
        cout << arr[i] << " " << flush;
        //cout << flush;
    }
    for(int i=0; i<size; ++i){
        if(i>0) assert(arr[i] >= arr[i-1]);
        //cout << flush;
    }
    cout << endl;
    cout << "Completed basic_int()" << endl;

}


void basic_custom_object(){
    cout << "Running basic_custom_object()" << endl;

    DuckLess dcomp;

    double_selection_sort<Duck, DuckLess> dss;
    size_t size = 10;

    Duck ducks[10];

    for(int i=0; i<size; ++i){
        ducks[i] = Duck(rand() % 100, (char)((int)'a' + i));
    }

    dss(ducks, size);

    cout << "Vector: ";
    for(int i=0; i<size; ++i){
        cout << ducks[i].age << " " << ducks[i].letter << " ";
        if(i>0) assert(dcomp(ducks[i-1], ducks[i]) 
                  || (!dcomp(ducks[i-1], ducks[i]) && !dcomp(ducks[i], ducks[i-1])));
    }
    cout << endl;
    cout << "Completed basic_custom_object() successfully" << endl;

}


void extra_test(){
    cout << "Running extra_test()" << endl;

    int arr[10] = {66, 60, 55, 9, 65, 57, 49, 54, 89, 80};
    double_selection_sort<int> dss;

    dss(arr, 10);

    cout << "Vector: ";
    for(int i=0; i<10; ++i){
        cout << arr[i] << " ";
        if(i>0) assert(arr[i] >= arr[i-1]);
        cout << flush;
    }
    cout << endl;
    cout << "Completed extra_test() successfully" << endl;

}


void small_vector(){
    cout << "Running small_vector()" << endl;
    double_selection_sort<int> dss;
    unsigned int sizes[3] = {3, 2, 1};

    for(int i=0; i<3; ++i){
        int size = sizes[i];
        cout << "Starting test for size = " << size << endl;

        int *arr = new int [size];

        cout << "arr: ";
        for(int j=0; j<size; ++j){
            int pushVal = rand() % 100;
            arr[j] = pushVal;
            cout << pushVal << " ";
        }
        cout << endl;

        dss(arr, size);

        cout << "Array: ";
        for(int k=0; k<size; ++k){
            cout << arr[k] << " " << flush;
        }
        for(int k=0; k<size; ++k){
            if(k>0) assert(arr[k] >= arr[k-1]);
        }
        cout << "Passed size = " << size << endl;
    }
        
    
    cout << "Completed small_vector()" << endl;
}

void big_vector(){
    cout << "Running big_vector()" << endl;
    double_selection_sort<int> dss;
    unsigned int sizes[4] = {100, 256, 1028, 65536};

    for(int i=0; i<4; ++i){
        int size = sizes[i];
        cout << "Starting test for size = " << size << endl;

        int *arr = new int [size];

        //cout << "arr: ";
        for(int j=0; j<size; ++j){
            int pushVal = rand() % 100;
            arr[j] = pushVal;
            //cout << pushVal << " ";
        }
        //cout << endl;

        dss(arr, size);
/*
        cout << "Vector: ";
        for(int k=0; k<size; ++k){
            cout << arr[k] << " " << flush;
        }
        */
        for(int k=0; k<size; ++k){
            if(k>0) assert(arr[k] >= arr[k-1]);
        }
        cout << "Passed size = " << size << endl;
    }

    cout << "Completed big_vector()" << endl;
}