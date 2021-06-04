//Bubble sort
#include<iostream>
using namespace std;
void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
void bubbleSort(int arr[],int n){
    
    for(int i=0;i<=n-2;i++){
        for(int j=0;j<=n-2-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main(){
	int n;
	cout<<"\nEnter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter the elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"\nElements before sort!: ";
	display(arr,n);
	cout<<"\nElements after applying bubble sort: ";
	bubbleSort(arr,n);
	display(arr,n);
}
