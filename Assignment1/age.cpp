/*
Samuel Bernsen
CPSC-350-03

Ask the user to enter ages of 3 people. Print the oldest and the
youngest ages.

*/

#include <iostream>

using namespace std;

int main() {
    int people_ages[3];

    cout << "You will be entering the ages of three different people..." << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "Age of person: ";
        cin >> people_ages[i];
    }
    cout << endl;

    // I did this the long way using separate conditionals because I didn't think of a simpler, cleaner way to do it.



        if ((people_ages[0] < people_ages[1]) && (people_ages[0] < people_ages[2])) {
            cout << "Smallest value: " << people_ages[0] << endl;
        }
        else if ((people_ages[1] < people_ages[0]) && (people_ages[1] < people_ages[2])) {
            cout << "Smallest value: " << people_ages[1] << endl;
        }
        else if ((people_ages[2] < people_ages[0]) && (people_ages[2] < people_ages[1])) {
            cout << "Smallest value: " << people_ages[2] << endl;
        }
        cout << endl;

        if ((people_ages[0] > people_ages[1]) && (people_ages[0] > people_ages[2])) {
            cout << "Largest value: " << people_ages[0] << endl;
        }

        else if ((people_ages[1] > people_ages[0]) && (people_ages[1] > people_ages[2])) {
            cout << "Largest value: " << people_ages[1] << endl;
        }
        else if ((people_ages[2] > people_ages[0]) && (people_ages[2] > people_ages[1])) {
            cout << "Largest value: " << people_ages[2] << endl;
        }
        cout << endl;

        return 0;
    }
