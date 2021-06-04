//Implementation of Stack

#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
using namespace std;
template <class T> 
class Queue{
	private: 
			T *a; //Dynamic array that is fixing the size of the array at the time of object creation
			int size;
			int front;
            int rear;
	
	public: 
			Queue(int); //Constructor
            ~Queue(){  //Destructor
                delete(a);
            }
			bool EnQ(T); //The parameter is the input variable
			bool DeQ(T &); //The parameter is the output variable which will be outputted using Call by Reference
			bool getFront(T &); //The parameter is the output variable which will be outputted using Call by Reference
			bool isQueueEmpty();
			bool isQueueFull();
			void makeQueueEmpty();
};
//Defining the constructor
template <class T>
Queue<T>::Queue(int n){
	
	size = n;
	front = rear = -1;
	a = new T[size]; //Initializing the array
	
}
//Defining isQueueEmpty() function
template <class T>
bool Queue<T>::isQueueEmpty(){
	
	if(front == -1){
		return true;
	}
	else{
		return false;
	}
	
}
//Defining isQueueFull() function
template <class T>
bool Queue<T>::isQueueFull(){
	
	if(rear == size-1){
		return true;
	}
	else{
		return false;
	}
	
}
//Defining EnQ() function
template <class T>
bool Queue<T>::EnQ(T x){
	
	//Checking queue overflow condition
	if(isQueueFull()){
		return false;
	}
	
	rear = rear + 1;
	a[rear] = x;
    if(front == -1){
        front = front + 1;
    }
	return true;
	
}
//Defining DeQ() function
template <class T>
bool Queue<T>::DeQ(T &x){
	
	//Checking queue underflow condition
	if(isQueueEmpty()){
		x=-1; // Invalid number denoting that operation we are going to perform is invalid
		return false;
	}
	
	x = a[front];
    if(front!=rear){
        front = front + 1;
    }else{
        front = rear = -1;
    }
	return true;
}
//Defining getFront() function
template <class T>
bool Queue<T>::getFront(T &x){
	
	if(isQueueEmpty()){
        x=-1;
		return false;
	}
	
	x = a[front];
	return true;
	
}
//Defining makeStackEmpty() function
template <class T>
void Queue<T>::makeQueueEmpty(){
	
	front = rear = -1; //Signifies queue is empty
	
}

