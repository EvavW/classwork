package classroom;

public class Animal {

    protected String name; /* prive to myself and all the subclass */
    private double size;

    public Animal() {
	name = "Unnamed";
    }

    public Animal (String name) {

	this.name = name;
    }

    public void eat(String thing) {

	System.out.println(name + " ate " + thing + " generically.");

    }

    public void move() {
	
	System.out.println(name + " moved kinda normally.");

    }



}
