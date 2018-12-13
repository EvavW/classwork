package guessing_game;

public class Guess {
	
	// instantiated variables
	private double firstNum = 0;
	private double secondNum = 0;
	private double thirdNum = 0;
	private String conclusion = "";
	
	// object with default values
	public Guess() {
	}

	// object with instantiated values
	public Guess(double myFirst, double mySecond, double myThird, String myConclusion){
		this.firstNum = myFirst;
		this.secondNum = mySecond;
		this.thirdNum = myThird;
		this.conclusion = myConclusion;
	}

	// "get" methods
	public double getFirstNum() {
		return this.firstNum;
	}
	
	public double getSecondNum() {
		return this.secondNum;
	}
	
	public double getThirdNum() {
		return this.thirdNum;
	}
	
	public String getConclusion() {
		return this.conclusion;
	}
	
	// "set" methods
	public void setFirstNum(double newFirst){
		this.firstNum = newFirst;
	}
	
	public void setSecondNum(double newSecond){
		this.secondNum = newSecond;
	}
	
	public void setThirdNum(double newThird){
		this.thirdNum = newThird;
	}
	
	public void setConclusion(String newConclusion){
		this.conclusion = newConclusion;
	}
	
	// =======================================
	
	public String toString() {
		return "Guess : " + this.firstNum + " " + this.secondNum + " " + this.thirdNum + " was " + this.conclusion;
	}
	
}

