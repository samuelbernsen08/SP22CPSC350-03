#include "Model.h"
#include <cctype>

using namespace std;

/*
Name: isVowel()
Use: isVowel() takes in an english letter and returns
true if the letter is a vowel, and false if the
letter is not a vowel
Parameters: char englishLetter
Return type: boolean
*/

bool Model::isVowel(char englishLetter) {
  /*
  char tempChar = tolower(englishLetter);
  bool vowelState;
  if (tempChar == 'a') {
      vowelState = true;
  }
  else if (tempChar == 'e') {
      vowelState = true;
  }
  else if (tempChar == 'i') {
      vowelState = true;
  }
  else if (tempChar == 'o') {
      vowelState = true;
  }
  else if (tempChar == 'u') {
      vowelState = true;
  }
  else {
    vowelState = false;
  }
  */

  bool vowelState;
  switch(englishLetter) {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
      vowelState = true;
      break;

    default:
      vowelState = false;
      break;

  }

  return vowelState;
}


/*
Name: Model
Use: Constructor
Parameters: None
Return type: None
*/

Model::Model() {
  // inputChar = '';
  // tutaneseStringFromChar = "";
  // inputPair = '';
  // tutaneseStringFromPair = "";
}

/*
Name: ~Model
Use: Destructor
Parameters: None
Return type: None
*/

Model::~Model() {  }


/*
Name: translateSingleCharacter
Use: Takes in a single character in english and translates it to tutanese
Parameters: char englishInput
Return type: string
*/

string Model::translateSingleCharacter(char englishInput) {
  string tutaneseStringFromChar;
  switch (englishInput) {
    case 'B':
      tutaneseStringFromChar = "Bub";
      break;
    case 'C':
      tutaneseStringFromChar = "Cash";
      break;
    case 'D':
      tutaneseStringFromChar = "Dud";
      break;
    case 'F':
      tutaneseStringFromChar = "Fuf";
      break;
    case 'G':
      tutaneseStringFromChar = "Gug";
      break;
    case 'H':
      tutaneseStringFromChar = "Hash";
      break;
    case 'J':
      tutaneseStringFromChar = "Jay";
      break;
    case 'K':
      tutaneseStringFromChar = "Kuck";
      break;
    case 'L':
      tutaneseStringFromChar = "Lul";
      break;
    case 'M':
      tutaneseStringFromChar = "Mum";
      break;
    case 'N':
      tutaneseStringFromChar = "Nun";
      break;
    case 'P':
      tutaneseStringFromChar = "Pub";
      break;
    case 'Q':
      tutaneseStringFromChar = "Quack";
      break;
    case 'R':
      tutaneseStringFromChar = "Rug";
      break;
    case 'S':
      tutaneseStringFromChar = "Sus";
      break;
    case 'T':
      tutaneseStringFromChar = "Tut";
      break;
    case 'V':
      tutaneseStringFromChar = "Vuv";
      break;
    case 'W':
      tutaneseStringFromChar = "Wack";
      break;
    case 'X':
      tutaneseStringFromChar = "Ex";
      break;
    case 'Y':
      tutaneseStringFromChar = "Yub";
      break;
    case 'Z':
      tutaneseStringFromChar = "Zub";
      break;
      // dealing with lowercase option
    case 'b':
      tutaneseStringFromChar = "bub";
      break;
    case 'c':
      tutaneseStringFromChar = "cash";
      break;
    case 'd':
      tutaneseStringFromChar = "dud";
      break;
    case 'f':
      tutaneseStringFromChar = "fuf";
      break;
    case 'g':
      tutaneseStringFromChar = "gug";
      break;
    case 'h':
      tutaneseStringFromChar = "hash";
      break;
    case 'j':
      tutaneseStringFromChar = "jay";
      break;
    case 'k':
      tutaneseStringFromChar = "kuck";
      break;
    case 'l':
      tutaneseStringFromChar = "lul";
      break;
    case 'm':
      tutaneseStringFromChar = "mum";
      break;
    case 'n':
      tutaneseStringFromChar = "nun";
      break;
    case 'p':
      tutaneseStringFromChar = "pub";
      break;
    case 'q':
      tutaneseStringFromChar = "quack";
      break;
    case 'r':
      tutaneseStringFromChar = "rug";
      break;
    case 's':
      tutaneseStringFromChar = "sus";
      break;
    case 't':
      tutaneseStringFromChar = "tut";
      break;
    case 'v':
      tutaneseStringFromChar = "vuv";
      break;
    case 'w':
      tutaneseStringFromChar = "wack";
      break;
    case 'x':
      tutaneseStringFromChar = "ex";
      break;
    case 'y':
      tutaneseStringFromChar = "yub";
      break;
    case 'z':
      tutaneseStringFromChar = "zub";
      break;
    default:
      tutaneseStringFromChar = englishInput;
      break;
      }
  return tutaneseStringFromChar;
}

/*
Name: translateDoubleCharacter
Use: translates a single english character that is a repeated letter and translates it to tutanese
Parameters: char englishInputPair
Return type: string
*/

string Model::translateDoubleCharacter(char englishInputPair) {
  string tutaneseStringFromPair;
  // consonant case:

  if (!(isVowel(englishInputPair))) {
    if (islower(englishInputPair)) {
      tutaneseStringFromPair = "squa" + translateSingleCharacter(englishInputPair);
    }
    if (isupper(englishInputPair)) {
      tutaneseStringFromPair = "Squa" + translateSingleCharacter(englishInputPair);
      }
    }
    // vowel case:

  else {
    if (islower(englishInputPair)) {
      tutaneseStringFromPair = "squat";
      tutaneseStringFromPair.push_back(englishInputPair);

    }
    if (isupper(englishInputPair)) {
      tutaneseStringFromPair = "Squat";
      tutaneseStringFromPair.push_back(englishInputPair);
        }
  }
  return tutaneseStringFromPair;
}
