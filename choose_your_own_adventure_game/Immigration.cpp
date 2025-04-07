#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;


int main(){
string gender1;
string gender2;
char exit = 'X';
int exitToken = 0;
char gender;
char response;
int page;


for(int i = 0; i == exitToken;){ // loop
while(exitToken < 1){ //intro
do{
system("CLS");
cout << "Welcome to Choose your own Adventure!\n";
cout << "\nPlease enter your character's gender: \nFor male, enter [M] \nFor female, enter [F]\n";
cin >> gender;
if(gender == 'M' || gender == 'm'){
    gender1 = "man";
    break;
}else if(gender == 'F' || gender == 'f'){
    gender1 = "woman";
    break;
}else if(gender == exit || gender == exit){
    exitToken = 1;
    break;
}else{
    cout << "Your entry was not valid, please try again.\n";
    Sleep(2000);
    continue;
}
}while (true);
break;
}
system("PAUSE");
while(exitToken < 1){ //part1
do{
system("CLS");
cout << "J";
Sleep(20);
cout << "un";
Sleep(100);
cout << "e ";
Sleep(500);
cout << "2";
Sleep(30);
cout << "3r";
Sleep(10);
cout << "d ";
Sleep(300);
cout << "1";
Sleep(20);
cout << "9";
Sleep(100);
cout << "50\n";
Sleep(1000);
cout << "Cata";
Sleep(300);
cout << "nzaro";
Sleep(700);
cout << ", Cala";
Sleep(450);
cout << "bria, ";
Sleep(500);
cout << "Italy.";
cout << "\n\nIt's been almost 7 years since Italy surrendered near the end of WWII.\n";
cout << "However, Southern Italy's cities remain dirtied and impoverished, surrounded by barren soil.\n";
cout << "Italy's economy and political was still in shambles and the situation was still getting worse.\n";
cout << "One day, your mother returns to your ragged home with a letter in hand. It's from your uncle Phillip.\n";
cout << "He immigrated to Canada in search of a job during the first world war, \nand now he wishes to sponsor you to go over yourself.\n\n";
system("PAUSE");
cout << "\n\nWhat is your choice? Will you go or stay?\n";
cout << "If you wish to stay in Italy, enter [A]\nTo leave to Canada, enter [B]\n";
cin >> response;
system("CLS");
if(response == 'A' || response == 'a'){
    page = 2;
    break;
}else if(response == 'B' || response == 'b'){
    page = 3;
    break;
}else if(response == exit || response == exit){
    exitToken = 1;
    break;
}else {
    cout << "Your entry was not valid, please try again.\n";
    Sleep(2000);
    continue;
}
}while (true);
break;
}
while(exitToken < 1){ //part2
system("CLS");
if(page == 2){
    cout << "Your father looks at you questioningly, but doesn't seem to mind the decision that you made.";
    cout << "\nYour mother however, was giving you \'the look\'.\n";
    cout << "\"Listen, I know you feel the need to stay and look over our family.";
    cout << "\nBut you're a young " << gender1 << " now, you're at the age when you should go out and explore!\n";
    cout << "Don't let us hold you back, we'll be fine.\"\n";
    cout << "With that, she decides to send you to Canada anyways :/.\n";
    system("PAUSE");
}
    cout << "\nA few days later, you bid your family goodbye and head to South to the one of the few harbours that remain intact.\n";
    cout << "It takes you about 2 days to get there by foot.\nWhen you finally arrive, ";
    cout << "You finally board a dirty crowded steamship for the cost of an arm and a leg and are finally on your way to Canada.\n";
    system("PAUSE");
    system("CLS");
    do{
    cout << "You arrive in Toronto 2 months later where your uncle comes to pick you up.\n";
    cout << "He helps you settle in at the ghetto area where he lived and did what he could to help.\n";
    cout << "You are informed that you need to pass an english exam before you can work, \nbut you don't even know how to speak any english.\n\n";
    system("PAUSE");

    cout << "\nYou can either ask your uncle for help, or visit the nearby Italian immigrant aid organization, \nCOSTI to see if they were willing to help.\n";
    cout << "To ask your uncle, enter [A]\nTo visit the Italian aid organization, enter [B]\n";
    response = ' ';
    cin >> response;
    system("CLS");
    if(response == 'A' || response == 'a'){
    cout << "You decided to ask you uncle for help. \nHe helps you learn the language well and you feel confident at your exam.\n";
    cout << "The next day, you go out to buy some groceries, Uncle Phillip had offered to make you a welcome meal of pizza.\n";
    system("PAUSE");
    break;
    }else if(response == 'B' || response == 'b'){
    cout << "You decided to go out and visit the organization.\nThey agreed to offer you lessons and you make your way home.\n";
    system("PAUSE");
    break;
}else{
    cout << "Your entry was not valid, please try again.\n";
    Sleep(2000);
    continue;
}
}while (true);
break;
}
while(exitToken < 1){ //SPLIT
system("CLS");

    do{
    cout << "On the street you meet another Italian a few years older than you.\n";
    cout << "He introduces himself as Alex and he shows you around town for awhile...\n";
    system("PAUSE");

    cout << "\nAfter awhile, Alex stops you.\n\"I'd going to get straight to the point kid, us Italians aren't treated very well around here.\n";
    cout << "We need to form groups if we want to survive. I'm willing to give you a chance, so ya in or nah?\"\n";
    cout << "You raise an eyebrow, \"What are you? the Italian Mafia?\" you ask him, not thinking he was serious\n";
    cout << "He just looks back at you awaiting an answer.\n";
    system("PAUSE");
    cout << "What do you do?\n";
    cout << "To accept the offer, enter [A]\nTo decline, enter [B]\n";
    response = ' ';
    cin >> response;
    system("CLS");
    if(response == 'A' || response == 'a'){
    cout << "You decided to accept his offer.\n";
    cout << "He leads you further into the slums than you've been before, until you reach a run down department store\n";
    cout << "You follow Alex inside and into the employee only entrace.\n";
    cout << "He leads you into a room, where you are briefed and introduced to \'il capitano\'\n";
    cout << "You return home that day feeling wary, but not without a tingle of excitement.\n";
    system("PAUSE");
    cout << "\n2 weeks pass and you're finally ready to take your exam.\n2 hours and many groans later, you walk out of the exam room, officially qualified to get a job.\n";
    cout << "Your uncle congratulates you and you celebrate with homemade lasagna that night.\n";
    cout << "Suddenly, Alex calls. He says that the il capitano had a job for you.\n";
    cout << "He wants you to go get him some cigars from a nearby shop.\n";
    cout << "You smirk, this was going to be easy.\n";
    cout << "You grab the pistrol you have been provided with and storm into the shady run down shop\n";
    system("PAUSE");
    cout << "Unfortunately, there was a cop sitting there, smoking a cigar as you barged in.\n";
    cout << "As it seems you've severly overestimated you gangster abilities.\n";
    Sleep(200);
    cout << "The cop felt threatened by your gun and shot you, you bled out on your way to the hostipal.\n";
    Sleep(3200);
    system("PAUSE");
    system("CLS");
    cout << "You Died!\n";
    Sleep(300);
    cout << "To start again, enter [R], to exit, enter [X]: \n";
    response = ' ';
    cin >> response;
    if(response == 'R' || response == 'r'){
    break;
}else if(response == exit || response == exit){
    exitToken = 1;
    break;
}else {
    cout << "Your entry was not valid, please try again.\n";
    Sleep(2000);
    system("CLS");
    continue;
}
    break;
    }else if(response == 'B' || response == 'b'){
    cout << "You decided to decline his offer.\n";
    cout << "You walk away from him, you're uninterested in joining a bunch of ragtag criminals and decide to focus on your upcoming exam";
    cout << "\n2 weeks pass and you're finally ready to take your exam.\n2 hours and many groans later, you walk out of the exam room, officially qualified to get a job.\n";
    cout << "Your uncle congratulates you and you celebrate with homemade lasagna that night.\n";
    system("PAUSE");
    cout << "\nNow you must decide what kind of job to get.\n\n";
    if(gender == 'M' || gender == 'm'){
    cout << "You aren't very smart, but are quite strong. Construction is a great option for you.\n";
    system("PAUSE");
    cout << "\nAfter some time and many applications,\nyou finally found a stable job as a construction worker in Toronto.\n";
    cout << "You were belittled by your fellow workers and only got paid half as much as they did, \nbut it kept your financial system afloat so you stuck with it.\n";
    Sleep(3000);
    cout << "To start again, enter [R], to exit, enter [X]: \n";
    response = ' ';
    cin >> response;
    if(response == 'R' || response == 'r'){
    break;
}else if(response == exit || response == exit){
    exitToken = 1;
    break;
}else {
    cout << "Your entry was not valid, please try again.\n";
    Sleep(2000);
    system("CLS");
    continue;
}
    }else {
    cout << "You aren't very strong, but you do know many basic home skills such as sewing and you enjoy teaching.\n";
    cout << "Maybe you could get a job at Italian aid organizaiton COSTI?\n";
    system("PAUSE");
    cout << "\nAfter some time and many applications,\nyou finally found a stable job as an english and sewing teacher at an Italian Cultural organizaiton,\n";
    cout << "called Instituto Italiano di Cultura (IIDC).\n\n";
    Sleep(3000);
    cout << "To start again, enter [R], to exit, enter [X]: \n";
    response = ' ';
    cin >> response;
    if(response == 'R' || response == 'r'){
    break;
}else if(response == exit || response == exit){
    exitToken = 1;
    break;
}else {
    cout << "Your entry was not valid, please try again.\n";
    Sleep(2000);
    system("CLS");
    continue;
}
    }
    break;
}else{
    cout << "Your entry was not valid, please try again.\n";
    Sleep(2000);
    continue;
}
}while (true);
break;
}



system("CLS");
for(int i = 0; i < 5; i++){
cout << ".\n";
Sleep(100);
system("CLS");
cout << "..\n";
Sleep(100);
system("CLS");
cout << "...\n";
Sleep(100);
system("CLS");
}
system("PAUSE");
system("CLS");
}
cout << "Fin";
return 0;
system("PAUSE");
}
