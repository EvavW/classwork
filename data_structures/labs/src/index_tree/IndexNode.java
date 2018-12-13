package index_tree;

import java.util.List;
import java.util.ArrayList;


public class IndexNode  {

	// The word for this entry
	String word;
	// The number of occurrences for this word
	int occurences;
	// A list of line numbers for this word.
	List<Integer> list;
	
	
	
	IndexNode left;
	IndexNode right;
	
	
	// Constructors
	// Constructor should take in a word and a line number
	// it should initialize the list and set occurrences to 1
	public IndexNode(String word, int line){
		this.word = word;
		
		this.list = new ArrayList<Integer>();
		this.list.add(line);
		
		this.occurences = 1;
	}
	
	
	
	// Complete This
	// return the word, the number of occurrences, and the lines it appears on.
	// string must be one line
	
	public String toString(){
		if(this.occurences == 1){
			return '"'+this.word+'"' + " occures " + this.occurences + " time at line: "+ this.list;
		}
		else{
		return '"'+this.word+'"' + " occures " + this.occurences + " times at lines: "+ this.list;
		}
	}
	
	
	
}