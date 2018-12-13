package guessing_game;

import common.MyScanner;
import java.util.ArrayList;

public class GuessingGame {

	public static void main(String[] args) {
		/*
		 * Lab 1: Guessing Game
		 * 
		 * This program is a guessing game. Users enter 3 numbers separated by spaced and the program tells the user
		 * whether this set of numbers obeys the secret rule.
		 * The secret rule in this game is that the second number must be a square of the first number and the second
		 * number must be a square of the second number. 
		 * 
		 * This program uses Guess objects, which are defined in the Guess class in this package. 
		 * 
		 * Programmer: Eva von Weltin
		 * Date: 8/31/2017
		 */
		
		// declare MyScanner object to gather for user input. See class MyScanner in the common package.
		MyScanner keyboard = new MyScanner ();
		
		// declare variables
		String guess = ""; // each entry the user makes gets stored initially in this variable
		double firstNum = 0; // the first number entered
		double secondNum = 0; // the second number entered
		double thirdNum = 0; // the third number entered
		double[] nums = new double[100]; // used to convert user input string to an array of doubles
		String conclusion = ""; // the result of the if block determining whether the guess fits the secret rule
		String answer = ""; // stores the user's answer for what the secret rule is
		
		// use generic form to declare an array list of Guess objects
		ArrayList<Guess> guessList = new ArrayList<Guess>();
		
		
		// welcome the user to the game. provide instructions
		System.out.println("Hello, welcome to the Guessing Game. \n"
				+ "The object of the game is figure out the secret rule that determines whether a set of 3 numbers is"
				+ " correct or incorrect.");
		System.out.println("To enter a new guess: enter 3 numbers seperated by spaces.");
		System.out.println("To view all previous guesses, enter 'previous'.");
		System.out.println("When you feel certain that you know the rule, enter 'answer'\n");
		System.out.println("I'll give you a hint: The entry: 1 1 1 is correct.");
		
		/* 
		 * This is the main loop in this program. all user input is handled here. 
		 * Separate if blocks handle different user inputs.
		 * Breaks when the user enters 'answer'
		 */
		while (true){ 
			
			System.out.println("Enter a guess, or type 'previous' or 'answer': "); // prompt user at the beginning of each loop
			
			guess = keyboard.nextString(); // send user input to a string called guess
			
				/*
				 * This if block handles user input in the form of three numbers separated by spaces.
				 * Guess objects are only created if the user input matches this format.
				 * Guess objects are added to the guessList ArrayList
				 */
				if ((!guess.trim().equalsIgnoreCase("previous"))&&(!guess.trim().equalsIgnoreCase("answer"))){
					// create new guess object
					Guess g = new Guess();
				
					/*handle user input by sending space delimited input to a string called delim. 
					 * Split that string by blank spaces into a doubles string called nums, 
					 * and then parse that into doubles.
					 * sort doubles into corresponding variables
					 */
					try {
						
						String[] delim = guess.trim().split(" ");
						nums[0] = Double.parseDouble(delim[0]);
						firstNum = nums[0];
						nums[1] = Double.parseDouble(delim[1]);
						secondNum = nums[1];
						nums[2] = Double.parseDouble(delim[2]);
						thirdNum = nums[2];
					}
					catch (Exception e) // keep program from terminating when the user makes an erroneous input
					{
						System.out.println("Exception encountered: "+e.getMessage());
					}
					
					// determine conclusion
					// logic for the secret rule is defined here
					if (((firstNum * firstNum) == secondNum) && ((secondNum *secondNum)== thirdNum )){
						conclusion = "Correct!";
					}
					else {
						conclusion = "Incorrect.";
					}
					System.out.println(conclusion);
				
					// set guess object values using get methods from the Guess class
					g.setFirstNum(firstNum);
					g.setSecondNum(secondNum);
					g.setThirdNum(thirdNum);
					g.setConclusion(conclusion);
				
					guessList.add(g); // add the complete guess object to the guess list array
				
				} // end guess block
			
				/*
				 * This if block is executed if the user indicates that they would like to see their previous
				 * answers. The conclusion of that answer is also printed. Uses the toString method in the Guess class.
				 */
				if (guess.trim().equalsIgnoreCase("previous")){
					for (int i = 0; i <guessList.size(); i++){ 
						System.out.println(guessList.get(i)); // get automatically looks for any toString method that you may have written
					}
				} // end previous block
				
				/*
				 * This if block is executed if the user indicated that they think they know the secret rule. 
				 * Once the answer variable is populated, the correct answer will be given and the while loop
				 * will break
				 */
				if (guess.trim().equalsIgnoreCase("answer")) {
					System.out.println("Think you've got it? You may enter what you believe the rule of the game to be now.");
				
					answer = keyboard.nextString(); 
					if (!answer.trim().equalsIgnoreCase("")){ 
						System.out.println("The Answer was:");
						System.out.println("	The second number must be a square of the first");
						System.out.println("	and the third number must be a square of the second");
						System.out.println("Your answer was: ");
						System.out.println("	" + answer + "\n");
						System.out.println("Thanks for Playing!");
						System.out.println("Goodbye!");
						break; // break the while loop
						
					}
				}
			
		} // end while loop
	
		
		// Housekeeping: close the keyboard object to prevent memory leaks.
		keyboard.close();
		
		// final print line
		System.out.println();
	}

}
