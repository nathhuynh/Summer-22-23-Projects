// Simple user registration and login program

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;

    // Read username and password from user
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // read in existing text file
    ifstream read(username + ".txt");

    // read in the un and pw to compare with the entered details
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int selection;

    // Display options to user and receive selection
    cout << "1. Register"
         << "\n";
    cout << "2. Login"
         << "\n";
    cin >> selection;

    // Register option selected
    if (selection == 1)
    {
        string username, password;

        cout << "Select a username: ";
        cin >> username;
        cout << "Select a password: ";
        cin >> password;

        // creates text file with username
        ofstream file;
        file.open(username + ".txt");

        // write the entered un and pw into the text file
        // username on the first line
        // password on the second line
        file << username << "\n"
             << password;
        file.close();

        // calls the main function, allowing user to register another account or login to an existing one
        main();
    }
    // Login option selected
    else if (selection == 2)
    {
        // calls function that reads in a username and password from the user
        // reads in the corresponding text file that matches the username
        // reads the first line of the text file (the registered username) and the second line (the registered password)
        // if the registered username and password match the entered ones, the function returns true
        bool status = IsLoggedIn();

        if (status == false)
        {
            cout << "False Login!"
                 << "\n";
            cout << "Please try again."
                 << "\n";
            main();
        }
        else
        {
            cout << "Successful Login!"
                 << "\n";
            return 1;
        }
    }

    return 0;
}