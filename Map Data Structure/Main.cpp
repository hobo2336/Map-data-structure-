#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main()
{
    // Create a map that connects each number to its word.
    map<int, string> numberWords;

    // Open the file containing the number words.
    ifstream inputFile("numbersAsWords.txt");

    if (!inputFile.is_open())
    {
        cout << "Could not open numbersAsWords.txt." << endl;
        cout << "Make sure the file is in the project folder." << endl;
        return 1;
    }

    // Read each line and store it in the map.
    string currentWord;
    int number = 1;

    while (getline(inputFile, currentWord) && number <= 100)
    {
        numberWords.insert({ number, currentWord });
        number++;
    }

    inputFile.close();

    if (numberWords.size() != 100)
    {
        cout << "The text file must contain 100 number words." << endl;
        return 1;
    }

    // Ask the user for an integer between 1 and 199.
    int userNumber;

    cout << "Enter an integer between 1 and 199: ";

    if (!(cin >> userNumber))
    {
        cout << "Invalid input. Please enter an integer." << endl;
        return 1;
    }

    if (userNumber < 1 || userNumber > 199)
    {
        cout << "The number must be between 1 and 199." << endl;
        return 1;
    }

    // Find the word or words that match the user's number.
    cout << userNumber << " in words is: ";

    if (userNumber <= 100)
    {
        cout << numberWords.at(userNumber);
    }
    else
    {
        cout << numberWords.at(100);

        int remainder = userNumber - 100;

        if (remainder > 0)
        {
            cout << " " << numberWords.at(remainder);
        }
    }

    cout << endl;

    return 0;
}

