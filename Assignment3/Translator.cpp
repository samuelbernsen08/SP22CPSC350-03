#include "Translator.h"
#include "Model.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
Name: Translator
Use: Constructor
Parameters: None
Return type: None
*/

Translator::Translator() {
//  tutaneseWordFromEnglish = "";
//  tutaneseSentenceFromEnglish = "";
}

/*
Name: ~Translator
Use: Destructor
Parameters: None
Return type: None
*/


Translator::~Translator() {

}

/*
Name: translateEnglishWord
Use: takes in an english word and translates it to tutanese
Parameters: string englishInput
Return type: string
*/

string Translator::translateEnglishWord(string englishInput) {
  string tutaneseWordFromEnglish;
  Model model;

  for (int i = 0; i < englishInput.size(); ++i) {
    if (tolower(englishInput[i]) == tolower(englishInput[i+1])) {
      tutaneseWordFromEnglish += model.translateDoubleCharacter(englishInput[i]);
      ++i;
    }
    else {
      tutaneseWordFromEnglish += model.translateSingleCharacter(englishInput[i]);
    }
}
  return tutaneseWordFromEnglish;
}

/*
Name: translateEnglishSentence
Use: takes in a sentence in english and translates it to tutanese
Parameters: string englishInputSentence
Return type: string
*/

string Translator::translateEnglishSentence(string englishInputSentence) {
  string tutaneseSentenceFromEnglish;

  string Word = "";

  Model m;

  for (char ch: englishInputSentence)
  {
    if (!(isalpha(ch))) {
      tutaneseSentenceFromEnglish += translateEnglishWord(Word) + ch;
      Word = "";
    }
    else {
      Word += ch;
    }
  }
  tutaneseSentenceFromEnglish += translateEnglishWord(Word);
	return tutaneseSentenceFromEnglish;
}
