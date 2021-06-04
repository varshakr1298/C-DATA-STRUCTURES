#include<iostream>
using namespace std;
//Creating node structure
struct Node{
    int data;
    Node *next;
    Node *prev;
};
class DoublyList{
    private:
        Node *f; //Node pointer pointing to the front of the list
        Node *l; //Node pointer pointing to the last of the list
        int size;

    public:
    DoublyList(){
        f=NULL;
        size=0;
    }
    bool insertFront(int);
    bool insertEnd(int);
    bool insertAt(int, int);
    bool elementAt(int, int &);
    bool deleteFront(int &);
    bool deleteEnd(int &);
    bool deleteAt(int, int &);
    bool deleteElement(int);
    bool search(int);
    void display();
};
bool DoublyList::insertFront(int x){

	//Step 1: Create a new node
	Node *n;
	n=new Node;
	if(n == NULL){
        return false;
	}
	//Step 2: Fill the node
	n->data = x;
    n->next = f;
	n->prev = NULL;
	//Step 3: Link the new node n with the starting node
	if (f == NULL)
    {
        n->prev = NULL;
        f = n;
        size=size+1;
    }
    else
    {
	    f->prev = n;
	    f = n;
	    size=size+1;
	}
	return true;
}
bool DoublyList::insertEnd(int x){
	//Step 1: Create a new node n
	Node *n;
	n=new Node;
	if(n == NULL){
		return false;
	}
	//Step 2: Fill the node and link the new node with the already present nodes
	Node* t = f;
    n->data = x;
    n->next = NULL;
    if (f == NULL) {
        n->prev = NULL;
        f = n;
        size=size+1;
        return true;
    }
 
    // Traversing till the last node 
    while (t->next != NULL)
        t = t->next;
 
    //Change the next of temp 
    t->next = n;

    //Linking back to previous 
    n->prev = t;
 
    size=size+1;
    return true;

}
bool DoublyList::insertAt(int p,int x){
	//Checking if the index is valid or not
	if(p<1||p>size+1){
	return false;
	}
	//Step 1: Create a new node n
	Node *n;
	n=new Node;
	if(n == NULL){
	   return false;
	}
	//Step 2: Fill the node
	n->data = x;
	n->next = NULL;
	//Step 3: Linking of nodes
	//Case 1: When it is the first node then same as insertFront
	if(p == 1){
	   n->prev = NULL;
       f = n;
       size=size+1;
       return true;
	}
	//Case 2: When we need to insert at a position other than 1
	Node * t;
	int i;
	t = f;
	i = 1;
	while(t!=NULL){
	//Moving till one position before the actual one
    	if(i==p-1){
    	    //Linking the next of the new node with the temp
    	    n->next=t->next;
    	    //Then linking the temps next with the new node
        	t->next=n;
        	//Updating the previous of the new node
        	n->prev = t;
        	size+=1;
        	return true;
	    }
	t=t->next;
	i++;
	}
	return false;
}
bool DoublyList::elementAt(int p,int &x){
   
    //Checking for invalid indices entered as input
    if(p<1 || p>size){
        x=-1;
        return false;
    }
    int i;
    Node *t;
    t=f;
    i=1;
    while(t!=NULL){
        if(i==p){
            x=t->data;
            return true;
        }
        t=t->next;
        i = i + 1;
    }
}
bool DoublyList::search(int x){
	//Check for list empty
	if(f==NULL){
		x=-1;
		return false;
	}
	Node *t;
	t=f;
	while(t!=NULL){
		if(t->data==x){
			return true;
		}
		t=t->next;
	}
	return false;
}
bool DoublyList::deleteFront(int &x){
    
    if(f==NULL){
        x=-1;
        return false;
    }
    if(f->next==NULL){
        x=f->data;
        f=NULL;
        delete(f);
        size=size-1;
        return true;
    }
    Node *t=f;
    //Update the output
    x=f->data;
    //Free the links
    f=f->next;
    f->prev=NULL;
    size=size-1;
    delete(t);
    return true;
}
bool DoublyList::deleteEnd(int &x){
   
    //Check for list empty
    if(f == NULL){
        x=-1; //Indicating invalid value
        return false;
    }
    Node *t;
    t=f;
    //Traversing till the end of the list
    while(t->next!=NULL){
        t=t->next;
    }
    //Linking the prev of the temp with that of the previous node meaning traversing back
    Node *t1=t;
    t=t->prev;
    if(t!=NULL){
        x=t1->data;
        t->next=NULL;
        delete(t1);
        size=size-1;
        return true;
    }else{
        f=NULL;
        size=size-1;
        return true;
    }
}
bool DoublyList::deleteAt(int pos,int &x){
	//Checking if the index is valid or not
	if(pos<1||pos>size+1){
	    return false;
	}
	if(f==NULL){
	   x=-1;
	   return false;
	}
	int i=1;
	Node *t;
	t=f;
	//Traversing till the position one before where we have to delete at
    while(i==pos-1 && t!=NULL){
        t=t->next;
        i++;
    }
    if(i==1){
        x=t->data;
        f=NULL;
        size=size-1;
        return true;
    }else if(t!=NULL){
        x=t->data;
        t->prev->next=t->next;
        if(t->next != NULL){
            t->next->prev = t->prev;
        }
        delete(t);
        size=size-1;
        return true;
    }
}
bool DoublyList::deleteElement(int x){
	if(f==NULL){
		x=-1;
		return false;
	}
	Node *t,*t1;
	t=f;
	//Traversing till the position where we have to delete at
    while(t!=NULL && f->next!=NULL) {
        if(t->data==x){
            t1=t;
            break;
        }
        t=t->next;
    }
   if(t1!=NULL){
        x=t1->data;
        t1->prev->next=t1->next;
        if(t1->next != NULL){
            t1->next->prev = t1->prev;
        }
        delete(t1);
        size=size-1;
        return true;
    }else{
        x=t->data;
        f=NULL;
        size=size-1;
        return true;    
    }
}
void DoublyList::display(){
	if(f == NULL){
	cout<<"\n List is empty!";
	return;
	}
	Node *t;
	t=f;
	while(t!=NULL){
		cout<<t->data;
		cout<<"<->";
		t=t->next;
	}
	cout<<"NULL";
}
int main(){
	
char ch = 'y';
int choice;
DoublyList a;
do{
	cout<<"\n\t\t\tDoubly Linked List Operations";
	cout<<"\n Option 1: Insert an element at the front of the list.";
	cout<<"\n Option 2: Insert an element at the end of the list.";
	cout<<"\n Option 3: Insert an element at a particular position in the list.";
	cout<<"\n Option 4: To display the value of the element present at a particular position.";
	cout<<" Option 5: Delete an element from the front of the list.";
	cout<<"\n Option 6: Delete an element from the end of the list.";
	cout<<"\n Option 7: Delete an element from a particular position of the list.";
	cout<<"\n Option 8: Delete an element present in the list by passing element value.";
	cout<<"\n Option 9: Search from the list";
	cout<<"\n Option 10: Display the list";
	cout<<"\n Option 11: Exit!";
	cout<<"\n Enter your choice: ";
	cin>>choice;
	switch(choice){
			case 1: {
					int x;
					cout<<"\nEnter the value of the node data that has to be inserted at front: ";
					cin>>x;
					bool result = a.insertFront(x);
					if(result == true){
					cout<<"Successful insertion at front!";
					}else{
					cout<<"Insertion failed!";
					}
					
			break;
			}
			case 2:{
					int x;
					cout<<"\nEnter the value of the node data that has to be inserted at end: ";
					cin>>x;
					bool result = a.insertEnd(x);
					if(result == true){
					cout<<"Successful insertion at end!";
					}else{
					cout<<"Insertion failed!";
					}
					break;
			}
			case 3:{
					int x,p;
					cout<<"Enter the position where you want to insert node: ";
					cin>>p;
					cout<<"\nEnter the value of the node data that has to be inserted at postion "<<p<<": ";
					cin>>x;
					bool result = a.insertAt(p,x);
					if(result == true){
						cout<<"Successful insertion at position "<<p<<"!";
					}else{
						cout<<"Insertion failed!";
					}
				break;
			}
			case 4:{
					int y,p;// y is output variable and p is the input variable
					cout<<"Enter the position whose data has to be displayed: ";
					cin>>p;
					bool result = a.elementAt(p,y);
					if(result == true){
					cout<<"Element found at position "<<p<<" is "<<y;
					}else{
					cout<<"Operation failed!";
			}
			   break;
			}
            case 5:{
                int y; //Output Variable
                bool result = a.deleteFront(y);
                if(result == true){
                    cout<<"\nElement "<<y<<" deleted from the front successfully!";
                }else{
                    cout<<"\nDeletion operation failed!";
                }
                break;
            }
            case 6:{
                int y; //Output Variable
                bool result = a.deleteEnd(y);
                if(result == true){
                    cout<<"\nElement "<<y<<" deleted from the end successfully!";
                }else{
                    cout<<"\nDeletion operation failed!";
                }
                break;
            }
            case 7:{
                int y,p;// y is output variable and p is the input variable
				cout<<"Enter the position whose data has to be deleted: ";
				cin>>p;
				bool result = a.deleteAt(p,y);
				if(result == true){
				cout<<"Element deleted at position "<<p<<" is "<<y;
				}else{
				cout<<"Operation failed!";
				}
				   break;
			}
			case 8:{
					int x;
					cout<<"\nEnter the value of the node data that has to be deleted: ";
					cin>>x;
					bool result = a.deleteElement(x);
					if(result == true){
					cout<<"Node "<<x<<" deleted successfully!";
					}else{
					cout<<"Deletion failed!";
					}
					break;
			}
			case 9:{
					int x;
					cout<<"\nEnter the element to be searched: ";
					cin>>x;
					bool result = a.search(x);
					if(result == true){
						cout<<"Element found!";
					}else{
						cout<<"Element not found!";
					}
					
				break;
			}
			case 10:{
				a.display();
				break;
			}
			case 11:{
				exit(0);
				break;
			}
}
cout<<"\n Do you wish to continue(y/press any other key): ";
cin>>ch;
}while(ch=='y');
    return 0;
}

