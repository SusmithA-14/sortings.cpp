#include<iostream>
using namespace std;
int partition (int a[],int lb,int ub)
{
	int pivot=a[lb];//first value as pivot or key
	int start=lb,end=ub;//take second pointer at begining and other at end
	while(start<end)//whether they crossed eachother or not
	{
		while(a[start]<=pivot)//if you find values <=pivot move your start
		{
			start++;
		}
		while(a[end]>pivot)//if you find values > pivot move your end
		{
			end--;
		}
		if(start<end)//if they dont cross each other then swap them
		{
			swap(a[start],a[end]);
		}
	}
	swap(a[lb],a[end]);//if they cross keep pivot at middle
	return end;
}

void Quicksort(int a[],int low,int high)
{
	if(low<high)
	{
		int loc=partition(a,low,high);//find partition location to make parts
		Quicksort(a,low,loc-1);//part1 values<=pivot
		Quicksort(a,loc+1,high);//part2 values>pivot
	}
}


int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
    }
    Quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
	}
	return 0;
}
