#include<iostream>
#include<string>
#include<fstream>  // Header file for file handling
using namespace std;

int main()
{
    // Creating object of the file:
    fstream file;

    // Opening file in write/append mode
    file.open("myfile.txt", ios::out | ios::app); // ios::out for output, ios::app to append data
    if (!file)
    {
        cout << "Error: File could not be opened for writing.\n";
        return 1;
    }

    int id;
    string name;
    char check;

    // Writing data to file
    do
    {
        cout << "\nPlease Enter ID: ";
        cin >> id;

        cout << "Please Enter Name (single word only): ";
        cin >> name; // use getline if you want full name with spaces

        file << id << " -> " << name << endl; // writing to file

        cout << "\nDo you want to continue entering values? (y/n): ";
        cin >> check;

        // Input validation
        if (check != 'y' && check != 'n')
        {
            cout << "Invalid Option! Exiting...\n";
            break;
        }

    } while (check == 'y');

    file.close(); // closing file after writing

    // Reopening file in read mode/getting data from file
    file.open("myfile.txt", ios::in);
    if (!file)
    {
        cout << "Error: File could not be opened for reading.\n";
        return 1;
    }

    // Reading file line-by-line
    string line;
    cout << "\nReading from file:\n";
    while (getline(file, line))   // safely reads whole line
    {
        cout << line << endl;
    }

    file.close();   // closing file after reading
    return 0;
}
