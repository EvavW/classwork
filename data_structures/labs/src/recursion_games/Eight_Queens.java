package recursion_games;

import java.util.Arrays;

public class Eight_Queens {
	
	public static void solve(int[][] board){
		solve(board,0);
}

	public static boolean solve(int[][] board, int col){
		if(col >= board.length){
			return true;
		}
	
		for(int row =0; row <board.length; row++){
			if(canPlace(board,row,col)   ){
				board[row][col] = 1;
				if(solve(board,col+1)){
					return true;
				}
				board[row][col] = 0;
			}
		}
	
		return false;
	}
		
	public static boolean canPlace(int[][] board, int row, int col){
		return (checkRow(board,row,col) && 
				checkCol(board,row,col) && 
				checkDiag(board,row,col));
			
	}
		
	private static boolean checkCol(int[][] board, int row, int col) {
		for(int i = 0; i <board.length; i++){
			if(board[i][col] == 1){
				return false;
			}
	
		}
	
		return true;
	}
	private static boolean checkRow(int[][] board, int row, int col) {
		for(int i = 0; i <board.length; i++){
			if(board[row][i] == 1){
				return false;
				}
		}
	
		return true;
	}
	private static boolean checkDiag(int[][] board, int row, int col) {
		if(row ==0 && col == 0){
			return true;
		}
		int i = row;
		int j = col;
		while(i >=0 && j >=0){
			if(board[i][j]==1){
				return false;
			}
			i--;
			j--;
		}
		i = row;
		j = col;
		while(i <=(board.length-1) && j >=0){
			if(board[i][j]==1){
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
	
	public static void main(String[] args) {
		int[][] board = new int[8][8];
		
	
		solve(board);
		
		for (int[] row : board){
			System.out.println(Arrays.toString(row));
		}
			

	}

}
