/**
 * @file Simulation.cpp
 * @author Samuel Bernsen
 * @brief Contains the implementations of all the method definitions from the Simulation header file.
 * Runs through a single simulation of sorting algorithms
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "Simulation.h"
#include <iostream>

/* 
 @brief constructor for simulation class
 */
Simulation::Simulation()
{

}

/* 
@brief destructor for simulation class
 */
Simulation::~Simulation()
{

}

/* 
@brief simulate one run of the program, running each of the sorting algorithms back-to-back
@param filename
 */
void Simulation::Simulate(string fileName)
{

    FileHandler* fh = new FileHandler();
    fh->OpenInFile(fileName);

    string numItemsToSort = fh->ReadLine();
    int numItems = stoi(numItemsToSort);

    double* SS_array;

    double* MS_array;

    double* ShellSort_array;

    int numValues = fh->NumLines();

    SS_array = new double[numValues];
    MS_array = new double[numValues];
    ShellSort_array = new double[numValues];

    fh->CloseInFile();

    FileHandler* f = new FileHandler();
    f->OpenInFile(fileName);

    string bigBabyMan = f->ReadLine();

    double value = 0.0;

    string line = "";

    for (int i = 0; i < numValues; i++)
    {
        line = f->ReadLine();
        value = stod(line);
        SS_array[i] = value;
        MS_array[i] = value;
        ShellSort_array[i] = value;
        //cout << SS_array[i] << endl;
    }

    int userGap = PromptForGapVal();

    for (int i = 0; i < 3; i++) // for readability purposes
    {
       cout << endl;
    }

    PerformSS(SS_array, numValues);
    PerformMS(MS_array, numValues);
    PerformShellSort(ShellSort_array, numValues, userGap);


    delete[] SS_array;
    delete[] MS_array;

    f->CloseInFile();
}

/* 
@brief Outputs the time taken for the Selection Sort algorithm
@param double* array, int numVals
 */
void Simulation::PerformSS(double* array, int numVals)
{
    cout << "Selection Sort starting..." << endl;
    auto begin = std::chrono::steady_clock::now();
    cout << "Sorting began at:  " << std::chrono::duration_cast<std::chrono::microseconds>(begin.time_since_epoch()).count() << endl;
    SelectionSort(array, numVals);
    auto end = std::chrono::steady_clock::now();
    cout << "Ended at: " << std::chrono::duration_cast<std::chrono::microseconds>(end.time_since_epoch()).count() << endl;

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    cout << "Duration: " << duration.count() << " microsecond(s)" << endl;
    cout << endl;

}

/* 
@brief Outputs the time taken for the Merge Sort algorithm
@param double* array, int numVals
 */
void Simulation::PerformMS(double* array, int numVals)
{
   cout << "Merge Sort starting..." << endl;
   auto begin = std::chrono::steady_clock::now();
   cout << "Sorting began at: " << std::chrono::duration_cast<std::chrono::microseconds>(begin.time_since_epoch()).count() << endl;
   MergeSort(array, 0, numVals - 1);
   auto end = std::chrono::steady_clock::now();
   cout << "Ended at: " << std::chrono::duration_cast<std::chrono::microseconds>(end.time_since_epoch()).count() << endl;
   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
   cout << "Duration: " << duration.count() << " microsecond(s)" << endl;
   cout << endl;
}

/*
@brief Outputs the time taken for the Shell Sort algorithm
@param double* array, int numVals, int gapVal
*/
void Simulation::PerformShellSort(double* array, int numVals, int gapVal)
{
   cout << "Shell Sort starting..." << endl;
   auto begin = std::chrono::steady_clock::now();
   cout << "Sorting began at: " << std::chrono::duration_cast<std::chrono::microseconds>(begin.time_since_epoch()).count() << endl;
   for (int i = 0; i < gapVal; i++) 
   {
   InsertionSortInterleaved(array, numVals, i, gapVal);
   }
   auto end = std::chrono::steady_clock::now();
   cout << "Ended at: " << std::chrono::duration_cast<std::chrono::microseconds>(end.time_since_epoch()).count() << endl;
   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
   cout << "Duration: " << duration.count() << " microsecond(s)" << endl;
   cout << endl;
}

/* 
@brief Performs the Selection Sort algorithm
@param double* array, int numbersSize
 */
void Simulation::SelectionSort(double *array, int numbersSize)
{
   int i = 0;
   int j = 0;
   int indexSmallest = 0;
   int temp = 0;  // Temporary variable for swap
   
   for (i = 0; i < numbersSize - 1; ++i) {
      
      // Find index of smallest remaining element
      indexSmallest = i;
      for (j = i + 1; j < numbersSize; ++j) {
         
         if (array[j] < array[indexSmallest] ) {
            indexSmallest = j;
         }
      }
      
      // Swap numbers[i] and numbers[indexSmallest]
      temp = array[i];
      array[i] = array[indexSmallest];
      array[indexSmallest] = temp;
   }
}

/* 
@brief Merges two halves of an array
@param double* array, int i, int j, int k
 */
void Simulation::Merge(double* numbers, int i, int j, int k) {
   int mergedSize = k - i + 1;               // Size of merged partition
   int mergePos = 0;                       // Position to insert merged number
   int leftPos = 0;                           // Position of elements in left partition
   int rightPos = 0;                          // Position of elements in right partition
   double* mergedNumbers = new double[mergedSize];   // Dynamically allocates temporary array
                                         // for merged numbers
   
   leftPos = i;                           // Initialize left partition position
   rightPos = j + 1;                      // Initialize right partition position
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] <= numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }
}

/* 
@brief Performs the Merge Sort algorithm
@param double* array, int i, int k
 */
void Simulation::MergeSort(double* numbers, int i, int k) {
   int j = 0;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSort(numbers, i, j);
      MergeSort(numbers, j + 1, k);
      
      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k);
   }
}

/* 
@brief Performs the Insertion Sort algorithm used in Shell Sort
@param double* array, int numVals, int startIndex, int gapVal
 */
void Simulation::InsertionSortInterleaved(double* array, int numVals, int startIndex, int gapVal)
{
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap

   for (i = startIndex + gapVal; i < numVals; i = i + gapVal) {
      j = i;
      while (j - gapVal >= startIndex && array[j] < array[j - gapVal]) {
         temp = array[j];
         array[j] = array[j - gapVal];
         array[j - gapVal] = temp;
         j = j - gapVal;
      }
   }
}


/* 
@brief Prompts the user for a gap value to be used in the shell sort algorithm
@return int
 */
int Simulation::PromptForGapVal()
{
   // need to prompt for the gap value
   int userGap = 0;
   cout << "What gap value would you like for shell sort? ";
   cin >> userGap;
   userGap = (userGap % 5) + 1; // ensures the value is small (1-6)
}