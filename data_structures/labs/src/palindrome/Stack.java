package palindrome;

public class Stack<E> {
	
	private Node<E> top;

	public Stack() {
		this.top =null;
	}
	
	
	/*
	 * places element on the top of the stack
	 */
	public void push(E element){
		Node<E> temp = new Node(element);
		temp.next = top;
		top = temp;
	}
	
	/*
	 * remove the top node and return its contents
	 */
	public E pop(){
		E retval = top.item;
		top = top.next;
		return retval;
	}
	
	/*
	 * Look at the top element of the Stack and return it, without removing
	 */
	public E peek(){
		return top.item;
	}
	
	/*
	 * determine if the stack is empty or not
	 */
	public boolean empty(){
		return top == null;
	}
	
	public String toString(){
		Node<E> current = top;
		String out = "";
		while(current != null){
			out = out + current.item.toString() + " ";
			current = current.next;
		}
		
		return out;
	}

}
