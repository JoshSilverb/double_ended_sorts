#include "double_selection_sort.h"
#include <vector>
#include <random>
#include <iostream>
#include <string>
#include <cassert>
#include <forward_list>
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


void basic_custom_object_vector();
void basic_int_vector();
void basic_int_fl();
void basic_custom_object_fl();
void basic_int_array();
void basic_custom_object_array();


int main(int argc, char** argv){
    srand (time(NULL));
    
    basic_int_vector();
    basic_custom_object_vector();
    basic_int_fl();
    basic_custom_object_fl();
    basic_int_array();
    basic_custom_object_array();
    

}

void basic_int_vector(){
    cout << "Running basic_int_vector()" << endl;
    double_selection_sort<int> dss;
    size_t size = 10;

    vector<int> dataVec;
    cout << "dataVec: ";
    for(int i=0; i<size; ++i){
        int pushVal = rand() % 100;
        dataVec.push_back(pushVal);
        cout << pushVal << " ";
    }
    cout << endl;

    dss(dataVec.begin(), dataVec.end());

    cout << "Vector: ";
    for(int i=0; i<size; ++i){
        cout << dataVec[i] << " ";
    }
    cout << flush;
    for(int i=0; i<size; ++i){
        if(i>0) assert(dataVec[i] >= dataVec[i-1]);
    }
    cout << endl;
    cout << "Completed basic_int_vector()" << endl;

}


void basic_custom_object_vector(){
    cout << "Running basic_custom_object_vector()" << endl;

    DuckLess dcomp;

    double_selection_sort<Duck, DuckLess> dss;
    size_t size = 10;

    vector<Duck> ducks;

    for(int i=0; i<size; ++i){
        ducks.emplace_back(rand() % 100, (char)((int)'a' + i));
    }

    dss(ducks.begin(), ducks.end());

    cout << "Vector: ";
    for(int i=0; i<size; ++i){
        cout << ducks[i].age << " " << ducks[i].letter << " ";
        if(i>0) assert(dcomp(ducks[i-1], ducks[i]) 
                  || (!dcomp(ducks[i-1], ducks[i]) && !dcomp(ducks[i], ducks[i-1])));
    }
    cout << endl;
    cout << "Completed basic_custom_object_vector() successfully" << endl;

}


void basic_int_fl(){
    cout << "Running basic_int_fl()" << endl;
    double_selection_sort<int, less<int>, forward_list<int>::iterator> dss;
    size_t size = 10;

    forward_list<int> dataList;
    cout << "dataVec: ";
    for(int i=0; i<size; ++i){
        int pushVal = rand() % 100;
        dataList.push_front(pushVal);
        cout << pushVal << " ";
    }
    cout << endl;

    dss(dataList.begin(), dataList.end());

    cout << "Vector: ";
    for(int i : dataList){
        cout << i << " ";
    }
    cout << flush;
    forward_list<int>::iterator one, two;
    one = dataList.begin();
    one++;
    two = dataList.begin();

    while(one != dataList.end()){
        assert(*one >= *two);
        one++; two++;
    }
    cout << endl;
    cout << "Completed basic_int_fl()" << endl;

}


void basic_custom_object_fl(){
    cout << "Running basic_custom_object_fl()" << endl;

    DuckLess dcomp;

    double_selection_sort<Duck, DuckLess, forward_list<Duck>::iterator> dss;
    size_t size = 10;

    forward_list<Duck> ducks;

    for(int i=0; i<size; ++i){
        ducks.emplace_front(rand() % 100, (char)((int)'a' + i));
    }

    dss(ducks.begin(), ducks.end());

    cout << "Forward list: ";
    for(Duck i : ducks){
        cout << i.age << " " << i.letter << " ";
    }
    cout << flush;

    forward_list<Duck>::iterator one, two;
    one = ducks.begin();
    one++;
    two = ducks.begin();
    while(one != ducks.end()){
        assert(dcomp(*two, *one)
             || (!dcomp(*one, *two) && !dcomp(*two, *one)));
        one++; two++;
    }


    cout << endl;
    cout << "Completed basic_custom_object_fl() successfully" << endl;

}



void basic_int_array(){
    cout << "Running basic_int()_array" << endl;
    double_selection_sort<int, less<int>, int*> dss;
    size_t size = 10;

    int arr[10];
    cout << "dataVec: ";
    for(int i=0; i<size; ++i){
        int pushVal = rand() % 100;
        arr[i] = pushVal;
        cout << pushVal << " ";
    }
    cout << endl;

    dss(arr, arr+size);

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
    cout << "Completed basic_int_array()" << endl;

}


void basic_custom_object_array(){
    cout << "Running basic_custom_object_array()" << endl;

    DuckLess dcomp;

    double_selection_sort<Duck, DuckLess, Duck*> dss;
    size_t size = 10;

    Duck ducks[10];

    for(int i=0; i<size; ++i){
        ducks[i] = Duck(rand() % 100, (char)((int)'a' + i));
    }

    dss(ducks, ducks+size);

    cout << "Vector: ";
    for(int i=0; i<size; ++i){
        cout << ducks[i].age << " " << ducks[i].letter << " ";
        if(i>0) assert(dcomp(ducks[i-1], ducks[i]) 
                  || (!dcomp(ducks[i-1], ducks[i]) && !dcomp(ducks[i], ducks[i-1])));
    }
    cout << endl;
    cout << "Completed basic_custom_object_array() successfully" << endl;

}

