#include "AStack.h"
#include "FileHandler.h"

using namespace std;


bool AnotherFile()
{

    bool isValid = false;
    do
    {
        
        short userChoice;
        cout << "Would you like to analyze another file?" << endl;
        cout << "Type '0' for no and '1' for yes" << endl;
        cin >> userChoice;

        
        if (userChoice == 1)
        {
            return true;
        }
        else if (userChoice == 0)
        {
            return false;
        }
        else
        {
            cout << "Inavlid option, try again..." << endl;
        }
    } while (!isValid);
}



int main()
{
    bool missingDelimiter;
    FileHandler* fh;
    fh = new FileHandler();

    do
    {

    AStack<char> myArrayStack(5);

    string s = "";
    cout << "Provide the name of the file that you would like to analyze: ";
    cin >> s;
    // cout << "skipping getline() ?" << endl;
    fh->OpenInFile(s);

    string entireFile = fh->ReadFile();

  
    fh->CloseInFile();


    for (char c: entireFile) // iterates through the whole file, which has been converted to a string already
    {
        if ((c == '(') || (c == '{') || (c == '['))
        {
            myArrayStack.push(c);
        }
        else if (c == ')')
        {
            char topVal = myArrayStack.topValue();
            if (topVal == '(')
            {
                myArrayStack.pop();
                continue;
            }
            missingDelimiter = true;
            cout << "Mismatched delimiter: (" << endl;
        }
        else if ((c == '}'))
        {
            char topVal = myArrayStack.topValue();
            if (topVal == '{')
            {
                myArrayStack.pop();
                continue;
            }
            missingDelimiter = true;
            cout << "Mismatched delimiter: {" << endl;
        }
        else if ((c == ']'))
        {
            char topVal = myArrayStack.topValue();
            if (topVal == '[')
            {
                myArrayStack.pop();
                continue;
            }
            missingDelimiter = true;
            cout << "Mismatched delimiter: [" << endl;
        }
    }
    
    if (!missingDelimiter)
    {
        if (myArrayStack.length() == 0)
        {
            cout << "All good" << endl;
            missingDelimiter = false;
        }
    }
    cout << endl;
    /*
    else
    {
        cout << "Missing delimiter for: " << endl;
        cout << myArrayStack.topValue() << endl;
    }
    */

    } while(AnotherFile());

    return 0;
}
