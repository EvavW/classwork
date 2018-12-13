package index_tree;

import java.io.*;
import java.util.Scanner;

//Your class. Notice how it has no generics.
//This is because we use generics when we have no idea what kind of data we are getting
//Here we know we are getting two pieces of data:  a string and a line number
public class IndexTree {

	// This is your root 
	// again, your root does not use generics because you know your nodes
	// hold strings, an int, and a list of integers
	private IndexNode root;
	
	// Make your constructor
	// It doesn't need to do anything
	public IndexTree(){
		
	}
	// complete the methods below
	
	// this is your wrapper method
	// it takes in two pieces of data rather than one
	// call your recursive add method
	public void add(String word, int lineNumber){
		this.root = add(this.root, word, lineNumber);
	}
	
	// your recursive method for add
	// Think about how this is slightly different the the regular add method
	// When you add the word to the index, if it already exists, 
	// you want to  add it to the IndexNode that already exists
	// otherwise make a new indexNode
	private IndexNode add(IndexNode root, String word, int lineNumber){
		if(root == null){
			return  new IndexNode(word,lineNumber);
		}
		else if(word.compareTo(root.word)== 0){
			root.list.add(lineNumber);
			root.occurences ++;
			return root;
		}
		else if(word.compareTo(root.word)< 0){
			if(root.left != null){
				if(word.compareTo(root.left.word)==0){
					root.left.list.add(lineNumber);
					root.left.occurences ++;
					return root;
				}
			}
			root.left = add(root.left,word,lineNumber);
			return root;
		}
		else {
			if(root.right != null){
				if(word.compareTo(root.right.word) == 0){
					root.right.list.add(lineNumber);
					root.right.occurences ++;
					return root;
				}
			}
			root.right = add(root.right,word,lineNumber);
			return root;
		}
	}
	
	
	// returns true if the word is in the index
	public boolean contains(IndexNode root,String word){
		
		if(root == null){
			return false;
		}
		else if(word.compareTo(root.word)== 0){
			return true;
		}
		else if(word.compareTo(root.word)< 0){
			return contains(root.left,word);
		}
		else{
			return contains(root.right,word);
		}
	}
	
	// call your recursive method
	// use book as guide
	public void delete(String word){
		this.root = delete(this.root,word);
	}
	
	// your recursive case
	// remove the word and all the entries for the word
	// This should be no different than the regular technique.
	private IndexNode delete(IndexNode root, String word){
		if(root == null){
			return null;
		}
		if(word.compareTo(root.word) < 0){
			root.left = delete(root.left,word);
			return root;
		}
		else if(word.compareTo(root.word) > 0){
			root.right = delete(root.right, word);
			return root;
		}
		else{
			if(root.left == null && root.right == null){
				return null;
			}
			else if(root.left != null && root.right == null){
				return root.left;
			}
			else if(root.left == null && root.right != null){
				return root.right;
			}
			else{
				if(root.left.right == null){
					IndexNode pred = root.left;
					pred.right = root.right;
					return pred;
				}
				else{
					
				IndexNode parent =  root.left;
				IndexNode pred = parent.right;
				while(pred.right != null){
					pred = pred.right;
					parent = parent.right;
				}
				
				root.word = pred.word;
				parent.right = pred.left;
				return root;
				}
			}
		}
	}
	// prints all the words in the index in inorder order
	// To successfully print it out
	// this should print out each word followed by the number 
	// of occurrences and the list of all occurrences
	// each word and its data gets its own line
	public void printIndex(){
		StringBuilder out = new StringBuilder();
		inorderTraverse(root, out);
		System.out.println(out);
		
	}
	
	private void inorderTraverse(IndexNode root, StringBuilder out){
		if (root == null){
			//out.append("null\n");
		}
		else{
			inorderTraverse(root.left,out);
			out.append(root.toString());
			out.append("\n");
			inorderTraverse(root.right, out);
		}
	}

	public static void main(String[] args){
		IndexTree index = new IndexTree();
		// add all the words to the tree
		String fileName = "pg100.txt";
	
		try {
			Scanner scanner = new Scanner(new File(fileName));
			int lineNumber = 1;
			while(scanner.hasNextLine()){
				String line = scanner.nextLine();
				//System.out.println(line);
				String[] words = line.split("\\s+");
				for(String word : words){
					word = word.replaceAll(":", "");
					word = word.replaceAll(",", "");
					word = word.replaceAll("\\s+", "");
					word = word.replaceAll("[^a-zA-Z ]", "");
					word = word.replaceAll("\\W$", "");
					word  = word.replaceAll("\\s","");
					word = word.toLowerCase();
					if (word.equals("")){
						break;
					}
					//System.out.println("word: " + word);
					index.add(word, lineNumber);
				}
				lineNumber++;
			}
			scanner.close();
			
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
		
		/*
		index.add("e", 1);
		index.add("e", 2);
		index.add("b", 3);
		index.add("b", 4);
		index.add("a", 5);
		index.add("a", 6);
		index.add("c", 7);
		index.add("c", 8);
		index.add("g", 9);
		index.add("g", 10);
		index.add("f", 11);
		index.add("f" ,12);
		index.add("h", 13);
		index.add("h", 14);
		
		*/
		/*
		System.out.println("root: " + index.root);
		System.out.println("root.left: " +index.root.left);
		System.out.println("root.left.left: " + index.root.left.left);
		System.out.println("root.left.right: " + index.root.left.right);
		System.out.println("root.right: " + index.root.right);
		System.out.println("root.right.left: " +index.root.right.left);
		System.out.println("root.right.right: " + index.root.right.right);
		System.out.println();
		*/
		
		
		// print out the index
		index.printIndex();
		
		// test removing a word from the index
		index.delete("yonder");
		//index.printIndex();
		
		//System.out.println(index.contains(index.root,"the"));
		index.printIndex();
		/*
		System.out.println("root: " + index.root);
		System.out.println("root.left: " +index.root.left);
		System.out.println("root.left.left: " + index.root.left.left);
		System.out.println("root.left.right: " + index.root.left.right);
		System.out.println("root.right: " + index.root.right);
		System.out.println("root.right.left: " +index.root.right.left);
		System.out.println("root.right.right: " + index.root.right.right);
		System.out.println();
		System.out.println(index.contains(index.root,"the"));
		*/
	}
}
