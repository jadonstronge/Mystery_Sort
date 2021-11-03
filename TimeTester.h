//
// Created by jadon stronge on 10/1/2021.
//

#ifndef PA03_TEMPLATE_TIMETESTER_H
#define PA03_TEMPLATE_TIMETESTER_H
#include "include/sorting_library.h"
#include <fstream>

class TimeTester {

public:

    static void Run(const int data[], int& n, std::ofstream& ofs) {
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

        int* temp = new int[n];
        // deep copy of the array before each mystery call so the next
        // mystery function doesn't work on an already ordered array
        for (int i = 0; i < n; i++) {
            temp[i] = data[i];
        }
        start = std::chrono::high_resolution_clock::now();
        mystery01(temp, n);
        end = std::chrono::high_resolution_clock::now();
        get_time(start, end, ofs);

        for (int i = 0; i < n; i++) {
            temp[i] = data[i];
        }
        start = std::chrono::high_resolution_clock::now();
        mystery02(temp, n);
        end = std::chrono::high_resolution_clock::now();
        get_time(start, end, ofs);

        for (int i = 0; i < n; i++) {
            temp[i] = data[i];
        }
        start = std::chrono::high_resolution_clock::now();
        mystery03(temp, n);
        end = std::chrono::high_resolution_clock::now();
        get_time(start, end, ofs);

        for (int i = 0; i < n; i++) {
            temp[i] = data[i];
        }
        start = std::chrono::high_resolution_clock::now();
        mystery04(temp, n);
        end = std::chrono::high_resolution_clock::now();
        get_time(start, end, ofs);

        for (int i = 0; i < n; i++) {
            temp[i] = data[i];
        }
        start = std::chrono::high_resolution_clock::now();
        mystery05(temp, n);
        end = std::chrono::high_resolution_clock::now();
        get_time(start, end, ofs);
    }

    static void get_time(std::chrono::time_point<std::chrono::high_resolution_clock> start,
                         std::chrono::time_point<std::chrono::high_resolution_clock> end, std::ofstream& ofs) {

        std::chrono::duration<double> time_in_seconds = end - start;
        std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;
        ofs << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;
    }

};

#endif //PA03_TEMPLATE_TIMETESTER_H
