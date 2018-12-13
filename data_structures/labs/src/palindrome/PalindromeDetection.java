package palindrome;

import common.MyScanner;
import java.util.ArrayList;
import java.util.List;
/*
 * This program allows a user to enter a series of words and test to see if each word is a palindrome.
 * Eva von Weltin
 * Data Structures
 * 10/12/217
 * 
 */


public class PalindromeDetection<E> {

	public static void main(String[] args) {
		
		// declare variables
		MyScanner keyboard = new MyScanner (); // scanner object
		Stack<String> stack =  new Stack<String>(); // initialize stack
		Queue<String> queue = new Queue<String>(); // initialize queue
		boolean quit = false; //boolean to end user input
		boolean isPalindrome = false; // boolean to return palindrome decision
		String words = "";
		
			
		while (quit == false){
			String word = ""; // string for user input
			System.out.println("Enter any word and I will tell you if it is a palindrome.");
			System.out.println("When you're finished, type 'quit'");
			word = keyboard.nextString();
			if (word.equals("quit")){
				// end the loop when the user enters 'quit'
				quit = false;
				System.out.println("Goodbye");
				System.out.println("Palindromes:");
				System.out.println(words);
				break;
			}
			//sanitize the string
			word = word.replaceAll("[^a-zA-Z ]", "");
			word = word.replaceAll("\\W$", "");
			word  = word.replaceAll("\\s","");
			System.out.println(word);
			// push each letter in the word to the top of the stack and the bottom of the queue
			for (int i = 0; i < word.length(); i++){
				stack.push(word.substring(i,i+1));
				queue.enqueue(word.substring(i,i+1));
			}
			
			//compare each element of the queue to each element of the stack
			while(stack.empty() == false){	
				if(stack.pop().equalsIgnoreCase(queue.dequeue())){
				isPalindrome = true;
				}
				// as soon as a mismatch is detected, return negative decision
				else{
					isPalindrome = false;
					System.out.println("The entered word is not a palindrome");
					System.out.println();
					break;
				}
			}
				// if the entire stack was emptied without returning false; it must be true
				if(isPalindrome == true){
					System.out.println("The entered word is a palindrome");
					System.out.println();
					// add word to words
					words = (words + word + "\n");
				}
		}
		
		
	keyboard.close(); //housekeeping	
	}

}


