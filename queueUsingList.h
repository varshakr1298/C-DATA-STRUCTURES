//Implementation of Queue Using Linked List
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
class Queue{
	
	private: 
            int size;
            Node<T> *f;
    
	public: 
			Queue(); //Constructor
			bool EnQ(T); //The parameter is the input variable
			bool DeQ(T &); //The parameter is the output variable which will be outputted using Call by Reference
			bool getFront(T &); //The parameter is the output variable which will be outputted using Call by Reference
			void display();
};
//Defining the constructor
template <class T>
Queue<T>::Queue(){
	
    f=NULL;
    size = 0;
}
//Defining push() function
template <class T>
bool Queue<T>::EnQ(T x){
	
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
//Defining DeQ() function
template <class T>
bool Queue<T>::DeQ(T &x){
	
    //Check for list empty
    if(f == NULL){
        x=-1; //Indicating invalid value
        return false;
    }
    Node<T> *t,*p;//p pointer for keeping track of parent node
    t=f;
    p=NULL;
    while(t!=NULL){
        if(t->next==NULL){
            if(p!=NULL){
                p->next = NULL;
                x=t->data;
                delete(t);
                size=size-1;
                return true;
            }else{
                f=NULL;
            }
        }
        p=t;
        t=t->next;
    }
	
}
//Defining peep() function
template <class T>
bool Queue<T>::getFront(T &x){
	
    //If list is empty, return failure
    if(f==NULL)
    {
        return false;
    }
    
    //Searching the last node
    Node<T> *p=NULL;
    Node<T> *t=f;
    while(t->next!=NULL)
    {
        p = t;
        t = t->next;
    }
    
    //Store the data in the output variable
    x = t->data;
    
	
}
template <class T>
void Queue<T>::display(){
    
    if(f==NULL)
    {
        cout<<"\nQueue is empty!\n";
        return;
    }
    Node<T> *t;
    t = f;
    
    while(t!=NULL)
    {
        cout<<"\t\t|"<<t->data<<"|";
        t = t->next;
    }
}
