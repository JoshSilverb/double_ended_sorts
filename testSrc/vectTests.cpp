#include "double_selection_sort.h"
#include "double_bubble_sort.h"
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
    double_bubble_sort<int> dbs;
    size_t size = 10;

    vector<int> dataVec1;
    vector<int> dataVec2;
    cout << "dataVec: ";
    for(int i=0; i<size; ++i){
        int pushVal = rand() % 100;
        dataVec1.push_back(pushVal);
        cout << pushVal << " ";
    }
    dataVec2 = dataVec1;
    cout << endl;

    dss(dataVec1);
    dbs(dataVec2);

    cout << "Vectors:\n";
    for(int i=0; i<size; ++i){
        cout << dataVec1[i] << " ";
    }
    cout << endl;
    for(int i=0; i<size; ++i){
        cout << dataVec2[i] << " ";
    }
    for(int i=0; i<size; ++i){
        if(i>0) assert((dataVec1[i] >= dataVec1[i-1]) && (dataVec2[i] >= dataVec2[i-1]));
    }


    cout << endl;
    cout << "Completed basic_int()" << endl;

}


void basic_custom_object(){
    cout << "Running basic_custom_object()" << endl;

    DuckLess dcomp;

    double_selection_sort<Duck, DuckLess> dss;
    double_bubble_sort<Duck, DuckLess> dbs;

    size_t size = 10;

    vector<Duck> ducks1;
    vector<Duck> ducks2;

    for(int i=0; i<size; ++i){
        ducks1.emplace_back(rand() % 100, (char)((int)'a' + i));
    }
    ducks2 = ducks1;

    dss(ducks1);
    dbs(ducks2);

    cout << "Vector: ";
    for(int i=0; i<size; ++i){
        cout << ducks1[i].age << " " << ducks1[i].letter << " ";
        if(i>0) assert(dcomp(ducks1[i-1], ducks1[i]) 
                  || (!dcomp(ducks1[i-1], ducks1[i]) && !dcomp(ducks1[i], ducks1[i-1])));
    }
    for(int i=0; i<size; ++i){
        cout << ducks2[i].age << " " << ducks2[i].letter << " ";
        if(i>0) assert(dcomp(ducks2[i-1], ducks2[i]) 
                  || (!dcomp(ducks2[i-1], ducks2[i]) && !dcomp(ducks2[i], ducks2[i-1])));
    }
    cout << endl;
    cout << "Completed basic_custom_object() successfully" << endl;

}


void extra_test(){
    cout << "Running extra_test()" << endl;

    //vector<int> vec = {4, 92, 21, 77, 69, 52, 22, 87, 5, 93};
    vector<int> vec1 = {66, 60, 55, 9, 65, 57, 49, 54, 89, 80};
    double_selection_sort<int> dss;
    double_bubble_sort<int> dbs;
    
    vector<int> vec2 = vec1;

    dss(vec1);
    dbs(vec2);

    cout << "Vector: ";
    for(int i=0; i<10; ++i){
        cout << vec1[i] << " ";
        if(i>0) assert(vec1[i] >= vec1[i-1]);
        cout << flush;
    }
    for(int i=0; i<10; ++i){
        cout << vec2[i] << " ";
        if(i>0) assert(vec2[i] >= vec2[i-1]);
        cout << flush;
    }
    cout << endl;
    cout << "Completed extra_test() successfully" << endl;

}


void small_vector(){
    cout << "Running small_vector()" << endl;
    double_selection_sort<int> dss;
    double_bubble_sort<int> dbs;
    unsigned int sizes[3] = {3, 2, 1};

    vector<int> dataVec1;
    vector<int> dataVec2;

    for(unsigned int size : sizes){
        cout << "Starting test for size = " << size << endl;
        cout << "dataVec: ";
        for(int i=0; i<size; ++i){
            int pushVal = rand() % 100;
            dataVec1.push_back(pushVal);
            cout << pushVal << " ";
        }
        cout << endl;
        dataVec2 = dataVec1;

        dss(dataVec1);
        dbs(dataVec2);

        cout << "Vector:\n";
        for(int i=0; i<size; ++i){
            cout << dataVec1[i] << " ";
        }
        cout << endl;
        for(int i=0; i<size; ++i){
            cout << dataVec2[i] << " ";
        }
        cout << endl;

        for(int i=0; i<size; ++i){
            if(i>0) assert(dataVec1[i] >= dataVec1[i-1] && dataVec2[i] >= dataVec2[i-1]);
        }
        cout << "Passed size = " << size << endl;
        dataVec1.clear();
        dataVec2.clear();
    }
    cout << "Completed small_vector()" << endl;
}

void big_vector(){
    cout << "Running big_vector()" << endl;
    double_selection_sort<int> dss;
    double_bubble_sort<int> dbs;
    unsigned int sizes[4] = {100, 256, 1028, 65536};

    vector<int> dataVec1;
    vector<int> dataVec2;
    for(unsigned int size : sizes){
        cout << "Starting test for size = " << size << endl;
        for(int i=0; i<size; ++i){
            dataVec1.push_back(rand() % 100);
        }
        dataVec2 = dataVec1;

        dss(dataVec1);
        cout << "dss finished\n";
        for(int i=0; i<size; ++i){
            if(i>0) assert(dataVec1[i] >= dataVec1[i-1] && dataVec2[i] >= dataVec2[i-1]);
        }
        dbs(dataVec2);
        cout << "dbs finished\n";
        for(int i=0; i<size; ++i){
            if(i>0) assert(dataVec1[i] >= dataVec1[i-1] && dataVec2[i] >= dataVec2[i-1]);
        }
        
        cout << "Passed size = " << size << endl;
        dataVec1.clear();
        dataVec2.clear();
    }
    cout << "Completed big_vector()" << endl;
}