import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class ChangeOneLetter {

static  String [] fileContents;

public static void main(String[] args) {
Scanner in = new Scanner( System.in );
String startWord = "";
String currentWord = "";
String goalWord = "";
String error = "";
char newLetter = 'a';
char index = 0;
int counter = 0;
String input = "";
int indexNum = 0;
int playerNum = 0;
char[] a;
char newChar = 'a';

String[] dictionary = getFileContents("dictionarywords.txt");





startWord = getStartWord();
currentWord = startWord;
System.out.println("Starting Word Entered by Player 1: " + startWord);


goalWord = getGoalWord();

System.out.println("Goal Word Entered by Player 2: " + goalWord);

do {

// looks at which players turn
if (counter % 2 == 0){
playerNum = 1;
}else {
playerNum = 2;
}
// checks if the new word
input = getInput(playerNum, currentWord, dictionary);

error = "";

// changes the letter
newChar = input.charAt(2);
indexNum = Character.getNumericValue(input.charAt(0));
a = currentWord.toCharArray();
a[indexNum] = newChar;

currentWord = new String(a);

if(isValidWord(currentWord) == false) {

continue;
} else {

// to switch player
counter++;
// outputs new word
System.out.println("Player " + playerNum +"'s new word: " + currentWord);
// if they win or not
if (currentWord.equals(goalWord)) {
System.out.println("Congratulations to Player " + playerNum + ". You won in " + counter + " steps!");
}
}//if else


} while (!currentWord.equals(goalWord));



} //main

public static String getInput(int playerNum, String currentWord, String d[]){

do{ // error check
String error = "";


String input = JOptionPane.showInputDialog(error + "Player " + playerNum + ", please make one change to the starting word to try to get to the goal word.\n"
+ "Enter the index of the letter you want to change (0-3), followed by a space, "
+ "followed by the letter you want to change it to. \nThe new word must be a word in the English dictionary. ");

if (input == null) {
System.out.println("You clicked cancel");
System.exit(0);
}

//System.out.println(input);

if(Character.getNumericValue(input.charAt(0)) <= -1
|| Character.getNumericValue(input.charAt(0)) >= 4
|| Character.isLetter(input.charAt(2)) == false
){
continue;
}else {

//System.out.println(input);

//check if index is within boundaries
if(Integer.parseInt(input.substring(0, 1)) < 0 || Integer.parseInt(input.substring(0, 1)) > 3) {
error = "The index " + Integer.parseInt(input.substring(0, 1)) + " does not exist within a four letter word.";
continue;
}
String changedword = makeChanges(input, currentWord, d); //make the change to the word
if(changedword.equals("error")){ // if the changed word isn't a valid 4 letter word, re-enter a modification and retry
error = "The word you changed it to does not exist.\n";
continue;
}else{
return changedword; // if everything works, return the new word
}
}
}while(true);
}
public static String[] getFileContents(String fileName) {

String[] contents = null;
int length = 0;
try {

// input
String folderName = ""; // if the file is contained in the same folder as the .class file, make this equal to the empty string
String resource = fileName;

// this is the path within the jar file
InputStream input = ChangeOneLetter.class.getResourceAsStream(folderName + resource);
if (input == null) {
// this is how we load file within editor (eg eclipse)
input = ChangeOneLetter.class.getClassLoader().getResourceAsStream(resource);
}
BufferedReader in = new BufferedReader(new InputStreamReader(input));

in .mark(Short.MAX_VALUE); // see api

// count number of lines in file
while ( in .readLine() != null) {
length++;
}

in .reset(); // rewind the reader to the start of file
contents = new String[length]; // give size to contents array

// read in contents of file and print to screen
for (int i = 0; i < length; i++) {
contents[i] = in .readLine();
} in .close();
} catch (Exception e) {
System.out.println("");
}

return contents;

} // getFileContents

//check for if the word is valid or not
public static boolean isValidWord(String word) {
//fileContents obtains and holds all the words from dictionary.txt
String[] fileContents = getFileContents("dictionary.txt");
boolean valid = false;

for (int i = 0; i < fileContents.length; i++) {
//checks if tested word is valid
if (fileContents[i].contains(word) == true) {
//updates valid if word checked is in dictionary.txt
valid = true;
}//if
} //for

return valid;
} //isWordValid
public static boolean checkDictionary(String word, String d[]) {
for(String s : d) { // for every String in array d
if(s.contains(word)){ // if one string contains
return true;
}

}
return false;
}
public static String makeChanges(String s, String y, String d[]) {
String currentWord = "";
if(checkDictionary(currentWord, d ) == true){
return currentWord;
}
return "error";
}

public static String getStartWord() {
String input = "";
String error = "";
String currentWord = "";

do {
input = JOptionPane.showInputDialog(error + "Player 1, please enter a four letter word from the English dictionary. This is your starting word. ");

if(input == null) {
System.exit(0);
} // if

// sets word to all lowercase

currentWord = input.toLowerCase();

if(currentWord.length() != 4) {
error = "Please check that the word you entered is four letters. ";
continue;
} else if(isValidWord(currentWord) == false){
error = "Please make sure the word you entered is a valid English word.";
continue;
}else {
break;
}


} while (true);
return currentWord;


} // getStartWord

public static String getGoalWord() {
String input = "";
String error = "";
String currentWord = "";

do {
input = JOptionPane.showInputDialog(error + "Player 2, please enter a four letter word from the English dictionary. This is your goal word. ");

if(input == null) {
System.exit(0);
} // if

// sets word to all lowercase

currentWord = input.toLowerCase();

if(currentWord.length() != 4) {
error = "Please check that the word you entered is four letters. ";
continue;
} else if(isValidWord(currentWord) == false){
error = "Please make sure the word you entered is a valid English word.";
continue;
}else {
break;
}


} while (true);
return currentWord;
}

public static String getcurrentWord() {
String input = "";
String error = "";
String currentWord = "";
int playerNum = 0;

do {
input = JOptionPane.showInputDialog(error + "Player " + playerNum + ", please make one change to the starting word to try to get to the goal word."
+ "Enter the index of the letter you want to change (0-3), followed by a space, "
+ "followed by the letter you want to change it to. the new word must be a word in the English dictionary ");


if(input == null) {
System.exit(0);
} // if

// sets word to all lowercase

currentWord = input.toLowerCase();

if(currentWord.length() != 4) {
error = "Please check that the word you entered is four letters. ";
continue;
} else if(isValidWord(currentWord) == false){
error = "Please make sure the word you entered is a valid English word.";
continue;
}else {
break;
}
} while (true);
return currentWord;
}
} // getcurrentWord