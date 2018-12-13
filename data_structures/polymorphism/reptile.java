package classroom;

public class Reptile extends Animal{


    public Reptile() {
	name = "ralph"; /* default name for a reptile is ralph */
    }


    public Reptile(String name) {
	super(name);
    }

    public void eat(String thing) { /* sma ename as in the parent (animal) class */
	System.out.println(name + " ate " + thing + " with a crunch.");
	/* redefine default eat verb from 'generically' in animal to crunch for reptile */
    }

    public static void main(String[] args) {
	Animal a = new Animal("Fred");
	a.eat("stick");
    

	Reptile r = new Reptile("George");
	r.eat("bug");
    }


}
