package recursion_games;

public class Hanoi {
	
	public static void solve(int n){
		Stack<Integer> left = new Stack<Integer>();
		Stack<Integer> middle = new Stack<Integer>();
		Stack<Integer> right =   new Stack<Integer>();
		for(int i = n; i >= 1; i--){
			left.push(i);
		}
		display(left,middle,right);
		
		solve(left,middle,right,n);
		
		display(left,middle,right);
	}
	
	public static boolean solve (Stack<Integer> left, Stack<Integer> middle, Stack<Integer> right,int n){
	
		if(n == 1){
			move(left,right);
			display(left,middle,right);
			return true;
		}
	
		else{
			solve(left,right,middle,(n-1));
			
			move(left,right);
		
			display(left,middle,right);
			
			solve(middle,left,right,(n-1));
			
		}
		
		return false;
	}
	
	public static void move(Stack<Integer> current,Stack<Integer> destination){
		destination.push(current.pop());
	}
	
	public static void display (Stack<Integer> left, Stack<Integer> middle, Stack<Integer> right){
		System.out.println("left: " + left);
		System.out.println("midle: " + middle);
		System.out.println("right: " +right);
		System.out.println();
	}

	public static void main(String[] args){
		int n = 3; // n disks
		solve(n);
	}
}
