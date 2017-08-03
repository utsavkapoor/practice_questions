#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp =*a;
	*a=*b;
	*b=temp;
}

int main()
{
	int n;
	cout<<"Enter the length of array:";
	cin>>n;
	int a[n];
	cout<<"Enter the array elements:";
	for(int i =0;i<n;i++)
	{
		cin>>a[i];
	}
	swap (&a[2],&a[3]);
	for(int i =0;i <n ;i++)
	{
		cout<<a[i]<<endl;
	}
	
}
