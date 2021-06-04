//Selection sort
#include<iostream>
using namespace std;
void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
void selectionSort(int arr[],int n){
	int i,j;
	for(i=0;i<=n-2;i++){
		cout<<"\n\nIteration i="<<i<<": ";
		display(arr,n);
		for(j=i+1;j<=n-1;j++){
			if(arr[j]<arr[i]){
				int temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
			cout<<"\nIteration j="<<j<<": ";
			display(arr,n);
		}
		if(j==n-1){
			cout<<"\n\nIteration j="<<j<<": ";
			display(arr,n);
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
	cout<<"\nElements after applying selection sort: ";
	selectionSort(arr,n);
	cout<<"\n\nFinal Output: ";
	display(arr,n);
}
