// TEAM WAFFLES
// (NAMES GO HERE)
// 
// Case 3: Vigenere Cipher Decryption
// Started: 11/25/2023
// Ended: (DATE GOES HERE)

#include <iostream>
#include <string>
using namespace std;

// Global
const string QUIT_1 = "Thank you for using this program!";
const string INVALID_ANSWER = "Please input a number!";

// Prototypes
int displayMenu(int&);
void titleScreen(int&);
void credits(int&);
void timesUsed_msg(int&);
bool isValid(int, int, int);
void cipher(int);
char returnToMenu(int&);

int main()
{
    // variables
    int timesUsed = 0;
    int userChoice;
    bool useAgain = false;

    // LOOP
    while (useAgain == false)
    {
        // MENU DISPLAY
        system("cls");
        userChoice = displayMenu(timesUsed);

        // SWITCH CASE
        switch (userChoice)
        {
        case 1: // THIS CASE SHOULD ENCRYPT
            system("cls");
            timesUsed++;
            cin.clear();
            cin.ignore();
            cipher(userChoice);
            returnToMenu(timesUsed);
            break;
        case 2: // THIS CASE SHOULD DECRYPT
            system("cls");
            timesUsed++;
            cin.clear();
            cin.ignore();
            cipher(userChoice);
            returnToMenu(timesUsed);
            break;
        case 3:
            system("cls");
            credits(timesUsed);
            break;
        case 4:
            system("cls");
            cout << QUIT_1 << endl << endl;
            timesUsed_msg(timesUsed);
            system("pause");
            exit(0);
        }
    }
}

//////////////////
// FUNCTIONS //
/////////////////

// Displays the Menu
int displayMenu(int& timesUsed)
{
    int min = 1;
    int max = 4;
    int userChoice = 0;

    // Setup a "do" loop for incorrect input until correct input
    do
    {
        titleScreen(timesUsed);
        cout << "User Choice: ";

        // If the user input isn't a number
        while (!(cin >> userChoice))
        {
            system("cls");
            titleScreen(timesUsed);
            cout << INVALID_ANSWER << endl;
            cin.clear();
            cin.ignore();
            cout << "User Choice: ";
        }

        // If the option is not valid, user has to reinput their option
        if (!isValid(userChoice, min, max))
        {
            system("cls");
            cout << "Please choose from the options below." << endl << endl;
        }
    } while (!isValid(userChoice, min, max));

    return userChoice;
}

// This sets up the Title Screen that is used for the DisplayMenu Function
 void titleScreen(int& timesUsed)
{
    cout << "       Vigenere Cipher - CIS7 Final" << endl;
    cout << "               Team WAFFLES" << endl;
    timesUsed_msg(timesUsed);
    cout << "1) Encrypt Text\n2) Decrypt Text\n3) Credits\n4) Quit Program" << endl;
}

// This Displays the Credits
 void credits(int& timesUsed)
{
    cout << " Vigenere Cipher Project Credits - Team WAFFLES" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "   Xenon Garcia | Interface & Navigation Stuff" << endl;
    cout << " Daelon Ruidsel |" << endl;
    cout << "    Jose Orozco |" << endl;
    returnToMenu(timesUsed);
}

// This displays how many times a user has used this program
void timesUsed_msg(int& timesUsed)
{
    if (timesUsed == 0) // Not yet used/just opened up the program
    {
        cout << "-------------------------------------------" << endl;
        cout << "You have not used this program at all yet." << endl;
        cout << "-------------------------------------------" << endl;
    }
    else if (timesUsed == 1) // Only used for proper grammer
    {
        cout << "-------------------------------------------" << endl;
        cout << "You have used this program " << timesUsed << " time." << endl;
        cout << "-------------------------------------------" << endl;
    }
    else // Used for anything after the first time
    {
        cout << "-------------------------------------------" << endl;
        cout << "You have used this program " << timesUsed << " times." << endl;
        cout << "-------------------------------------------" << endl;
    }
}

// Validation Test
bool isValid(int num, int min, int max)
{
    if (num < min || num > max)
        return false;
    else
        return true;
}

// Return To Menu Function
char returnToMenu(int& timesUsed)
{
    char userChoice;

    // Setup a "do" loop for incorrect input until correct input
    do
    {
        cout << endl;
        cout << "Want to go back to menu? (Y/N)" << endl;
        cout << "User Choice: ";
        cin >> userChoice;
        userChoice = toupper(userChoice);

        // If Yes
        if (userChoice == 'Y')
            cout << endl << "thumbs up emoji" << endl;

        // If No
        if (userChoice == 'N') 
        {
            system("cls");
            cout << QUIT_1 << endl << endl;
            timesUsed_msg(timesUsed);
            system("pause");
            exit(0);
        }

        // If it's not YES (y) or NO (n)
        if (userChoice != 'Y' && userChoice != 'N') 
        {
            system("cls");
            cout << "Please make a proper choice." << endl;
        }
    } while (userChoice != 'Y' && userChoice != 'N');

    return userChoice;
}

//////////////////////////////////////////
// ENCRYPT & DECRYPT FUNCTIONS //
/////////////////////////////////////////
 void cipher(int userChoice)
{
     // Variables
     string plain, key, ciphered;

     // This determines the title for the cipher option
     if (userChoice == 1)
     {
         cout << "Vigenere Cipher Project - Encrypting Text" << endl;
         cout << "-------------------------------------------" << endl;
     }
     else if (userChoice == 2)
     {
         cout << "Vigenere Cipher Project - Decrypting Text" << endl;
         cout << "-------------------------------------------" << endl;
     }

    // Text Input
    cout << "Plain Text - Limit 25 Characters\nInput: ";
    getline(cin, plain);
    cout << "\nKeyword - Limit 25 Characters\nInput: ";
    getline(cin, key);
    // ciphered = "TEST";

    /* User choice option so we function lines.
       The "couts" are for testing purposes.
       unless you want to keep the "couts" because its funny lol */
    if (userChoice == 1)
    {
        cout << "\nENCRYPTING!!" << endl;
        // the function for encrpytion should go here
    }
    else if (userChoice == 2)
    {
        cout << "\nDECRYPTING!!" << endl;
        // the function for decryption should go here
    }

    // Length Checking
    if (plain.length() > 25)
        cout << "Plain Text Input exceeded 25 characters. Please try again." << endl;
    else if (key.length() > 25)
        cout << "Keyword Input exceeded 25 characters. Please try again." << endl;

    // Output
    cout << "===========================================" << endl;
    cout << "Your plain text was: \"" << plain << "\"" << endl;
    cout << "Your keyword was: \"" << key << "\"" << endl;
    cout << "Your ciphered text: \"" << ciphered << "\"" << endl;
    cout << "===========================================" << endl;
}