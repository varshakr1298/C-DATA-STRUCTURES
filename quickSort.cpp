#include<iostream>
using namespace std;
void swap(int &x,int &y){
    int temp = x;
    x=y;
    y=temp;
}
int partition(int arr[],int s,int e){
    int key = arr[e];
    int i = s-1;
    int j;
    for(j=s;j<=e;j++){
        if(arr[j]<=key){
            i+=1;
            swap(arr[i],arr[j]);
        }
    }
    return i;
}
void quickSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int m=partition(arr,s,e);
    quickSort(arr,s,m-1);
    quickSort(arr,m+1,e);
}
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    cout<<"\n Elements after sort: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
