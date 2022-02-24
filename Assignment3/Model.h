#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

class Model {
public:
  Model();
  ~Model();
  string translateSingleCharacter(char englishInput);
  string translateDoubleCharacter(char englishInputPair);
private:

  bool isVowel(char englishLetter);
};
