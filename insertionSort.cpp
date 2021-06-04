//Inserstion Sort
#include<iostream>
using namespace std;
void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
void insertionSort(int arr[],int n){
	int i,j;
	for(i=1;i<=n-1;i++){
		int key=arr[i];
		j=i-1;
		while(j>=0 && key<arr[j]){
			arr[j+1]=arr[j];
			j=j-1;
			cout<<"\nIteration"<<i<<": ";
			display(arr,n);
		}
		arr[j+1]=key;
		cout<<"\nIteration"<<i<<": ";
		display(arr,n);
		cout<<"\n";
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
	cout<<"\nElements after applying insertion sort: ";
	insertionSort(arr,n);
	cout<<"\n\nFinal Output: ";
	display(arr,n);
}
