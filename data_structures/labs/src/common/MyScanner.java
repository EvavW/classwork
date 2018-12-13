package common;

import java.util.Scanner;

/* MyScanner is a "wrapper class" for java.util.Scanner. 
 * 
 * The problem with Scanner is that it does not advance to the next 
 * line in the input stream after it gets numeric data (as most people
 * would expect it to do).
 * 
 * MyScanner fixes this problem by "redefining" the way that nextInt()
 * and nextDouble() work. In MyScanner, they do advance to the next 
 * line in the input stream after reading the numeric data.
 * 
 *   nextDouble(): get a double value from the user then advance to the 
 *     next line in the input stream.
 *   nextInt(): get an int value from the user then advance to the 
 *     next line in the input stream.
 *   nextString(): return a string containing all the character data
 *     on the line (and advance to the next line in the input stream).
 *   close(): close out the private Scanner object so that there are
 *     no memory leaks.
 * 
 */

public class MyScanner {

	// private data member (Scanner object) for providing user 
		// input. This object is used by all the methods.
		private Scanner keyboard = null; 
		
		public MyScanner () {
			// instantiate object "keyboard" as a new Scanner object
			keyboard = new Scanner (System.in);
		}
		
		// get a double value (real number) from the user then advance the 
		// input stream to the next line. Return the double value.
		public double nextDouble() {
			double d = keyboard.nextDouble();
			
			// advance to the next line in the input stream
			String disregard = keyboard.nextLine(); 
			return d;
		}
		
		public double nextDouble(String prompt){
			double f = -66666; // this should never be returned
			boolean bad = true;
			while (bad) { 
					try{
						System.out.print(prompt);;
						f = keyboard.nextDouble();
						//advance to the next line in the input stream
						String disregard = keyboard.nextLine();
						bad = false;
					}catch (Exception e ){
						// advance to the next line in the input stream
						String disregard = keyboard.nextLine();
						System.out.println("That is not an double. Please try again...");
					}
				}// while loop
				return f;
		} // method
		
		// get an int value (integer) from the user then advance the input 
		// stream to the next line. Return the int value.
		public int nextInt() {
			int i = keyboard.nextInt();
			
			// advance to the next line in the input stream
			String disregard = keyboard.nextLine(); 
			return i;
		}
		//get an integer value from the user then advance the input
		// stream to the next line. Return the integer value. If the user does
		// not enter a valid integer, keep asking the user to enter
		public int nextInt(String prompt){
			int i = -99999; // this should never be returned (is always overwritten)
			boolean bad = true;
			while(bad){
					try{
						System.out.print(prompt);
						i = keyboard.nextInt();
						// advance to the next line in the input stream
						String disregard = keyboard.nextLine();
						bad = false;
					}catch(Exception e){
						// advance to the next line in the input stream
						String disregard = keyboard.nextLine();
						System.out.println("That is not an integer. Please try again...");
					}
				}// while loop
				return i;
		}// method
		
		// read all the character data on the current line, advancing to the 
		// next line in the input stream, then return that character data 
		// (in a String object). 
		public String nextString() {
			String s = keyboard.nextLine(); // read and return all the character data from the current line
			
			return s;
		}
		
		public void close() {
			keyboard.close();
		}

	}
