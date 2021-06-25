#include<iostream>
using namespace std;

int RotatedSA(int low,int high,int a[],int T)
{
	while(low<=high)
	{
		int mid=(low+high)>>1;
		if(T==a[mid])
		{
			return mid;
		}
		if(a[mid]<a[0])//mid is in part2
		{
			if(T>=a[0]||T<a[mid])//target in part1
			{
				high=mid-1;
			}
			else//target in part2
			{
				low=mid+1;
			}
		}
		else//mid is in part1
		{
			if(T>a[mid]||T<a[0])//
			{
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
	}
	return -1;
}


int main()
{
	int n;
	cin>>n;
	int T;
	cin>>T;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<RotatedSA(0,n-1,a,T);
	return 0;
}
