//FCFS DISK SCHEDULING
#include<iostream>
using namespace std;
int main(){
    int n,initialPointer;
    cout<<"Enter the number of references: ";
    cin>>n;
    int requestSequence[n];
    cout<<"\n Enter the request sequence: ";
    for(int i=0;i<n;i++){
        cin>>requestSequence[i];
    }
    cout<<"\n Enter the intial head position: ";
    cin>>initialPointer;
    int temp=0,currentHead;
    temp = abs(requestSequence[0]-initialPointer);
    for(int i=0;i<n-1;i++){
            temp = temp + abs(requestSequence[i]-requestSequence[i+1]);
    }
    cout<<temp;
    return 0;
}

