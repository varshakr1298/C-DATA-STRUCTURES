
#include<iostream>
using namespace std;
int main(){ 
    int n; //Number of processes
    cout<<"Enter the number of process: ";
    cin>>n;
    int burstTime[n];
    for(int i=0;i<n;i++){
        cout<<"Burst time of process "<<i<<": ";
        cin>>burstTime[i];
    }
    int priority[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the arrival time of process"<<i<<": ";
        cin>>priority[i];
    }
    int startTime=0;
    int waitTime[n];
    int completionTime[n];
    //Calculating starting time
    for(int i=0;i<n;i++){
        //Calculating Wait Time
        waitTime[i]=startTime-priority[i];
        cout<<"\nStarting time for process "<<i<<": "<<startTime;
        startTime=startTime+burstTime[i];
        completionTime[i]=startTime;
    }
    for(int i=0;i<n;i++){
        cout<<"\nCompletion time for process "<<i<<" "<<completionTime[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        cout<<"\nWait time for process "<<i<<": "<<waitTime[i];
        sum+=waitTime[i];
    }
    //Calculating Average Waiting Time
    cout<<"\nAverage Waiting Time: "<<sum/n;
}



