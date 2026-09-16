#include <iostream>
#include "myStack.h"

using namespace std;

/*
 * Constructor
 * Usage: myStack(maxSz);
 * -------------------------
 * A new stack variable is initialized.  The initialized
 * stack is made empty.  maxSz is used to determine the
 * maximum number of character that can be held in the
 * stack.
 */

myStack::myStack(int maxSz) {
	maxSize = maxSz;
	//-1 since top being 0 is an index and can be confusing to implement isEmpty()
	top = -1;
	contents = new int[maxSize];
}


/* Destructor
 * Usage: delete ptr
 * -----------------------
 * This frees all memory associated with the stack.
 */

myStack::~myStack() {
	delete[] contents;
}

/*
 * Functions: push, pop
 * Usage: s1.push(element); element = s1.pop();
 * --------------------------------------------
 * These are the fundamental stack operations that add an element to
 * the top of the stack and remove an element from the top of the stack.
 * A call to pop on an empty stack or to push on a full stack
 * is an error.  Make use of isEmpty()/isFull() (see below)
 * to avoid these errors.
 */

void myStack::push(int element) {
	if (isFull()) {
		cerr << "Error: Stack overflow. Cannot push to a full stack." << endl;
		return;
	}
	top++;
	contents[top] = element;
}

int myStack::pop() {
	if (isEmpty()){
		cerr << "Error: Stack underflow. Cannot pop from a empty stack." << endl;
		return -1;
	}
	top--;
	return contents[top+1];

}

/*
 * Functions: isEmpty, isFull
 * Usage: if (s1.isEmpty()) ...
 * -----------------------------------
 * These return a true value if the stack is empty
 * or full (respectively).
 */

bool myStack::isEmpty() const {
	//top == 0 could be non empty with an element at 0 so we use -1
	return top == -1;
}

bool myStack::isFull() const {
	//10 max size = 0-9 indices so top would be maxSize-1 if full
	return top == maxSize-1;
}

