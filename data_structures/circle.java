package review;

public class Circle { /* final means that the class cannot be extended */

    private double radius;
    public static final double PI = 3.14159; /* now no created circle owns it owns version of Pi because the variable is static. startic variables areshared by the entire class */

    public Circle(double radius) {
	this.radius = radis;
    }

    public String toString() { /* overradie the java toString method */
	return "Circle [radius=" + radius + "]";
    }

    public double getArea() {
	return PI*this.radius*this.radius;

    }
    
    public static void main(String[] args) {
       Circle c = new Circle(5);
       System.out.println(c);

       /*       List list = new ArrayList(); this won't really work. use the generic directly below. */
       List<Circle> list = new ArrayList<Circle>(); /* tells you that this is a list of circles */

       
       List<Integer> l2 = new ArrayList<Integer>(); /* making a list of integersyou need to use a wrapper class, below */
       int myOtherInt = 3;
       Integer myInt = myOtherInt;
       
       for(int i = 0; i <1000); i++) {
	Circle c = new Circle(i);
	list.add(c); /* 0.c would always add to the beginning of the list */

    }

    for(int i = 0; i <list.size(); i++) { /* .size not .length! */

	Circle c = list.get(i);
	System.out.println(list.get(i)); /* just pritning area */

	/*	Cicrcle c=list.get(i); you can't do this because it does not know that this is a list of circles. it just knows it is a list. period. */
	/* Circle c = (Circle) list.get(i); this also won't work because you cannot make a list into a circle in java because it is a strongly typed language. to get around this, we use generics to specificy what the list can hold */
	System.out.println(c.getArea());

    }
    
 }

	   
	

    

}
