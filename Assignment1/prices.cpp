/*
Samuel Bernsen
CPSC-350-03

file: prices.cpp
"Write a program to ask the user for prices of some items.
Prompt the user to enter a price until they enter a negative number. Finally, print
the total cost by summing all prices the user had entered"

*/

#include <iostream>

using namespace std;

int main() {
    double total_price = 0.0;
    double user_price;
    do { // using a do-while loop to make sure that the loop is entered
        cout << "Enter the price of this item in dollars (enter negative number to stop): $";
        cin >> user_price;
        if (user_price < 0) { // this condition makes sure the negative value doesn't get added at the end
            break;
        }
        total_price += user_price;

    } while (user_price >= 0);

    cout << "Total price: $" << total_price << endl;
    return 0;
}
