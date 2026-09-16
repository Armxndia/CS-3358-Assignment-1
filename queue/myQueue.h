#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_
#include <iostream>

using namespace std;

template <class T>
class myQueue {
public:
	myQueue(int maxSz);
	~myQueue();
	void enqueue(T item);
	T dequeue();
    int currentSize();
    bool isEmpty();
    bool isFull();

private:
	T *contents; /*Dynamic initiate (C++ keyword new) the holder array*/
	int front,rear;  /*Index in the array of the front and rear element*/
	int arrayLength;  /*The length of the contents holder array*/
		/* Keep in mind that the Queue will only hold up to (arrayLength - 1) elements*/
};

template <class T>
myQueue<T>::myQueue(int maxSz) {
	arrayLength = maxSz;
	contents = new T[arrayLength];
	front = 0;
	rear = 0;
}

template <class T>
myQueue<T>::~myQueue() {
	delete[] contents;
}

template <class T>
void myQueue<T>::enqueue(T item) {
	if (isFull()) {
        cerr << "Queue is full. Cannot enqueue." << endl;
        return;
    }
    contents[rear] = item;
    rear = (rear + 1) % arrayLength; 
}

template <class T>
T myQueue<T>::dequeue() {
	if (isEmpty()) {
        cerr << "Queue is empty. Cannot dequeue." << endl;
        return T(); // Similar to returning -1 garbage value for stacks
    }
    T item = contents[front];
    front = (front + 1) % arrayLength; //Simply makes front wrap back around to the index 0 when flowing over arrayLength
    return item;
}

template <class T>
int myQueue<T>::currentSize() {
	return (rear - front + arrayLength) % arrayLength;
}

template <class T>
bool myQueue<T>::isEmpty() {
	return front==rear;
}

template <class T>
bool myQueue<T>::isFull() {
	//front=rear would make full true but in this case we will keep one slot open since we do not have a counter variable
	return (rear+1) % arrayLength == front;
}

#endif