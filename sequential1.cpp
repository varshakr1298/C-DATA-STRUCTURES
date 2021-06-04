#include<iostream>
using namespace std;
int main()
{
    int a[50],sindex,len,b[50],nblock,i,sum;
    cout<<"Enter how many blocks that are already alocated";
    cin>>nblock;
    cout<<"Enter the block no.s that are already alocated";
    for(i=0;i<nblock;i++)
    cin>>b[i];
    cout<<"Enter the starting index block and length";
    cin>>sindex>>len;
    sum=sindex+len;
    for(i=sindex;i<(sum+nblock);i++)
    {
        for(int j=0;j<nblock;j++)
        if(b[j]==i)
        {cout<<i<<"-->already allocated\n";
        i++;
        }
        
        cout<<i<<"-->available\n";
    }
    return 0;
}
