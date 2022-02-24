#include "FileProcessor.h"
#include "Translator.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Name: FileProcessor
Use: Constructor
Parameters: None
Return type: None
*/

FileProcessor::FileProcessor() {

}

/*
Name: ~FileProcessor
Use: Destructor
Parameters: None
Return type: None
*/

FileProcessor::~FileProcessor() { }

/*
Name: processFile
Use: takes in two names of files, opens those files, writes the translation of the input file to the output file, then closes the file
Parameters: string inputFile, string outputFileing
Return type: void
*/

void FileProcessor::processFile(string inputFile, string outputFile) {

  ifstream inFile;
  string line;

  ofstream outFile;

  outFile.open(outputFile);

  inFile.open(inputFile);

  Translator trans;

  if(inFile.is_open()) {
    while(getline(inFile,line)) {
      outFile << trans.translateEnglishSentence(line);

    }
  }
  inFile.close();
  outFile.close();
}
