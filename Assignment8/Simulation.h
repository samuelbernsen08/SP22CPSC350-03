
#ifndef SIMULATION_H
#define SIMULATION_H

#include "FileHandler.h"
#include <iostream>
#include <ctime>
#include <chrono>

class Simulation
{
    public:
        Simulation();
        ~Simulation();

        void Simulate(string fileName);


    private:
        void PerformSS(double* array, int numVals);
        void PerformMS(double* array, int numVals);
        void SelectionSort(double* array, int numbersSize);
        void MergeSort(double* numbers, int i, int k);
        void Merge(double* numbers, int i, int j, int k);
        // choose a type of sorting algorithm
        //int SomethingSort();

};

#endif