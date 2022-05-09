#include "Simulation.h"
#include <iostream>

Simulation::Simulation()
{

}

Simulation::~Simulation()
{

}

void Simulation::Simulate(string fileName)
{

    FileHandler* fh = new FileHandler();
    fh->OpenInFile(fileName);

    string numItemsToSort = fh->ReadLine();
    int numItems = stoi(numItemsToSort);

    double* SS_array;

    double* MS_array;

    int numValues = fh->NumLines();

    SS_array = new double[numValues];
    MS_array = new double[numValues];

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
        //cout << SS_array[i] << endl;
    }
    PerformSS(SS_array, numValues);
    PerformMS(MS_array, numValues);


    delete[] SS_array;
    delete[] MS_array;

    f->CloseInFile();
}


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