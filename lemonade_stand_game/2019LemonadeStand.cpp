#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
#include <windows.h>
#include <cstdio>
#include "colours.h"

using namespace std;

// Functions
// ---------
int getSales(int,int);
int getMaxSales(double numLemons, double numWater, double numSugar);

// Start of Main
// ----------
int main()
{
    // Variables
    // ---------
    int price = 0;                // price of a glass of lemonade in cents
    int totalCash = 0;            // total cash user has in cents
    int day = 0;                  // tracks number of days played
    double numLemons = 0;         // lemons in inventory
    double numWater = 0;          // water in inventory
    double numSugar = 0;          // sugar in inventory
    int buyLemons = 0;            // purchased lemons
    int buySugar = 0;             // purchased sugar
    int buyWater = 0;             // purchased water
    double incomeGoal = 0;        // $ amount user wants to earn
    int maxDays = 0;              // max # of days to play
    int costLemons = 0;           // cost of lemons in cents
    int costWater = 0;            // cost of one litre of water in cents
    int costSugar = 0;            // cost of 1 kg bag of sugar in cents
    int totalCost = 0;            // cost of total product purchased
    int maxGlasses = 0;           // maximum # of glasses you can sell
    int numSales = 0;             // # glasses you sell in a day
    int income = 0;               // total income for a day
    int seed = 0;                 // seed for random generator
    int x = 0;                    // x coordinate for printing warnings
    int y = 0;                    // y coordinate for printing warnings
    string name;
    int weather = 0;
    int randEvent = 0;
    char diff;
    int marDeals = 0;
    int door = 0;
    int guessDoor = 0;
    int stolenAmount = 0;
    int loan = 0;
    char makeLoan = 0;


    // seed random generator
    // ----------------------
    seed = time(NULL);
    srand (seed);


    // intro  (ascii art/animation goes here)
    // ------------------------------------------
    initScreen(fYELLOW, bBLACK);
cout << " ____________________________________________________________________\n";
cout << "|  __      __   _                    _                               |\n";
cout << "|  \\ \\    / /__| |__ ___ _ __  ___  | |_ ___                         |\n";
cout << "|   \\ \\/\\/ / -_) / _/ _ \\ '  \\/ -_) |  _/ _ \\                        |\n";
cout << "|    \\_/\\_/\\___|_\\__\\___/_|_|_\\___|  \\__\\___/                        |\n";
cout << "|                                                                    |\n";
cout << "|  _                               _       ___ _                _ _  |\n";
cout << "| | |   ___ _ __  ___ _ _  __ _ __| |___  / __| |_ __ _ _ _  __| | | |\n";
cout << "| | |__/ -_) '  \\/ _ \\ ' \\/ _\` / _\` / -_) \\__ \\  _/ _\` | ' \\/ _\` |_| |\n";
cout << "| |____\\___|_|_|_\\___/_||_\\__,_\\__,_\\___| |___/\\__\\__,_|_||_\\__,_(_) |\n";
cout << " --------------------------------------------------------------------\n\n";
Sleep(3200);
system("CLS");
    cout <<"Loading.\n";
    Sleep (500);
    system ("CLS");
    cout <<"Loading..\n";
    Sleep (500);
    system ("CLS");
    cout <<"Loading...\n";
    Sleep (500);
    system ("CLS");
    cout <<"Loading.\n";
    Sleep (500);
    system ("CLS");
    cout <<"Loading..\n";
    Sleep (500);
    system("CLS");
    cout <<"Loading...\n";
    Sleep (500);
    system("CLS");
    cout <<"Loading.\n";
    Sleep (500);
    system ("CLS");
    cout <<"Loading..\n";
    Sleep (500);
system("CLS");

       // determine start up investment ($5-$10)
    // ---------------------------------------
    totalCash = rand()%501 + 500; //in cents
    // set parameters for game
    // -----------------------

    cout << "Please enter your name:\n";
    cin >> name;
    cout << "Hello there "<< name << "! ";
    do{
    cout << "Please pick your game difficulty:\n";
    cout << "(E) for Easy - $25 in 10 days\n";
    cout << "(M) for Medium - $50 in 10 days\n";
    cout << "(H) for Hard - $75 in 10 days\n";
    cout << "(F) for Freeplay\n";
    cin >> diff;
    if (diff == 'E' || diff == 'e' || diff == 'M' || diff == 'm' || diff == 'H' || diff == 'h' || diff == 'F' || diff == 'f'){
        break;
    }
    cout << "You're answer was invalid\nTry again";
    Sleep(2000);
    system("CLS");
    continue;
    }while (true);
    if (diff == 'E' || diff == 'e'){
        maxDays = 10;
        incomeGoal = 25;
    }
    if (diff == 'M' || diff == 'm'){
        maxDays = 10;
        incomeGoal = 50;
    }
    if (diff == 'H' || diff == 'h'){
        maxDays = 10;
        incomeGoal = 75;
    }
    if (diff == 'F' || diff == 'f'){
    do{
    cout << "How many days do you wish to play the game for?\n";
    cin >> maxDays;
    if (maxDays > 25){
        cout << "That's too long for running a lemonade stand!\nPlease pick a number between 5 and 25 (inclusive)\n";
        Sleep (2000);
        system ("CLS");
        continue;
    }else if (maxDays < 5){
        cout << "That's not enough time to run a lemonade stand!\nPlease pick a number between 5 and 25 (inclusive)\n";
        Sleep (2000);
        system ("CLS");
        continue;
    }break;
    }while (true);
     do{
    cout << "How much money (in dollars) do you wish to make in that time?\n";
    cin >> incomeGoal;
    if (incomeGoal < 20) {
        cout << "That's way too easy,\nHow about at least $20\n";
        Sleep(2000);
        system ("CLS");
        continue;
    }break;
    }while (true);
    cout << "Generating Freeplay";
    }
    system("CLS");

    do{
    // count day
    // ---------
    day = day + 1;
    cout << "DAY " << day;
    Sleep(2500);
    system("CLS");

    //Weather
    weather = 0;
    weather = rand()%4 + 1;
    if (weather == 1){
        cout << "                |\n";
        cout << "                |\n";
        cout << "      `.        |        .'\n";
        cout << "        `.    .---.    .'\n";
        cout << "           .~       ~.\n";
        cout << "          /   O   O   \\\n";
        cout << "-- -- -- (             ) -- -- --\n";
        cout << "          \\    `-'    /\n";
        cout << "           ~.       .~\n";
        cout << "        .'    ~---~    `.\n";
        cout << "      .'        |        `.\n";
        cout << "                |\n";
        cout << "                |\n\n";
        cout << "It's Sunny today!";
    }else if (weather == 2){
    cout << "                _                                  \n";
    cout << "              (`  ).                   _           \n";
    cout << "             (     ).              .:(`  )`.       \n";
    cout << ")           _(       '`.          :(   .    )      \n";
    cout << "        .=(`(      .   )     .--  `.  (    ) )      \n";
    cout << "       ((    (..__.:'-'   .+(   )   ` _`  ) )                 \n";
    cout << "`.     `(       ) )       (   .  )     (   )  ._   \n";
    cout << "  )      ` __.:'   )     (   (   ))     `-'.-(`  ) \n";
    cout << ")  )  ( )       --'       `- __.'         :(      )) \n";
    cout << ".-'  (_.'          .')                    `(    )  ))\n";
    cout << "                  (_  )                     ` __.:'          \n\n";
    cout << "It's cloudy today";

    }else if (weather == 3){
    cout << "    ...        *                        *       * \n";
    cout << "      ...   *         * ..   ...                        * \n";
    cout << " *      ...        *           *            * \n";
    cout << "          ...               ...                          * \n";
    cout << "            ..                            * \n";
    cout << "    *        ..        *                       * \n";
    cout << "           __##____              *                      * \n";
    cout << "  *    *  /  ##  ****                   * \n";
    cout << "         /        ****               *         *  X   * \n";
    cout << "   *    /        ******     *                    XXX      * \n";
    cout << "       /___________*****          *             XXXXX \n";
    cout << "        |            ***               *       XXXXXXX   X \n";
    cout << "    *   | ___        |                    *   XXXXXXXX  XXX \n";
    cout << "  *     | | |   ___  | *       *             XXXXXXXXXXXXXXX \n";
    cout << "        | |_|   | |  ****             *           X   XXXXXXX \n";
    cout << "    *********** | | *******      *                X      X \n";
    cout << "************************************************************ \n\n";
    cout << "It's snowy today";
    }else if(weather ==  4){
    cout << "                             000      00\n";
    cout << "                           0000000   0000\n";
    cout << "              0      00  00000000000000000\n";
    cout << "            0000 0  000000000000000000000000       0\n";
    cout << "         000000000000000000000000000000000000000 000\n";
    cout << "        0000000000000000000000000000000000000000000000\n";
    cout << "    000000000000000000000000000000000000000000000000\n";
    cout << "00000000000000000000000000000000000000000000000000000000\n";
    cout << "              / / / / / / / / / / / / / / / /\n";
    cout << "            / / / / / / / / / / / / / / /\n";
    cout << "            / / / / / / / / / / / / / / /\n";
    cout << "          / / / / / / / / / / / / / /\n";
    cout << "          / / / / / / / / / / / / /\n";
    cout << "        / / / / / / / / / / / /\n";
    cout << "        / / / / / / / / / /\n\n";
    cout << "It's rainy today";
    }
    Sleep(4000);
    system("CLS");
    //Generate Random Events
    if (diff == 'E' || diff == 'e'){
         if (totalCash < 1499){
        randEvent = rand()%9 + 1;

    }else if (totalCash > 1500){
    randEvent = rand()%10 + 1;
    }
    //Random Events
    if (randEvent == 2 || randEvent == 3){
        cout << "It's Your Lucky Day!\nYou found a 10 dollar bill.";
        totalCash = totalCash + 1000;
    Sleep(4000);
    system("CLS");
    }
    if (randEvent == 5){
        cout << "You are assigned to babysitting your brother all day\nWe'll just have to open the stand tomorrow.\n\n";
        cout << "                lllllll_______ \n";
        cout << "             _,_  llllllllllll\\ \n";
        cout << "___         /   \\  llllllllllll\\ \n";
        cout << "   \\       | @ @ |  llllllllllll\ \n";
        cout << "    \\-----oOO---Ooo-------------/ \n";
        cout << "     \\lllllllllllllllllllllllll/ \n";
        cout << "      \\lllllllllllllllllllllll/ \n";
        cout << "       \\lllllllllllllllllllll/ \n";
        cout << "            //            \\\\ \n";
        cout << "           ||             || \n";
        cout << "           OO             OO \n";
        Sleep(4000);
        system("CLS");
        continue;
    Sleep(4000);
    system("CLS");
    }else if (randEvent == 11 || randEvent == 10){
        cout << "Your brother stole your money!\nYou lost 5 dollars.";
        totalCash = totalCash - 500;
    Sleep(4000);
    system("CLS");
    }
    }
    if (diff == 'M' || diff == 'm' || diff == 'F' || diff == 'f'){
         if (totalCash < 1499){
        randEvent = rand()%9 + 1;

    }else if (totalCash > 1500){
    randEvent = rand()%11 + 1;
    }
    //Random Events
    if (randEvent == 2){
        cout << "It's Your Lucky Day!\nYou found a 10 dollar bill.";
        totalCash = totalCash + 1000;
    Sleep(4000);
    system("CLS");
    }
    if (randEvent == 5){
        cout << "You are assigned to babysitting your brother all day\nWe'll just have to open the stand tomorrow.\n\n";
        cout << "                lllllll_______ \n";
        cout << "             _,_  llllllllllll\\ \n";
        cout << "___         /   \\  llllllllllll\\ \n";
        cout << "   \\       | @ @ |  llllllllllll\ \n";
        cout << "    \\-----oOO---Ooo-------------/ \n";
        cout << "     \\lllllllllllllllllllllllll/ \n";
        cout << "      \\lllllllllllllllllllllll/ \n";
        cout << "       \\lllllllllllllllllllll/ \n";
        cout << "            //            \\\\ \n";
        cout << "           ||             || \n";
        cout << "           OO             OO \n";
        Sleep(4000);
        system("CLS");
        continue;
    Sleep(4000);
    system("CLS");
    }else if (randEvent == 11 || randEvent == 10){
        cout << "Your brother stole your money!\nYou lost 5 dollars.";
        totalCash = totalCash - 500;
    Sleep(4000);
    system("CLS");
    }
    }
    if (diff == 'H' || diff == 'h'){
         if (totalCash < 999){
        randEvent = rand()%9 + 1;

    }else if (totalCash > 1000){
    randEvent = rand()%12 + 1;
    }
    //Random Events
    if (randEvent == 2){
        cout << "It's Your Lucky Day!\nYou found a 5 dollar bill.";
        totalCash = totalCash + 500;
    Sleep(4000);
    system("CLS");
    }
    if (randEvent == 5){
        cout << "You are assigned to babysitting your brother all day\nWe'll just have to open the stand tomorrow.\n\n";
        cout << "                lllllll_______ \n";
        cout << "             _,_  llllllllllll\\ \n";
        cout << "___         /   \\  llllllllllll\\ \n";
        cout << "   \\       | @ @ |  llllllllllll\ \n";
        cout << "    \\-----oOO---Ooo-------------/ \n";
        cout << "     \\lllllllllllllllllllllllll/ \n";
        cout << "      \\lllllllllllllllllllllll/ \n";
        cout << "       \\lllllllllllllllllllll/ \n";
        cout << "            //            \\\\ \n";
        cout << "           ||             || \n";
        cout << "           OO             OO \n";
        Sleep(4000);
        system("CLS");
        continue;
    Sleep(4000);
    system("CLS");
    }else if (randEvent == 11 || randEvent == 10){
        cout << "Your brother stole your money!\nYou lost 5 dollars.";
        totalCash = totalCash - 500;
    Sleep(4000);
    system("CLS");
    }
    }
    if(diff == 'e' || diff == 'E' || diff == 'f' || diff == 'F' || diff == 'm' || diff == 'M'){
    if(randEvent == 4){
        cout << "Oh No! You're being ROBBED!\n";
        stolenAmount = rand()%3 + 1;

        if (diff == 'E' || diff == 'e'){
        door = rand()%3 + 1;
        cout << "Wait, you still might be able to catch the burglar.\n";
        Sleep(1200);
        do{
        cout << "Is the burgalar coming in 1. front door, 2. back door or 3. the window?";
        cout << "\n1, 2 or 3?\n";
        cin >> door;
        if (door == guessDoor){
            cout << "You caught them!\nYou recovered your money!";
            Sleep(2500);
            break;
        }else {
            cout << "Drats! Just missed them!\n";
        if(stolenAmount == 1){
            cout << "They stole ALL of your money!";
           totalCash = 0;
        }
        if(stolenAmount == 2){
            cout << "They stole 1/2 of your money!";
             totalCash = totalCash - (int)(totalCash * 0.5);
        }
        if(stolenAmount == 3){
            cout << "They stole 3/4 of your money!";
            totalCash = totalCash - (int)(totalCash * 0.75);
        }
        }
        }while(true);
}
        if (diff == 'M' || diff == 'm' || diff == 'F' || diff == 'f'){
        door = rand()%4 + 1;
        cout << "Wait, you still might be able to catch the burglar.\n";
        Sleep(1200);
        do{
        cout << "Is the burgalar coming in 1. front door, 2. back door, 3. the front window or 4. the back window?";
        cout << "\n1, 2, 3 or 4?\n";
        cin >> door;
        if (door == guessDoor){
            cout << "You caught them!\nYou recovered your money!";
            Sleep(2500);
            break;
        }else {
            cout << "Drats! Just missed them!\n";
        if(stolenAmount == 1){
            cout << "They stole ALL of your money!";
           totalCash = 0;
        }
        if(stolenAmount == 2){
            cout << "They stole 1/2 of your money!";
             totalCash = totalCash - (int)(totalCash * 0.5);
        }
        if(stolenAmount == 3){
            cout << "They stole 3/4 of your money!";
            totalCash = totalCash - (int)(totalCash * 0.75);
        }
        }
        }while(true);
    }
    }
    }
    if(diff == 'h' || diff == 'H'){
        if(randEvent == 4 || randEvent == 6){
        door = rand()%4 + 1;
        cout << "Oh No! You're being ROBBED!\n";
        cout << "Wait, you still might be able to catch the burglar.\n";
        Sleep(1200);
        do{
        cout << "Is the burgalar coming in 1. front door, 2. back door, 3. the front window or 4. the back window?";
        cout << "\n1, 2, 3 or 4?\n";
        cin >> door;
        if (door == guessDoor){
            cout << "You caught them!\nYou recovered your money!";
            Sleep(2500);
            break;
        }else {
            cout << "Drats! Just missed them!\n";
            cout << "They stole ALL of your money!";
           totalCash = 0;
           Sleep(2500);
           break;
        }
        }while(true);
    }
    }
system("CLS");

if(totalCash < 500){
            cout << "You don't have very much money left! \nMake a loan? (Y) for yes, (N) for no.\n";
            cout << "Loans are to be paid at the end of the day with a 10% interest.\n";
            cin >> makeLoan;
            if (makeLoan == 'y' || makeLoan == 'Y'){
                do{
                cout << "How many dollars do you want?\n";
                cin >> loan;
                if (loan < 0 || loan > 100){
                    cout << "The bank can only loan you 1-100 dollars.\nPlease try again.";
                    Sleep(2500);
                    system("CLS");
                    continue;
                }else{
                cout << "You have made a loan of $" << loan;
                totalCash = totalCash + (loan * 100.00);
                Sleep(2500);
                system("CLS");
                break;
                }
            }while(true);
            }
         }
         system("CLS");
         // current inventory
         // ------------------
         cout << " __________\n";
         cout << "|Day: " << day << " / " << maxDays << "|\n";
         cout << "------------------------------------\n";
         cout << "Your current inventory: \n";
         cout << "\tNumber of Lemons: \t";
         cout << numLemons;
         cout << "\n\tLitres of Water: \t";
         cout << numWater;
         cout << "\n\tBags of Sugar: \t\t";
         cout << numSugar;
         cout << "\n\tYou have \t\t";
         if(totalCash < 1000){
            setCoord(32, 7);
            printf("%4.2f", totalCash/100.0);
         }else if (totalCash > 999 && totalCash < 10000){
            setCoord(31, 7);
            printf("%4.2f", totalCash/100.0);
         }else if (totalCash > 9999 && totalCash < 100000){
            setCoord(30, 7);
            printf("%4.2f", totalCash/100.0);
         }

         // set price of lemons, water and sugar
         // ------------------------------------
    if (diff == 'E' || diff == 'e'){
         if (totalCash > 2501) {
            costLemons = rand()%56+20;
            costWater = rand()%51+10;
            costSugar = rand()%281+120;
         }else if (totalCash < 2500){
            costLemons = rand()%41+10;
            costWater = rand()%46+5;
            costSugar = rand()%201+100;
         }
    }
    if (diff == 'M' || diff == 'm' || diff == 'F' || diff == 'f'){
         if (totalCash > 2501) {
            costLemons = rand()%61+20;
            costWater = rand()%66+10;
            costSugar = rand()%301+125;
         }else if (totalCash < 2500){
            costLemons = rand()%51+10;
            costWater = rand()%52+5;
            costSugar = rand()%201+100;
         }
    }
    if (diff == 'H' || diff == 'h'){
         if (totalCash > 2501) {
            costLemons = rand()%71+30;
            costWater = rand()%76+25;
            costSugar = rand()%301+150;
         }else if (totalCash < 2500){
            costLemons = rand()%51+20;
            costWater = rand()%51+10;
            costSugar = rand()%201+120;
         }
    }
    setCoord(0, 10);
    cout << "Today's Market Deals:   ";
    if(diff == 'e' || diff == 'E'){
        marDeals = rand()%9 + 1;
    }
    if(diff == 'm' || diff == 'M' || diff == 'F' || diff == 'f'){
        marDeals = rand()%11 + 1;
    }
    if(diff == 'h' || diff == 'H'){
        marDeals = rand()%13 + 1;
    }

    if (marDeals == 2){
        costSugar = (int)(costSugar * 0.8);
        cout << "Sugar is 20% off.   You Save $";
        cout << (int)(costSugar * 0.2)/100.00;
    }
    if (marDeals == 3){
        costLemons = (int)(costLemons * 0.8);
        cout << "Lemons are 20% off.   You Save $";
        cout << (int)(costLemons * 0.2)/100.00;
    }
    if (marDeals == 4){
        costWater = (int)(costWater * 0.8);
        cout << "Water is 20% off.   You Save $";
        cout << (int)(costSugar * 0.2)/100.00;
    }
    if (marDeals != 4 && marDeals != 3 && marDeals != 2){
        cout << "None";
    }

         // print cost of supplies
         // ----------------------
    if (diff == 'E' || diff == 'e'){
            setCoord(0, 10);
        cout << "Game Difficulty : Easy";
    }
    if (diff == 'M' || diff == 'm' || diff == 'F' || diff == 'f'){
        setCoord(0, 9);
        cout << "Game Difficulty : Medium";
    }
    if (diff == 'H' || diff == 'h'){
        setCoord(0, 9);
        cout << "Game Difficulty : Hard";
    }
    if (weather == 1){
        setCoord(0, 11);
        cout << "Today's Weather is:   Sunny!";
    }
     if (weather == 2){
        setCoord(0, 11);
        cout << "Today's Weather is:   Cloudy!";
    }
     if (weather == 3){
        setCoord(0, 11);
        cout << "Today's Weather is:   Snowy!";
    }
     if (weather == 4){
        setCoord(0, 11);
        cout << "Today's Weather is:   Rainy!";
    }
         cout << "\n\nGROCERY STORE\n";
         //Price of Sugar
         cout << "Sugar (1kg): $";
         printf("%4.2f", costSugar/100.0);
         //Price of Lemons
         cout << "\nLemons: $";
         printf("%4.2f", costLemons/100.0);
         //Price of Water
         cout << "\nWater (1L): $";
         printf("%4.2f", costWater/100.0);
         cout << "\n";

		 // GLOBAL MARKET WARNINGS
         // ----------------------------
         setCoord(50, 0);
         cout << "GLOBAL MARKET WARNINGS\n\n";
         if (diff == 'E' || diff == 'e'){
         if (totalCash > 2500){
            if (costSugar > 350) {
            setCoord(40, 2);
            cout << "Flood destroys sugar";
            setCoord(40, 3);
            cout << "cane farms in Brazil";
            setCoord(40, 4);
            cout << "Sugar is EXPENSIVE!";
         }else if (costSugar < 160){
            setCoord(40, 2);
            cout << "Sugar cane is abundant";
            setCoord(40, 3);
            cout << "Sugar is CHEAP!";
         }
         if (costLemons > 55) {
            setCoord(68, 2);
            cout << "Lemon tart is popular";
            setCoord(68, 3);
            cout << "Lemons are on high demand";
            setCoord(68, 4);
            cout << "Lemons are EXPENSIVE!";
         }else if (costLemons < 35){
            setCoord(68, 2);
            cout << "Good lemon harvest";
            setCoord(68, 3);
            cout << "Lemons are CHEAP!";
         }
         if (costWater > 55) {
            setCoord(96, 2);
            cout << "Bad water pollution";
            setCoord(96, 3);
            cout << "Water is EXPENSIVE!";
         }else if (costWater < 25){
            setCoord(96, 2);
            cout << "Deal for bottled ";
            setCoord(96, 3);
            cout << "water at supermarket";
            setCoord(96, 4);
            cout << "Water is CHEAP!";
         }
         //less than 2.5k
         }else if (totalCash < 2499){
            if (costSugar > 250) {
            setCoord(40, 2);
            cout << "Flood destroys sugar";
            setCoord(40, 3);
            cout << "cane farms in Brazil";
            setCoord(40, 4);
            cout << "Sugar is EXPENSIVE!";
         }else if (costSugar < 150){
            setCoord(40, 2);
            cout << "Sugar cane is abundant";
            setCoord(40, 3);
            cout << "Sugar is CHEAP!";
         }
         if (costLemons > 40) {
            setCoord(68, 2);
            cout << "Lemon tart is popular";
            setCoord(68, 3);
            cout << "Lemons are on high demand";
            setCoord(68, 4);
            cout << "Lemons are EXPENSIVE!";
         }else if (costLemons < 20){
            setCoord(68, 2);
            cout << "Good lemon harvest";
            setCoord(68, 3);
            cout << "Lemons are CHEAP!";
         }
         if (costWater > 40) {
            setCoord(96, 2);
            cout << "Bad water pollution";
            setCoord(96, 3);
            cout << "Water is EXPENSIVE!";
         }else if (costWater < 20){
            setCoord(96, 2);
            cout << "Deal for bottled ";
            setCoord(96, 3);
            cout << "water at supermarket";
            setCoord(96, 4);
            cout << "Water is CHEAP!";
         }
         }
    }
         if (diff == 'M' || diff == 'm' || diff == 'F' || diff == 'f'){
         if (totalCash > 2500){
            if (costSugar > 375) {
            setCoord(40, 2);
            cout << "Flood destroys sugar";
            setCoord(40, 3);
            cout << "cane farms in Brazil";
            setCoord(40, 4);
            cout << "Sugar is EXPENSIVE!";
         }else if (costSugar < 160){
            setCoord(40, 2);
            cout << "Sugar cane is abundant";
            setCoord(40, 3);
            cout << "Sugar is CHEAP!";
         }
         if (costLemons > 60) {
            setCoord(68, 2);
            cout << "Lemon tart is popular";
            setCoord(68, 3);
            cout << "Lemons are on high demand";
            setCoord(68, 4);
            cout << "Lemons are EXPENSIVE!";
         }else if (costLemons < 35){
            setCoord(68, 2);
            cout << "Good lemon harvest";
            setCoord(68, 3);
            cout << "Lemons are CHEAP!";
         }
         if (costWater > 60) {
            setCoord(96, 2);
            cout << "Bad water pollution";
            setCoord(96, 3);
            cout << "Water is EXPENSIVE!";
         }else if (costWater < 35){
            setCoord(96, 2);
            cout << "Deal for bottled ";
            setCoord(96, 3);
            cout << "water at supermarket";
            setCoord(96, 4);
            cout << "Water is CHEAP!";
         }
         //less than 2.5k
         }else if (totalCash < 2499){
            if (costSugar > 240) {
            setCoord(40, 2);
            cout << "Flood destroys sugar";
            setCoord(40, 3);
            cout << "cane farms in Brazil";
            setCoord(40, 4);
            cout << "Sugar is EXPENSIVE!";
         }else if (costSugar < 125){
            setCoord(40, 2);
            cout << "Sugar cane is abundant";
            setCoord(40, 3);
            cout << "Sugar is CHEAP!";
         }
         if (costLemons > 45) {
            setCoord(68, 2);
            cout << "Lemon tart is popular";
            setCoord(68, 3);
            cout << "Lemons are on high demand";
            setCoord(68, 4);
            cout << "Lemons are EXPENSIVE!";
         }else if (costLemons < 20){
            setCoord(68, 2);
            cout << "Good lemon harvest";
            setCoord(68, 3);
            cout << "Lemons are CHEAP!";
         }
         if (costWater > 40) {
            setCoord(96, 2);
            cout << "Bad water pollution";
            setCoord(96, 3);
            cout << "Water is EXPENSIVE!";
         }else if (costWater < 15){
            setCoord(96, 2);
            cout << "Deal for bottled ";
            setCoord(96, 3);
            cout << "water at supermarket";
            setCoord(96, 4);
            cout << "Water is CHEAP!";
         }
         }
    }
         if (diff == 'H' || diff == 'h'){
         if (totalCash > 2500){
            if (costSugar > 395) {
            setCoord(40, 2);
            cout << "Flood destroys sugar";
            setCoord(40, 3);
            cout << "cane farms in Brazil";
            setCoord(40, 4);
            cout << "Sugar is EXPENSIVE!";
         }else if (costSugar < 235){
            setCoord(40, 2);
            cout << "Sugar cane is abundant";
            setCoord(40, 3);
            cout << "Sugar is CHEAP!";
         }
         if (costLemons > 80) {
            setCoord(68, 2);
            cout << "Lemon tart is popular";
            setCoord(68, 3);
            cout << "Lemons are on high demand";
            setCoord(68, 4);
            cout << "Lemons are EXPENSIVE!";
         }else if (costLemons < 45){
            setCoord(68, 2);
            cout << "Good lemon harvest";
            setCoord(68, 3);
            cout << "Lemons are CHEAP!";
         }
         if (costWater > 80) {
            setCoord(96, 2);
            cout << "Bad water pollution";
            setCoord(96, 3);
            cout << "Water is EXPENSIVE!";
         }else if (costWater < 40){
            setCoord(96, 2);
            cout << "Deal for bottled ";
            setCoord(96, 3);
            cout << "water at supermarket";
            setCoord(96, 4);
            cout << "Water is CHEAP!";
         }
         //less than 2.5k
         }else if (totalCash < 2499){
            if (costSugar > 270) {
            setCoord(40, 2);
            cout << "Flood destroys sugar";
            setCoord(40, 3);
            cout << "cane farms in Brazil";
            setCoord(40, 4);
            cout << "Sugar is EXPENSIVE!";
         }else if (costSugar < 160){
            setCoord(40, 2);
            cout << "Sugar cane is abundant";
            setCoord(40, 3);
            cout << "Sugar is CHEAP!";
         }
         if (costLemons > 55) {
            setCoord(68, 2);
            cout << "Lemon tart is popular";
            setCoord(68, 3);
            cout << "Lemons are on high demand";
            setCoord(68, 4);
            cout << "Lemons are EXPENSIVE!";
         }else if (costLemons < 30){
            setCoord(68, 2);
            cout << "Good lemon harvest";
            setCoord(68, 3);
            cout << "Lemons are CHEAP!";
         }
         if (costWater > 45) {
            setCoord(96, 2);
            cout << "Bad water pollution";
            setCoord(96, 3);
            cout << "Water is EXPENSIVE!";
         }else if (costWater < 25){
            setCoord(96, 2);
            cout << "Deal for bottled ";
            setCoord(96, 3);
            cout << "water at supermarket";
            setCoord(96, 4);
            cout << "Water is CHEAP!";
         }
         }
    }
         // Buy Sugar
         // ---------
         do{
         setCoord(0, 17);
         cout << "How many 1kg bags of sugar would you like to buy?  ";
         cin >> buySugar;
         // Total cost of Sugar
         totalCost = costSugar * buySugar;

         // Update totalCash
         // ------------------------------------
         if(buySugar < 0){
            cout << "\nNice try, but you can't sell your sugar.";
            Sleep(2000);
            setCoord(0, 17);
         cout << "                                                          ";
         setCoord(0, 18);
         cout << "                                                          ";
         setCoord(0, 19);
         cout << "                                                          ";
         setCoord(0, 20);
         cout << "                                                          ";
         setCoord(0, 21);
         cout << "                                                          ";
            continue;
         }
         if(totalCash < totalCost){
            cout << "\nYou can't afford " << buySugar <<" bags of sugar\n";
            cout << "You can afford " << (int)(totalCash/costSugar) << " bags.";
            Sleep(2000);
            setCoord(0, 17);
         cout << "                                                          ";
         setCoord(0, 18);
         cout << "                                                          ";
         setCoord(0, 19);
         cout << "                                                          ";
         setCoord(0, 20);
         cout << "                                                          ";
         setCoord(0, 21);
         cout << "                                                          ";
            continue;
         }
         totalCash = totalCash - totalCost;
         break;
         }while(true);
         //Update inventory - Sugar
         // ------------------------------------
         numSugar = numSugar + buySugar;
         setCoord(25, 7);
         cout << "                               ";
         if(totalCash < 1000){
            setCoord(32, 7);
            printf("%4.2f", totalCash/100.0);
         }else if (totalCash > 999 && totalCash < 10000){
            setCoord(31, 7);
            printf("%4.2f", totalCash/100.0);
         }else if (totalCash > 9999 && totalCash < 100000){
            setCoord(30, 7);
            printf("%4.2f", totalCash/100.0);
         }

         if(numSugar < 10){
            setCoord(32, 6);
            printf("%4.2f", numSugar);
         }else if (numSugar > 9.99 && numSugar < 100){
            setCoord(31, 6);
            printf("%4.2f", numSugar);
         }else if (numSugar > 99.99 && numSugar < 1000){
            setCoord(30, 6);
            printf("%4.2f", numSugar);
         }

         // Buy Lemons
         // ----------
         do{
         setCoord(0, 17);
         cout << "                                                          ";
         setCoord(0, 18);
         cout << "                                                          ";
         setCoord(0, 19);
         cout << "                                                          ";
         setCoord(0, 20);
         cout << "                                                          ";
         setCoord(0, 21);
         cout << "                                                          ";
         setCoord(0, 17);
         cout << "How many lemons would you like to buy?  ";
         cin >> buyLemons;
         // Total cost of Lemons
         totalCost = costLemons * buyLemons;

         // Update totalCash
         // ------------------------------------
         if(buyLemons < 0){
            cout << "\nNice try, but you can't sell your lemons.";
            Sleep(2000);
            setCoord(0, 17);
         cout << "                                                          ";
         setCoord(0, 18);
         cout << "                                                          ";
         setCoord(0, 19);
         cout << "                                                          ";
         setCoord(0, 20);
         cout << "                                                          ";
         setCoord(0, 21);
         cout << "                                                          ";
            continue;
         }
         if(totalCash < totalCost){
            cout << "\nYou can't afford " << buyLemons <<" lemons\n";
            cout << "You can afford " << (int)(totalCash/costLemons) << " lemons.";
            Sleep(2000);
            setCoord(0, 17);
         cout << "                                                          ";
         setCoord(0, 18);
         cout << "                                                          ";
         setCoord(0, 19);
         cout << "                                                          ";
         setCoord(0, 20);
         cout << "                                                          ";
         setCoord(0, 21);
         cout << "                                                          ";
            continue;
         }
         totalCash = totalCash - totalCost;
         break;
         }while(true);

         //Update inventory - Lemons
         // ------------------------------------
         numLemons = numLemons + buyLemons;
         setCoord(25, 7);
         cout << "                               ";
         if(totalCash < 1000){
            setCoord(32, 7);
            printf("%4.2f", totalCash/100.0);
         }else if (totalCash > 999 && totalCash < 10000){
            setCoord(31, 7);
            printf("%4.2f", totalCash/100.0);
         }else if (totalCash > 9999 && totalCash < 100000){
            setCoord(30, 7);
            printf("%4.2f", totalCash/100.0);
         }

         if(numLemons < 10){
            setCoord(32, 4);
            printf("%4.2f", numLemons);
         }else if (numLemons > 9.99 && numLemons < 100){
            setCoord(31, 4);
            printf("%4.2f", numLemons);
         }else if (numLemons > 99.99 && numLemons < 1000){
            setCoord(30, 4);
            printf("%4.2f", numLemons);
         }

         // Buy Water
         // ---------
         do{
         setCoord(0, 17);
         cout << "                                                          ";
         setCoord(0, 18);
         cout << "                                                          ";
         setCoord(0, 19);
         cout << "                                                          ";
         setCoord(0, 20);
         cout << "                                                          ";
         setCoord(0, 21);
         cout << "                                                          ";
         setCoord(0, 17);
         cout << "How many litres of water would you like to buy?  ";
         cin >> buyWater;
         // Total cost of Lemons
         totalCost = costWater * buyWater;

         // Update totalCash
         // ------------------------------------
         if(buyWater < 0){
            cout << "\nNice try, but you can't sell your water.";
            Sleep(2000);
            setCoord(0, 17);
         cout << "                                                          ";
         setCoord(0, 18);
         cout << "                                                          ";
         setCoord(0, 19);
         cout << "                                                          ";
         setCoord(0, 20);
         cout << "                                                          ";
         setCoord(0, 21);
         cout << "                                                          ";
            continue;
         }
         if(totalCash < totalCost){
            cout << "\nYou can't afford " << buyWater <<" litres of water\n";
            cout << "You can afford " << (int)(totalCash/costWater) << " litres.";
            Sleep(2000);
            setCoord(0, 17);
         cout << "                                                          ";
         setCoord(0, 18);
         cout << "                                                          ";
         setCoord(0, 19);
         cout << "                                                          ";
         setCoord(0, 20);
         cout << "                                                          ";
         setCoord(0, 21);
         cout << "                                                          ";
            continue;
         }
         totalCash = totalCash - totalCost;
         break;
         }while(true);


         //Update inventory - Water
         // ------------------------------------
         numWater = numWater + buyWater;
         setCoord(25, 7);
         cout << "                               ";
         if(totalCash < 1000){
            setCoord(32, 7);
            printf("%4.2f", totalCash/100.0);
         }else if (totalCash > 999 && totalCash < 10000){
            setCoord(31, 7);
            printf("%4.2f", totalCash/100.0);
         }else if (totalCash > 9999 && totalCash < 100000){
            setCoord(30, 7);
            printf("%4.2f", totalCash/100.0);
         }

         if(numWater < 10){
            setCoord(32, 5);
            printf("%4.2f", numWater);
         }else if (numWater > 9.99 && numWater < 100){
            setCoord(31, 5);
            printf("%4.2f", numWater);
         }else if (numWater > 99.99 && numWater < 1000){
            setCoord(30, 5);
            printf("%4.2f", numWater);
         }

         // Print max number of glasses that can be sold
         // --------------------------------------------

         maxGlasses = getMaxSales(numLemons, numWater, numSugar);

         setCoord(0, 17);
         cout << "                                                          ";
         setCoord(0, 18);
         cout << "                                                          ";
         setCoord(0, 19);
         cout << "                                                          ";
         setCoord(0, 20);
         cout << "                                                          ";
         setCoord(0, 21);
         cout << "                                                          ";

         setCoord(0, 17);
         cout << "You can make " << maxGlasses << " glasses of lemonade.";
         Sleep(1000);


         // Clear away global market warnings
         // ----------------------------------

         // Get price of 1 glass of lemonade from user
         // ------------------------------------------

         do{

         setCoord(0, 18);
         cout << "                                                          ";
         setCoord(0, 19);
         cout << "                                                          ";
         setCoord(0, 20);
         cout << "                                                          ";
         setCoord(0, 21);
         cout << "                                                          ";

         setCoord(0, 18);
         cout << "How much (in cents) would you like to sell one glass of lemonade for?   ";
         cin >> price;
         if(price > 200){
             setCoord(0, 19);
             cout << "That's too expensive for 1 glass of lemonade!";
             setCoord(0, 20);
             cout << "Pick a number between 20 and 200.";
             Sleep(3000);
             continue;
         }else if(price < 20){
             setCoord(0, 19);
             cout << "That's too cheap for 1 glass of lemonade!";
             setCoord(0, 20);
             cout << "Pick a number between 20 and 200.";
             Sleep(3000);
             continue;
         }
         system("CLS");
         break;
         }while(true);

         // Display Stand
         // -------------
         setCoord(0, 0);
         cout << "   ______________________ \n";
         cout << "  /                      \\ \n";
         cout << " /     FRESH LEMONADE     \\ \n";
         cout << "/__________________________\\ \n";
         cout << " |                        | \n";
         cout << " |                        | \n";
         cout << " |                        | \n";
         cout << " |                        | \n";
         cout << " |                        | \n";
         cout << " |                        | \n";
         cout << " |                _       | \n";
         cout << " |  |~| |~|      \\ }      | \n";
         cout << " |__|_|_|_|______(_)______| \n";
         cout << " |||||||||||||||||||||||||| \n";
         cout << " |||||||||||||||||||||||||| \n";
         cout << " |||||||||||||||||||||||||| \n";
         cout << " |||||||||||||||||||||||||| \n\n";

         // Determine sales for the day
         // --------------------------

         if(weather == 3){ // Snowy
            numSales = (getSales(price, maxGlasses) * 0.5);
         }
         if(weather == 2){ // Cloudy
            numSales = getSales(price, maxGlasses);
         }
         if(weather == 1){ // Sunny
            numSales = maxGlasses - (0.2 * getSales(price, maxGlasses));
         }
         if(weather == 4){ // rainy
            numSales = (getSales(price, maxGlasses) * 0.8);
         }

         // Calculate income for the day
         // ----------------------------

         income = numSales * price;
         totalCash = totalCash + income;

         // Print sales and income for the day
         // ----------------------------------
         setCoord(0, 19);
         cout << "Your total sales today were: ";
         int i = 0;
         do{
         setCoord (0, 20);
         cout << i;
         Sleep(100);
         i = i + 1;
         }while (i <= numSales);

         setCoord(0, 21);
         cout << "You made $" << income/100.00 << ".";
         setCoord(0, 24);
         system("PAUSE");
         system("CLS");


         if(makeLoan == 'y' || makeLoan == 'Y'){
            cout << "Time to pay your loan!\n";
            totalCash = totalCash - (loan * 110);
            loan = 0;
            Sleep(2500);

            if(totalCash < 0){
                cout << "YOU'VE GONE BROKE!!!\n\n";
                cout << "                                          __ \n";
      cout << " __ __            __    _____ _____ _____|  |\n";
      cout << "|  |  |___ _ _   |  |  |     |   __|   __|  |\n";
      cout << "|_   _| . | | |  |  |__|  |  |__   |   __|__|\n";
      cout << "  |_| |___|___|  |_____|_____|_____|_____|__|\n\n";
      return 0;
      system("PAUSE");
      system("CLS");
            }

         }
         system("CLS");

		 // Calculate supplies left
         // -----------------------
         numLemons = numLemons - (numSales/2.0);
         numSugar = numSugar - (numSales/20.00);
         numWater = numWater - (numSales/4.0);


    // Repeats each day
    } while (day < maxDays);

    // Determine win/loss
    // -------------------
    if (totalCash >= incomeGoal * 100) {
      cout << "_____.___.               __      __.__      ._.\n";
      cout << "\\__  |   | ____  __ __  /  \\    /  \\__| ____| |\n";
      cout << " /   |   |/  _ \\|  |  \\ \   \\/\\/   /  |/    \ |\n";
       cout << "\\____   (  <_> )  |  /  \\        /|  |   |  \\|\n";
       cout << "/ ______|\\____/|____/    \\__/\\  / |__|___|  /_\n";
       cout << "\\/                            \\/          \\/\\/ \n\n";
    } // if
    else  {
      cout << "                                          __ \n";
      cout << " __ __            __    _____ _____ _____|  |\n";
      cout << "|  |  |___ _ _   |  |  |     |   __|   __|  |\n";
      cout << "|_   _| . | | |  |  |__|  |  |__   |   __|__|\n";
      cout << "  |_| |___|___|  |_____|_____|_____|_____|__|\n\n";
    } // else

    cout << "Your goal was $" << incomeGoal << " and you made $"
         << totalCash / 100.0 << endl;

    // end program
    // -----------
    return 0;
    system("PAUSE");

} // End of main

// -----------------------------------------------------------------------------
// Function: getSales
// Input:    price in cents, max # glasses that can be sold
// Output:   Actual number of sales
// Purpose: generates a number of sales based on set price and random numbers
// -----------------------------------------------------------------------------
int getSales(int price, int maxGlasses) {

    int numSales = 0;
    int calcSales = 0;
    int randNum = rand() % 100 + 1;

    // formula requires prices to be between 10 cents and 3 dollars
    if (price < 1) price = 1;
    else if (price > 300) price = 300;

    // formula for sales
    calcSales = (int)((-1 / 3.0) * price) + 100;

    // numSales is halfway btwn randNum and calcSales
    int difference = randNum - calcSales;
    if (randNum > calcSales)
        numSales = randNum - (difference / 3);
    else
        numSales = calcSales - (difference / 3);

	if (numSales > 100) numSales = 100;

    return (int)(maxGlasses * (numSales / 100.0));
} // getSales

// -----------------------------------------------------------------------------
// Function: getMaxSales
// Input:    numLemons - number of lemons in inventory
//           numWater  - number of litres of water in inventory
//           numSugar  - number of bags of sugar in inventory
// Output:   Maximum number of glasses of lemonade that can be sold
// Purpose:  determine how many glasses of lemonade that can be sold
// -----------------------------------------------------------------------------
int getMaxSales(double numLemons, double numWater, double numSugar){
     int a = int (numLemons * 2);  // 2 glasses /lemon
     int b = int (numWater * 4);   // 4 glasses / litre water
     int c = int (numSugar * 20);  // 20 glasses / 1 kg sugar
     return (a < b && a < c) ? a : ((b < c) ? b : c);
} // getMaxSales
