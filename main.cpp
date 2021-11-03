#include <iostream>
#include <chrono>
#include "TimeTester.h"
using namespace std;

//create a start and end time_point object
//get the current time, run the algo, then get the current time again
//calculate the duration between start and end and print to the terminal

void ascending(int* , int);
void descending(int* , int);
void shuffle(int*, int);

int main() {

    std::cout << std::fixed << std::showpoint;
    std::cout.precision(9);
    print_version_number();
    std::ofstream ofs("output.txt");

    int n = 30000;

    //while loop allows for five iteration to test for growth rate
    while (n <= 150000) {
        //dynamically allocated so as not to overflow stack
        int *data = new int[n];
        ascending(data, n);

        cout << "Ascending order test results:" << endl;
        cout << "-----------------------------" << endl;
        ofs << "Ascending order test results for " << n << " elements:" << endl;
        ofs << "------------------------------------------------------" << endl;
        TimeTester::Run(data, n, ofs);
        cout << endl;
        ofs << endl;

        descending(data, n);

        cout << "Descending order test results:" << endl;
        cout << "------------------------------" << endl;
        ofs << "Descending order test results for " << n << " elements:" << endl;
        ofs << "-------------------------------------------------------" << endl;
        TimeTester::Run(data, n, ofs);
        cout << endl;
        ofs << endl;

        shuffle(data, n);

        cout << "Shuffled order test results:" << endl;
        cout << "----------------------------" << endl;
        ofs << "Shuffled order test results for " << n << " elements:" << endl;
        ofs << "-----------------------------------------------------" << endl;
        TimeTester::Run(data, n, ofs);
        cout << endl;
        ofs << endl;

        n += 30000;
    }


    return 0;
}

//instantiate array in ascending order
void ascending(int* data, int n) {
    for (int i = 0; i < n; i++) {
        data[i] = i;
    }
}

//instantiate array in descending order
void descending(int* data, int n) {
    for (int i = 0; i < n; i++) {
        data[i] = n - i - 1;
    }
}

//instantiate array with "out of order" elements
void shuffle(int* data, int n) {
    //implement Fisher-Yates shuffle so as to
    // randomize elements of ordered array (source geeks for geeks)
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(data[i], data[j]);
    }
}