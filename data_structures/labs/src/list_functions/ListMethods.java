package list_functions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ListMethods<E> {
	
	public static void main(String[] args) {
		List<Integer> test = new ArrayList<Integer>();
		for (int i = 0; i < 10; i ++){
			test.add(i);
		}// for
		
		// test unique method
		test.add(1, 0);
		System.out.println(unique(test));
		
		// test sum method
		System.out.println(sum(test));
		
		// test multiples method
		for (int i = 0; i <allMultiples(test,2).size(); i++){
			System.out.println(allMultiples(test, 2).get(i));
		}
		
		// test stringToListOfWords
		String phrase = "this, is a sentence.";
		List<String> test2  = new ArrayList<String>();
		for(int i = 0; i < stringToListOfWords(phrase).size(); i++){
			System.out.println(stringToListOfWords(phrase).get(i));
			test2.add(stringToListOfWords(phrase).get(i));
		}// for
		
		// test allStringsOfSize
		for (int i = 0; i < allStringsOfSize(test2, 4).size(); i++){
			System.out.println(allStringsOfSize(test2, 4).get(i));
		}
		
		
		// test removeAllInstances
		for (int i =0; i <test.size(); i++ ){
			System.out.println(test.get(i));
			
		}
		System.out.println();
		removeAllInstances(test,test.get(0));
		for (int i =0; i <test.size(); i++ ){
			System.out.println(test.get(i));
		}
		
		}// main
		
	
	public static <E> boolean unique(List<E> list){
		/*
		 * this method checks to see if all of the items in list are unique.
		 */
		for (int i = 0; i <list.size(); i++){ 
			for (int j = 0; j <list.size(); j++){
				if (i != j){
					if (list.get(i).equals(list.get(j))){
					return false; // code will break here if there is a match
				} // if
				}// if
			} // for 
		}// for
		return true; // if code doesn't break in if, return true and break here
	} // unique

	public static double sum(List<Integer> list){
		/*
		 * this method sums all of the integers in a list of integers
		 * returns the sum
		 */
		double sum = 0.0; // declare sum variable
		for (int i = 0; i <list.size(); i++) {
			sum = sum + list.get(i); // add to sum
		}// for
		return sum; // break
	}// sum
	
	public static List<Integer> allMultiples(List<Integer> list, int check){ 
		/*
		 * this method takes a list of integers and an integer. 
		 * all multiples of the integer in the list of integers are added to a 
		 * new list multiples. returns multiples
		 */
		List<Integer> multiples = new ArrayList<Integer>(); // declare list of multiples of in
		for (int i = 0; i <list.size(); i++) {
			if (list.get(i) % check == 0){ // check if item in list is a multiple of int
				multiples.add(list.get(i)); // if yes, add to new list
			}// if
		}// for
		return multiples; // return new list, break
	}// allMultiples
	
	public static List<String> allStringsOfSize(List<String> list, int length){
		/*
		 * this method takes a list of strings and an integer. It finds all strings
		 * in the list whose length matches the int. These strings are added to a new
		 * list ofLength, which is returned
		 */
		List<String> ofLength = new ArrayList<String>(); // declare list for strings of size length
		for (int i = 0; i <list.size(); i++) {
			if (list.get(i).length() == length) { // check length
				ofLength.add(list.get(i)); // if yes, add item to ofLength
			}// if
		}// for
		return ofLength; // return ofLength, break
	}// allStringsOfSize
	
	public static List<String> stringToListOfWords(String phrase){
		/*
		 * take a string and convert it into a list of strings where
		 * each string is a single word
		 * all the words in the list are then sanitized to remove ".,!?" etc. 
		 */
		// declare a list of words. populate the list by splitting phrase by whitespace
		List<String> words = new ArrayList<String>(Arrays.asList(phrase.split("\\s+"))); 
		// sanitize the list
		String replace = ""; // declare string for the sanitized word
		for (int i = 0; i < words.size(); i++) {
			String word  = words.get(i); // get word
			replace = word.replaceAll("\\W$", ""); // sanitize word using regular expression
			words.set(i,replace); // replace the sanitized word in the position of the original word
		}// for
		
		return words; // return words and break
		
	}// stringToListOfWords
	
	public static <E> void removeAllInstances(List<E> list, E item){
		/*
		 *this method removes all instances from a given generic list that match the given item 
		 */
		for (int i = 0; i < list.size();){
			if (list.get(i) == item){
				list.remove(i);
				// if this code is executed, i should not be iterated, since the number of items has decreased.
			}// if
			else {
				i++; // only iterate i if the if block is not terminated. 
			}// else
		}// for
	}// removeAllInstances

	}// class
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
