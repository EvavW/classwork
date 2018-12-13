package guessing_game;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		Scanner Scanner = new Scanner(System.in);

		double d = 0.0;
		System.out.println("Do it");
		d = Scanner.nextDouble();
		
		System.out.println(d*2);
		
		Scanner.close();
		
		List<Integer> list = new ArrayList<Integer>();
		for (int i = 0; i < 10; i ++){
			list.add(i);
		}// for
	
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		
		for (int i = 0; i < list.size(); i++){
			if (list.get(i) > max){
				max = list.get(i);
			}
			if (list.get(i) < min){
				min = list.get(i);
			}
		}
		System.out.println("min : " + min + " max: " + max);
		
		List<String> list2 = new ArrayList<String>();
		
		String prefix = "fuck";
		
		list2.add(0,"helloworld");
		list2.add(1,"helloworld");
		list2.add(2,"helloworld");
		list2.add(3,"helloworld");
		list2.add(4,"helloworld");
		list2.add(5,"fuckthis");
		list2.add(6,prefix);
		
		//System.out.println(list2);
		System.out.println(list2);
		for (int j = 0; j < list2.size();j++){
			if (list2.get(j).substring(0,prefix.length()) == prefix){
				System.out.println(list2.get(j));
				list2.remove(j);
				j--;
			}
			else{
				
				j++;
			}
		}
		System.out.println(list2);
	
		//System.out.println(list2);
	
	
	}
	

	


}
