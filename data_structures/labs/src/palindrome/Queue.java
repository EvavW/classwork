package palindrome;

public class Queue<E> {
	
	private Node<E> front;
	private Node<E> back;

	public Queue() {
		this.front = null;
		this.back  = null;
	}
	
	
	/*
	 * places element in the back of the Queue
	 */
	public void enqueue(E element){
		Node<E> temp = new Node<E>(element);
		// if the queue is empty:
		if(empty()){
			front = temp;
			back = temp;
		}
		// if the queue is not empty:
		else{
			back.next = temp;
			back = temp;
		}
		
	}
	
	/*
	 * remove the front node of the queue and return it
	 */
	public E dequeue(){
		E retval = front.item;
		// if there is only 1 element:
		if(front.next == null){
			front = null;
			back = null;
		}
		// if there is more than 1 element:
		else{
			front = front.next;
		}
		return retval;
	}
	
	/*
	 * Look at the front of the queue and return it, without removing
	 */
	public E peek(){
		return front.item;
	}
	/*
	 * determine if the queue is empty or not
	 */
	public boolean empty(){
		return front == null;
	}
	
	public String toString(){
		Node<E> current = front;
		String out = "";
		while(current != null){
			out = out + current.item.toString() + " ";
			current = current.next;
		}
		
		return out;
	}

}