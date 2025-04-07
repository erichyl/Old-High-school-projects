/***********************
 * @author (Eric Liu)
 * @version (2020-04-14)
 **********************/
import javax.swing.JOptionPane;
import java.io.*;
public class LetterGame {
	public static void main(String [] args){ 
		//variables
		int numWords = 0; //turn counter
		boolean player = true; // which player
		String startWord = ""; 
		String endWord = "";
		
		String [] dictionary = getFileContents("dictionary.txt"); // list of words
		String error = "";
		
		
		do { //error check for getting starting word
		startWord = JOptionPane.showInputDialog(error + " Player 1: Please enter a 4 letter word from the english dictionary, this will be the starting word.");
		
		//if they clicked cancel
			if (startWord == null) {
      			System.out.println("You clicked cancel");
       	    	System.exit(0);
       		 }
        //change letters to lower case
			startWord = startWord.toLowerCase();
			
			if(startWord.length() != 4) {
				error = "Your word did not have 4 letters\n";
				continue;
			}
			
			if(startWord.contains(" ")) {
				error = "Your word should not contain a space\n";
				continue;
			}
			//make sure word exists in 4 letter dictionary
			if(checkDictionary(startWord, dictionary)) {
				break;
			}else {
				error = "Your word is not within the 4 letter english dictionary\n";
				continue;
			} 
		
		}while(true);
		System.out.println(startWord);
		
		
		error = "";
		do { // error check for getting ending word
			endWord = JOptionPane.showInputDialog(error + " Player 2: Please enter a 4 letter word from the english dictionary, this will be the ending word.");
			
			//check if user clicked cancel
			if (endWord == null) {
      	        System.out.println("You clicked cancel");
     	   	    System.exit(0);
      	    }
			// change to lowercase
      	    endWord = endWord.toLowerCase();
      	    
      	    if(endWord.length() != 4) {
				error = "Your word did not have 4 letters\n";
				continue;
			}
      	    if(endWord.contains(" ")) {
				error = "Your word should not contain a space\n";
				continue;
			}
      	    //check if word exists within 4 letter dictionary
			if(checkDictionary(endWord, dictionary)) {
				break;
			}else {
				error = "Your word is not within the 4 letter english dictionary\n";
				continue;
			} 
		}while(true);
		
		
        String input = startWord;
        int p = 0; //player
        
		while(!input.equals(endWord)) { //keeps going while the playing word does not equal endWord
		if(player == true) {
			p = 1;
		}else {
			p = 2;
		}
		input = getInput(p, input, dictionary); //gets instructions and changes word
		System.out.println(input);
		numWords++; // counter adds one
		player = !player; //switches to other player
		}
		
		
		System.out.println("Player " + p + " won in " + numWords + " step(s)!"); //print results
	}
	
	public static boolean checkDictionary(String word, String d []){ //check if word is in 4 letter dictionary
		for(String s : d){	//for each string in array d
			if(s.contains(word)){ //if one string contains the 4 letter word
				return true; // then return as true
			}
		}
		return false; //else return as false
	}
	
	public static String getInput(int player, String word, String d[]){
		String error = "";
		do{ // error check
		String input = JOptionPane.showInputDialog(error + "Player " + player + ": Please enter a 3 character modification \n"
				+ "enter the index of the letter you want to change(0-3), followed by a space, and then the letter you wish to change it to.\n"
				+ "The new word must be a word within the 4 letter english dictionary. exampled of modification: 0 d");
		if (input == null) {
            System.out.println("You clicked cancel");
            System.exit(0);
        }
		input = input.toLowerCase();
        //check if index is within boundaries
		if(input.length() != 3) {
			error = "Check the amount of characters you have.\n";
			continue;
		}
		if(Integer.parseInt(input.substring(0, 1)) < 0 || Integer.parseInt(input.substring(0, 1)) > 3) {
			error = "The index " + Integer.parseInt(input.substring(0, 1)) + " does not exist within a four letter word.\n";
			continue;
		}
		if(!(input.substring(1, 2).equals(" "))) {
			error = "Check if you have a space in between your number and character.\n";
			continue;
		}
		if((int)input.charAt(2) < 97 || (int)input.charAt(2) > 122) {
			error = "Invalid character.\n";
			continue;
		}
		
        String changedword = makeChange(input, word, d); //make the change to the word
        if(changedword.equals("error")){ // if the changed word isn't a valid 4 letter word, re-enter a modification and retry
        	error = "The word you changed it to does not exist.\n";
        	continue;
        }else{
        	return changedword; // if everything works, return the new word
        }
        }while(true);
	}
	
	public static String makeChange(String s, String w, String d[]){ //make the indicated change
		int index = Integer.parseInt(s.substring(0, 1)); //get the index that changes
		char [] word = w.toCharArray(); // changes word to char array
		word[index] = s.charAt(2); //changes replaces the letter at index with new letter
		String newWord = new String (word); // reverts char array back into string
		if(checkDictionary(newWord, d) == true){ // check if word exists in dictionary
			return newWord;
		}
		return "error"; //if it doesn't return error
	}
	
	public static String [] getFileContents(String fileName){ // copied from FileInputOutput
        String [] contents = null;
        
        int length = 0;
        try {

           // input
           String folderName = "/subFolder/"; // if the file is contained in the same folder as the .class file, make this equal to the empty string
           String resource = fileName;

			// this is the path within the jar file
			InputStream input = LetterGame.class.getResourceAsStream(folderName + resource);
			if (input == null) {
				// this is how we load file within editor (eg eclipse)
				input = LetterGame.class.getClassLoader().getResourceAsStream(resource);
			}
			BufferedReader in = new BufferedReader(new InputStreamReader(input));
           
           in.mark(Short.MAX_VALUE);  // see api

           // count number of lines in file
           while (in.readLine() != null) {
             length++;
           }

           in.reset(); // rewind the reader to the start of file
           contents = new String[length]; // give size to contents array

           // read in contents of file and print to screen
           for (int i = 0; i < length; i++) {
             contents[i] = in.readLine();
           }
           in.close();
       } catch (Exception e) {
           System.out.println("File Input Error");
       }
       return contents;

    } // getFileContents
} // LetterGame