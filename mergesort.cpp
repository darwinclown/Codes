#include<iostream>
#include<stdio.h>
using namespace std;


void merge(int A[], int low, int mid, int high)
{
    int index=0,left,right,count=low;
    int B[high-low+1];
    left=low; right=mid+1;

    while (left<=mid && right<=high)
    {
        if(A[left]>A[right])
        {
            B[index++]=A[right++];
        }    
        else
        {
            B[index++]=A[left++];
        }
    }

    while(left<=mid){
        B[index++]=A[left++];
    }

    while(right<=high)
    {
        B[index++]=A[right++];
    }

for(count=low; count<=high; count++)
{
    A[count]=B[count-low];
}

}



void sort(int A[], int low, int high){
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        sort(A,low,mid);
        sort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}

int main(void)
{

    int A[5]={8,7,6,5,4};
    sort(A,0,4);
    int t=5;
    while(t--)
    {
        printf("%d",A[4-t]);
    }
    return 0;
}



