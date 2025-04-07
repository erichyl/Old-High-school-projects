/*-
 *NAME:		E. Liu
 *DATE:		Oct. 5th 2021
 *EXERCISE:	CodeBreaker.java
 *PURPOSE:	Break a caesar cipher encryption, displaying top 3 decryptions
 */
import java.io.*;

public class CodeBreaker {
	public static void main (String [] args) {
		String [] input = getFileContents("cipher.txt");
		decode(input);
	} // main
	
	/**
	 * decodes the caesar cipher
	 * displays top 3 decryptions to console
	 * 
	 * @param s		input from file
	 */
	public static void decode (String [] s) {
		int [] best = new int [3];
		String [][] allShifts = new String [26][s.length];
		int [] scores = new int [26];
		int place = 0;
		int highScore = 0;
		int index = 0;
		
		/* get all 26 shifts of the input including the original */
		/* and store it in the 2D string array allShifts */
		for (int j = 0; j < 26; j++) {
			for (int i = 0; i < s.length; i++) {
				allShifts[j][i] = shift(s[i], j + 1);
			}
		}
		
		/* assess every shift of the input and store it's score */
		/* in the corresponding slot of the integer array score */
		for (int j = 0; j < allShifts.length; j++) {
			for (int i = 0; i < allShifts[j].length; i++) {
			}
			scores[j] = assessShift(allShifts[j]);
		}
		
		/* find the 3 shifts that have the highest score */
		/* and store their shift number in the integer array best */
		while (place < 3) {
			index = 0;
			for (int i = 0; i < 26; i++) {
				if (scores[i] > highScore) {
					highScore = scores[i];
					index = i;
				}
			}
			
			/* save the highest score set that score to 0 to avoid recounting */
			/* reset highScore */
			best[place] = index;
			scores[index] = 0; 
			highScore = 0;
			place++;
		}
		
		/* print out the top 3 results */
		for (int i = 0; i < best.length; i++) {
			for (int j = 0; j < s.length; j++) {
				System.out.println(allShifts[best[i]][j]);
			}
			System.out.println();
		}
	} // decode
	
	/**
	 * assesses a shift of the caesar cipher
	 * and gives it a score
	 * 
	 * @param shift		a shift of the input
	 * @return score    score given to the shift
	 */
	public static int assessShift (String [] shift) {
		int score = 0;
		int vowels = 0;
		int total = 0;
		int index = 0;
		
		/* 2 letter combinations worth 3 points */
		String [] three = {"ss", "tt", "ff", "ee", "ll", "th", "oo",
				"er", "es", "an", "re", "ar", "as", "in", "ed", "pi",
				"nd", "at", "en", "is", "it", "io", "st", "of", "ou",
				"ti", "to", "ea", "rt", "nt", "ot"};
		
		/* 2 letter combinations worth 2 points */
		String [] two = {
				"ab", "ac", "ad", "af", "ag", "ah", "al", "am", "ap", 
				"bi", "bl", "bo", "br", "bu", "ca", "ce", "ch", "ci", 
				"ck", "co", "ct", "cy", "da", "de", "do", "ba", "be", 
				"dr", "ds", "du", "dy", "eb", "ef", "eg", "el", "em", 
				"fi", "fl", "fo", "fr", "ga", "ge", "gl", "fa", "fe",
				"go", "gy", "he", "ho", "ib", "ic", "id", "lt", "sp",
				"if", "ig", "il", "im", "ip", "ir", "ep", "et", "os",
				"ke", "ki", "ky", "la", "le", "li", "ly", "ma", "me",
				"mo", "na", "ne", "ng", "ni", "no", "ns", "nt", "ny",
				"pa", "pe", "ph", "pl", "po", "pr", "py", "oa", "ia",
				"ra", "ri", "rk", "rl", "ro", "rs", "ry", "ob", "od",
				"sa", "se", "sh", "si", "so", "sy", "ta", "te", "og",
				"to", "tr", "ty", "lo", "ol", "ur", "ts", "om", "on",
				"un", "us", "rd", "gg", "bb", "ut", "rn", "rg", "or",
				"dd", "rr", "ai", "nn", "cr", "ys", "ld", "ls", "mm"};
		
		/* 2 letter combinations worth 1 point */
		String [] one = {"ak", "au", "av", "aw", "ax", "mu", "nk",
				"bs", "cc", "cs", "cu", "ec", "ei", "ek", "gh", "gi",
				"eu", "ev", "ew", "ex", "ey", "fs", "ft", "fu", "fy",
				"gs", "gu", "hy", "ie", "iv", "cl", "gr", "xy", "ha",
				"ko", "ks", "lu", "mb", "mi", "mp", "ms", "mt", "zz",
				"oi", "ok", "op", "oy", "pp", "ps", "nu", "oc", "su",
				"pu", "rm", "rp", "ru", "sk", "sl", "sm", "sn", "ye",
				"ug", "ul", "um", "up", "aq", "aj", "ae", "tu", "ub",
				"bn", "bj", "bt", "dg", "dm", "dv", "eh", "eq", "eo", 
				"gn", "ht", "hu", "ik", "ka", "kl", "kn", "lb", "yl",
				"lf", "lg", "lk", "lm", "ln", "lp", "my", "nc", "hy",
				"nl", "nn", "nv", "ow", "pt", "rb", "rf", "rv", "sc",
				"sr", "tc", "ua", "uc", "ud", "uf", "ui", "va", "vo",
				"wa", "we", "wn", "wo", "xe", "xt"};
		
		/* 3 letter combinations worth 1 additional point */
		String [] triple = {"the", "and", "tha", "ent", "ion", "tio", "ger",
				"for", "end", "has", "nce", "tis", "oft", "sth", "men",
				"con", "sub", "sel", "ing", "ont", "ter", "tor", "per"};
		
		/* letter combinations do not exist in the English language */
		String [] nopes = {"bx", "cf", "cg", "cj", "cp", "zt", "zx",
				"cv", "cw", "cx", "dx", "fj", "fq", "fv", "fx", "fz",
				"gj", "gq", "gv", "gx", "hx", "jb", "jc", "jd", "jf",
				"jg", "jh", "jj", "jk", "jl", "jm", "jn", "jp", "jq",
				"js", "jt", "jv", "jw", "jx", "jy", "jz", "kq", "kx",
				"kz", "mq", "mx", "pq", "pv", "px", "qb", "qc", "qd",
				"qf", "qg", "qh", "qj", "qk", "ql", "qm", "qn", "qo",
				"qp", "qq", "qr", "qt", "qv", "qw", "qx", "qy", "qz",
				"rx", "sx", "sz", "tx", "vb", "vc", "vd", "vf", "vh",
				"vj", "vk", "vm", "vp", "vq", "vt", "vw", "vx", "wx",
				"yq", "zj", "zn", "zr", " q ", " w ", " e ", " r ",
				" t ", " y ", " o ", " p ", " s ", " d ", " f ",
				" h ", " j ", " k ", " l ", " z ", " x ", " c ",
				" v ", " b ", " n ", " m ", " u ", " g "};
		
		/* counts number of vowels and characters */
		for (int i = 0; i < shift.length; i++) {
			for (int j = 0; j < shift[i].length() - 1; j++) {
				if (shift[i].substring(j, j+1).equals("a") ||
					shift[i].substring(j, j+1).equals("e") ||
					shift[i].substring(j, j+1).equals("i") ||
					shift[i].substring(j, j+1).equals("o") ||
					shift[i].substring(j, j+1).equals("u") ||
					shift[i].substring(j, j+1).equals("y")) {
					vowels++;
				}
				total++;
			}
		}
		
		/* if there isn't one vowel for every 5 letters */
		/* give the shift a score of 0 */
		if (vowels < (total / 5.0)) {
			return 0;
		}
		
		/* test for the contents within the 5 arrays */
		for (int i = 0; i < shift.length; i++) {
			/* test for invalid letter combinations */
			/* if found give the shift a score of 0 */
			for (int j = 0; j < nopes.length; j++) {
				if (shift[i].contains(nopes[j])) {
					return 0;
				}
			}
			
			/* test for 3 point 2 letter combinations */
			/* if found add 3 point for each instance */
			for (int j = 0; j < three.length; j++) {
				while (shift[i].indexOf(three[j], index) != -1) {
					score += 3;
					index = shift[i].indexOf(three[j], index) + 1;
				}
				index = 0;
			}
			
			/* test for 2 point 2 letter combinations */
			/* if found add 2 point for each instance */
			for (int j = 0; j < two.length; j++) {
				while (shift[i].indexOf(two[j], index) != -1) {
					score += 2;
					index = shift[i].indexOf(two[j], index) + 1;
				}
				index = 0;
			}
			
			/* test for 1 point 2 letter combinations */
			/* if found add 1 point for each instance */
			for (int j = 0; j < one.length; j++) {
				while (shift[i].indexOf(one[j], index) != -1) {
					score += 1;
					index = shift[i].indexOf(one[j], index) + 1;
				}
				index = 0;
			}
			
			/* test for 1 point 3 letter combinations */
			/* if found add 1 point for each instance */
			for (int j = 0; j < triple.length; j++) {
				while (shift[i].indexOf(triple[j], index) != -1) {
					score += 1;
					index = shift[i].indexOf(triple[j], index) + 1;
				}
				index = 0;
			}
		}
		return score;
	} // assessShift
	
	/**
	 * shift the letters within the string by a specified amount
	 * 
	 * @param input 	the string that is to be shifted
	 * @param shift		number of places to shift the letters
	 * @return c		returns the shifted character array as a string
	 */
	public static String shift (String input, int shift) {
	    char [] c = input.toLowerCase().toCharArray();
	   
	    for (int i = 0; i < c.length; i++) {
	    	/* check to make sure character is a letter */
		    if (c[i] >= 97 && c[i] <= 122) {
		    	if (c[i] + shift > 122) {
		    		c[i] -= 26;
		    	}
		    	c[i] += shift;
		    }
	    } // iterate through char array
	   
	    return new String(c);
	} // shift
	
	/**
	 * retrieves the specified file from you bin folder
	 * and returns it's contents as a string array
	 * 
	 * @param fileName		name of the file
	 * @return contents		a string array containing the file contents
	 */
	public static String [] getFileContents (String fileName) {
		String [] contents = null;
		int length = 0;
		
		/* attempt to locate specified file */
		try {
			String folderName = "/subFolder/";
			
			InputStream input = CodeBreaker.class.getResourceAsStream(folderName + fileName);
			if (input == null) {
				input = CodeBreaker.class.getClassLoader().getResourceAsStream(fileName);
			}
			BufferedReader in = new BufferedReader(new InputStreamReader(input));
			
			in.mark(Short.MAX_VALUE);
			
			/* count number of lines file contains */
			/* then create a string array of the same size */
			while (in.readLine() != null) {
				length++;
			}
			in.reset();
			contents = new String[length];
			
			/* store the input in contents using BufferedReader */
			for (int i = 0; i < length; i++) {
				contents[i] = in.readLine();
			}
			in.close();
		} catch (Exception e) {
			System.out.println("File Input Error");
		}
		return contents;
	} // getFileContents
} // CodeBreaker
