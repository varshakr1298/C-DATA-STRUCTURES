//Driver code of Stack Using Array

#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include "Stack.h"
using namespace std;
int main(){
	char ch='y';
	int choice;
	int size;
	cout<<"Enter the size of the stack: ";
	cin>>size;
	Stack <int>s(size);
	do{
		cout<<"\n****************************************************************************************************************\n";
		cout<<"\t\t\t Performing Stack Operations";
		cout<<"\nOption 1: Push an element to the stack.";
		cout<<"\nOption 2: Pop an element from the stack.";
		cout<<"\nOption 3: Peep(LookUp) the element from the stack.";
		cout<<"\nOption 4: Make the stack empty.";
		cout<<"\nOption 5: Exit!";
		cout<<"\n****************************************************************************************************************\n";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		switch(choice){
			
			case 1: {
					int element; // Input Variable
					cout<<"\nEnter the element you want to push into the stack: ";
					cin>>element;
					bool result = s.push(element);
					if(result == true){
						cout<<"\nPush operation is successful! ";
					}
					else{
						cout<<"\n Push operation failed! ";
					}
					break;
			    	}
			case 2: {
					int y; //Output variable
					bool result = s.pop(y);
					if(result == true){
						cout<<"\n Pop Operation is successful!: Popped element is "<<y;
					}
					else{
						cout<<"\n Failed Pop Operation : Element not present in stack!";
					}
					break;
					}
					
			case 3: {
					int y;
					bool result = s.peep(y);
					if(result == false){
						cout<<"\nStack Underflow!";
					}
					else{
						cout<<"\nNext element to be deleted or the LookUp element is "<<y;
					}
					break;
				   }
			case 4: s.makeStackEmpty();
					break;
					
			case 5: exit(0);
		}
		cout<<"\nDo you wish to continue(y/press any other key)? ";
	    cin>>ch;
	}while(ch == 'y');
}
