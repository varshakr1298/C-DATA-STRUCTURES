#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        for(int j=0;j<=n-2-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
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
    bubbleSort(arr,n);
    cout<<"\n Elements after sort: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
