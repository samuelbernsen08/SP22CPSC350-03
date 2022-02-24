#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileProcessor {
public:
  FileProcessor();
  ~FileProcessor();
  void processFile(string inputFile, string outputFile);
};
