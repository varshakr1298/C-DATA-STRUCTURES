//Implementation of Stack

#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
using namespace std;
template <class T> 
class Stack{
	
	private: 
			T *a; //Dynamic array that is fixing the size of the array at the time of object creation
			int size;
			int top;
	
	public: 
			Stack(int); //Constructor
			bool push(T); //The parameter is the input variable
			bool pop(T &); //The parameter is the output variable which will be outputted using Call by Reference
			bool peep(T &); //The parameter is the output variable which will be outputted using Call by Reference
			bool isStackEmpty();
			bool isStackFull();
			void makeStackEmpty();
};
//Defining the constructor
template <class T>
Stack<T>::Stack(int n){
	
	size = n;
	top = -1;
	a = new T[size]; //Initializing the array
	
}
//Defining isStackEmpty() function
template <class T>
bool Stack<T>::isStackEmpty(){
	
	if(top == -1){
		return true;
	}
	else{
		return false;
	}
	
}
//Defining isStackFull() function
template <class T>
bool Stack<T>::isStackFull(){
	
	if(top == size-1){
		return true;
	}
	else{
		return false;
	}
	
}
//Defining push() function
template <class T>
bool Stack<T>::push(T x){
	
	//Checking stack overflow condition 
	if(isStackFull()){
		return false;
	}
	
	top = top + 1;
	a[top] = x;
	return true;
	
}
//Defining pop() function
template <class T>
bool Stack<T>::pop(T &x){
	
	//Checking stack underflow condition
	if(isStackEmpty()){
		x=-1; // Invalid number denoting that operation we are going to perform is invalid
		return false;
	}
	
	x = a[top];
	top = top - 1;
	return true;
	
}
//Defining peep() function
template <class T>
bool Stack<T>::peep(T &x){
	
	if(isStackEmpty()){
		return false;
	}
	
	x = a[top];
	return true;
	
}
//Defining makeStackEmpty() function
template <class T>
void Stack<T>::makeStackEmpty(){
	
	top = -1; //Signifies stack is empty
	
}

