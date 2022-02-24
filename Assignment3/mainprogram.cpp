#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{

  FileProcessor f;

  string userInputFile;
  string userOutputFile;

  cout << "Name of input file: ";
  cin >> userInputFile;
  cout << "Name of output file: ";
  cin >> userOutputFile;

  f.processFile(userInputFile, userOutputFile);


	return 0;
}
