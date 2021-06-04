//Implementation of Stack Using Linked List
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
using namespace std;
template <typename T>
struct Node{
    T data;
    Node *next;
};
template <class T> 
class Stack{
	
	private: 
            int size;
            Node<T> *f;
    
	public: 
			Stack(); //Constructor
			bool push(T); //The parameter is the input variable
			bool pop(T &); //The parameter is the output variable which will be outputted using Call by Reference
			bool peep(T &); //The parameter is the output variable which will be outputted using Call by Reference
			void display();
};
//Defining the constructor
template <class T>
Stack<T>::Stack(){
	
    f=NULL;
    size = 0;
}
//Defining push() function
template <class T>
bool Stack<T>::push(T x){
	
    //Step 1: Create a new node
    Node<T> *n;
    n=new Node<T>;
    if(n == NULL){
        return false;
    }
    //Step 2: Fill the node
    n->data = x;
    n->next = NULL;
    //Step 3: Link the new node n with the starting node
    n->next = f;
    f = n;
    size = size + 1;
    
    return true;
	
}
//Defining pop() function
template <class T>
bool Stack<T>::pop(T &x){
	
    //Check if list is empty or not
    if(f==NULL){
        x=-1; //Indicating invalid value
        return false;
    }
    //Update the output
    x=f->data;
    //Disconnect and delete
    Node<T> *t;
    t=f;
    f=f->next;
    size=size-1;
    delete(t);
    return true;
	
}
//Defining peep() function
template <class T>
bool Stack<T>::peep(T &x){
	
    //If list is empty, return failure
    if(f==NULL)
    {
        return false;
    }
    
    //Store the value of the data that is to deleted next
    x = f->data;
    return true;
	
}
template <class T>
void Stack<T>::display(){
    
    if(f==NULL)
    {
        cout<<"\nStack is empty!\n\n";
        return;
    }
    Node<T> *t;
    t = f;
    
    while(t!=NULL)
    {
        cout<<"\n\t\t|"<<t->data<<"|";
        t = t->next;
    }
}
