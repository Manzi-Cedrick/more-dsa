#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int randomNumber(int min, int max)
{
    return rand() % (max - min) + min;
}
string printTheSelectedArray(string category[],int length){
    string selectedArrayItems = "";
    for(int i=0; i<length; i++){
        selectedArrayItems += category[i] + ", ";
    }
    cout<<"["<<selectedArrayItems<<"]"<<endl;
}
string randomiseString(string category[], int length)
{
    string random = "";
    /* Getting the length of the array. */
    // int length = sizeof(category) / sizeof(category[0]);
    for (int i = 0; i < length - 1; i++)
    {
        random = category[randomNumber(length, 0)];
    }
    cout<<"random String: "<<random;
    return random;
}
int verifyChoice(int choice)
{
    switch (choice)
    {
    case 1:
        choice = 1;
        cout << "The NBA clubs choice:" <<choice << endl;
        break;
    case 2:
        choice = 2;
        cout << "The Food Choice: "<<choice << endl;
        break;
    case 3:
        choice = 3;
        cout << "The Animal Choice: "<<choice << endl;
        break;
    case 4:
        choice = 4;
        cout << "The Object Choice: "<<choice << endl;
        break;
    default:
        cout << "Category Invalid !! More categories coming" << endl;
        exit(1);
        break;
    }
    return choice;
}
int GuessChances(string GuessedString)
{
    int chances;
    return chances = GuessedString.length();
}
string PlaceOccupy(string toGuessString, int length)
{
    for (int i = 0; i < length; i++)
    {
        toGuessString[i] = '_';
    }
    return toGuessString;
}
string CheckWord(string toGuessString, int chanceLength)
{
    char enteredCh, initialCh = '_';
    string correctword;
    string dashString = PlaceOccupy(toGuessString, chanceLength);
    for (int i = chanceLength; i > 0; i--)
    {
        cout << "Enter the char: ";
        cin >> enteredCh;
        int GuessStringLength = toGuessString.length();
        for (int j = 0; j < GuessStringLength; j++)
        {
            if (toGuessString[j] == enteredCh)
            {
                dashString[j] = enteredCh;
            }
        }
        cout << "The chances left are: " << i << endl;
        if (dashString == toGuessString)
        {
            i = 0;
            cout << "=================================== WIN ======================================="<<endl;
            cout << "The Correct Word: " << toGuessString << endl;
            cout << "You win the game"<< endl;
        }
        cout << dashString << endl;
    }

    if (dashString != toGuessString)
    {
        cout << "=================================== LOST ======================================="<<endl;
        cout << "The Correct  was: " << toGuessString << endl;
        cout << "You lost the game"<< endl;
    }
}
int main()
{
    // categories
    string NBA_Clubs[] = {"Lakers", "Warriors", "Spurs", "Knicks", "Celtics"};
    string Food[] = {"Mango", "Bread", "Juice", "Strawberry", "Avocado"};
    string Animals[] = {"Lion", "Gorilla", "Monkey", "Fish", "Bears"};
    string Objects[] = {"Pen", "Pencil", "paper", "chair", "table", "computer", "projector", "adapter", "ethernet", "laptops"};
    int choice;
    cout << "==================================== WELCOME TO THE GUESS GAME ===============================" << endl;
    cout << "The Menu categories\n 1.NBA Clubs\n 2.Food\n 3.Animals\n 4.Objects\n";
    cout << "Enter the guess category number: ";
    cin >> choice;
    int resultChoice = verifyChoice(choice);
    switch (resultChoice){
    case 1:
    {

        int length = sizeof(NBA_Clubs) / sizeof(NBA_Clubs[0]);
        printTheSelectedArray(NBA_Clubs, length);
        string randomWord = randomiseString(NBA_Clubs, length);
        int chanceNum = GuessChances(randomWord);
        cout << "The chances are: " << chanceNum << endl;
        string resultString = CheckWord(randomWord, chanceNum);
        break;
    }
    case 2:
    {
        int length = sizeof(Food) / sizeof(Food[0]);
        printTheSelectedArray(Food,length);
        string randomWord = randomiseString(Food, length);
        int chanceNum = GuessChances(randomWord);
        cout << "The chances are: " << chanceNum << endl;
        string resultString = CheckWord(randomWord, chanceNum);
        break;
    }
     case 3:
    {
        int length = sizeof(Animals) / sizeof(Animals[0]);
        printTheSelectedArray(Animals, length);
        string randomWord = randomiseString(Animals, length);
        int chanceNum = GuessChances(randomWord);
        cout << "The chances are: " << chanceNum << endl;
        string resultString = CheckWord(randomWord, chanceNum);
        break;
    }
     case 4:
    {
        int length = sizeof(Objects) / sizeof(Objects[0]);
        printTheSelectedArray(Objects, length);
        string randomWord = randomiseString(Objects, length);
        int chanceNum = GuessChances(randomWord);
        cout << "The chances are: " << chanceNum << endl;
        string resultString = CheckWord(randomWord, chanceNum);
        break;
    }
     default:
        {
        cout << "The Random String Not Fetched ";
        break;
        }
    }
    return 0;
}
