
#include<iostream>
using namespace std;
int main(){ 
    int n; //Number of processes
    cout<<"Enter the number of process: ";
    cin>>n;
    int burstTime[n];
    for(int i=0;i<n;i++){
        cout<<"Burst time of process: "<<i;
        cin>>burstTime[i];
    }
    int startTime=0;
    int waitTime[n];
    //Calculating starting time
    for(int i=0;i<n;i++){
        //Calculating Wait Time
        waitTime[i]=startTime-i;
        cout<<"\nStarting time for process "<<i<<": "<<startTime;
        startTime=startTime+burstTime[i];
        
    }
    int sum=0;
    for(int i=0;i<n;i++){
        cout<<"\nWait time for process "<<i<<": "<<waitTime[i];
        sum+=waitTime[i];
    }
    //Calculating Average Waiting Time
    cout<<"\nAverage Waiting Time: "<<sum/n;
}



