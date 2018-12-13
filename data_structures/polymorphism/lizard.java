ackage classroom;

public class Lizard extends Reptile {

    public Lizard() {
	this.name = "Lizzy";
    }

    public void move() {
	
	System.out.println(this.name + " scurried.");
    }

    public void eat(String thig) {
	System.out.println(this.name + " ambushed and ate " +  thing);
    }



    public static void main(String[] args ) {

	Lizard l - new Lizard();
	l.move();
	l.eat(" a smaller lizard b");



	Animal a = new Lizard(); /* this is totally ok */
	a.move(); /* what gets printed out? there is no move method in reptile but there is a move method in lizard. so wil it move "normall" as it is in animal? or will it scurry? 

It will scurry, because it is an animal, but is is also a lizard*/
	

	Animal[] zoo = new Animal[10];

	zoo[0] = new Animal("Earl the Elephant"); /* this will work because animal is less specific than lizard or reptile */

	zoo[1] = new Reptile();
	zoo[2] = new Lizard();

	z00[0].eat(" leaves and stuff"); /* needs input */
	zoo[1].move(); /* does not need input */
	zoo[2].move(); /* does not need input */

    }
