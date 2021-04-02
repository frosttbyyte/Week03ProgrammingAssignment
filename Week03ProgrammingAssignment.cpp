// Week03ProgrammingAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cassert>
#include <fstream>

using namespace std;

int main()
{
    // header
    cout << setw(50) << setfill('.') << "." << endl;
    cout << "ITCS 1530 - Programming Assignment for week #3" << endl;
    cout << setw(50) << setfill('.') << "." << endl;
    cout << endl;

    // declaring variables
    string item;
    string fragile;
    float price;
    string destination;
    double shipping;
    // file variable
    ofstream file;

    // asking the user for the item
    cout << "Please enter the item name (no spaces)" << setw(12) << setfill('.') << right << ":";
    cin >> item;
    transform(item.begin(), item.end(), item.begin(), ::toupper);

    // asking the user whether item is fragile
    cout << "Is the item fragile? (y=yes/n=no)" << setw(17) << setfill('.') << right << ":";
    cin >> fragile;
    transform(fragile.begin(), fragile.end(), fragile.begin(), ::toupper);

    // exit the program if the user enters incorrect value for fragile
    if (fragile != "Y" && fragile != "N") {
        cout << endl;
        cout << "Invalid entry, exiting" << endl;
        system("pause");
        return 0;
    }

    // asking the user for order total
    cout << "Please enter your order total" << setw(21) << setfill('.') << right << ":";
    cin >> price;

    // asking the user for destination
    cout << "Please enter destination. (usa/can/aus/venus)" << setw(5) << setfill('.') << right << ":";
    cin >> destination;
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);

    // exit the program if the user enters incorrect value for destination
    if (destination != "USA" && destination != "CAN" && destination != "AUS" && destination != "VENUS") {
        cout << endl;
        cout << "Invalid entry, exiting" << endl;
        system("pause");
        return 0;
    }

    // adding a space between the inputs and final outputs
    cout << endl;

    // using if statements to determine the shipping costs
    // for prices less than $50.00
    if (price <= 50.00) {
        if (destination == "USA") {
            shipping = 6.00;
        }
        if (destination == "CAN") {
            shipping = 8.00;
        }
        if (destination == "AUS") {
            shipping = 10.00;
        }
        if (destination == "VENUS") {
            shipping = 20.00;
        }
    }
    // for prices between $50.00 and $100.00
    else if (price > 50.00 && price <= 100.00) {
        if (destination == "USA") {
            shipping = 9.00;
        }
        if (destination == "CAN") {
            shipping = 12.00;
        }
        if (destination == "AUS") {
            shipping = 14.00;
        }
        if (destination == "VENUS") {
            shipping = 28.00;
        }
    }
    // for prices between $100.00 and $150.00
    else if (price > 100.00 && price <= 150.00) {
        if (destination == "USA") {
            shipping = 12.00;
        }
        if (destination == "CAN") {
            shipping = 15.00;
        }
        if (destination == "AUS") {
            shipping = 17.00;
        }
        if (destination == "VENUS") {
            shipping = 32.00;
        }
    }
    // for prices over $150.00 (free shipping)
    else {
        shipping = 0.00;
    }

    // add 2.00 to the shipping cost if item is fragile
    if (fragile == "Y") {
        shipping = shipping + 2.00;
    }

    // calculate the order total
    float total = shipping + price;

    // final outputs
    cout << "Your item is" << setw(28) << setfill('.') << '.' << item << endl;
    cout << "Your shipping cost is" << setw(20) << setfill('.') << "$" << fixed << setprecision(2) << shipping << endl;
    cout << "You are shipping to" << setw(21) << setfill('.') << '.' << destination << endl;
    cout << "Your total shipping costs are" << setw(12) << setfill('.') << "$" << fixed << setprecision(2) << total << endl;
    cout << endl;

    // write output to a file named Order.txt
    // open the file
    file.open("Order.txt");
    // output the sormat to Order.txt
    file << "Your item is" << setw(28) << setfill('.') << '.' << item << endl;
    file << "Your shipping cost is" << setw(20) << setfill('.') << "$" << fixed << setprecision(2) << shipping << endl;
    file << "You are shipping to" << setw(21) << setfill('.') << '.' << destination << endl;
    file << "Your total shipping costs are" << setw(12) << setfill('.') << "$" << fixed << setprecision(2) << total << endl;

    // thank you
    cout << setw(50) << setfill('-') << "Thank You!" << endl;
    cout << endl;

    // don't forget the system("pause")
    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
