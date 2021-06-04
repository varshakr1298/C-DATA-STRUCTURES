//Driver code of Queue Using List

#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include "queueUsingList.h"
using namespace std;
int main(){
	char ch='y';
	int choice;
	Queue <int>q;
	do{
		cout<<"\n********************************************************************************************\n";
        cout<<"\t\t\t Performing Queue Operations";
        cout<<"\nOption 1: EnQ an element to the queue.";
        cout<<"\nOption 2: DeQ an element from the queue.";
        cout<<"\nOption 3: Get the front(LookUp) element from the queue.";
        cout<<"\nOption 4: Display the elements of queue.";
        cout<<"\nOption 5: Exit!";
		cout<<"\n*******************************************************************************************\n";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		switch(choice){
			
            case 1: {
                    int element; // Input Variable
                    cout<<"\nEnter the element you want to EnQ into the queue: ";
                    cin>>element;
                    bool result = q.EnQ(element);
                    if(result == true){
                        cout<<"\nEnQ operation is successful! ";
                    }
                    else{
                        cout<<"\n EnQ operation failed! Queue is full! ";
                    }
                    break;
                    }
            case 2: {
                    int y; //Output variable
                    bool result = q.DeQ(y);
                    if(result == true){
                        cout<<"\nDeQ Operation is successful!: DeQueued element is "<<y;
                    }
                    else{
                        cout<<"\nFailed DeQ Operation : Element not present in queue or Queue is empty!";
                    }
                    break;
                    }
                    
            case 3: {
                    int y;
                    bool result = q.getFront(y);
                    if(result == false){
                        cout<<"\nQueue Underflow!";
                    }
                    else{
                        cout<<"\nNext element to be deleted or the LookUp element is "<<y;
                    }
                    break;
                   }
            case 4: q.display();
                    break;
                    
            case 5: exit(0);
		}
		cout<<"\nDo you wish to continue(y/press any other key)? ";
	    cin>>ch;
	}while(ch == 'y');
}
