#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Translator {
public:
  Translator();
  ~Translator();
  string translateEnglishWord(string englishInput);
  string translateEnglishSentence(string englishInputSentence);
};
