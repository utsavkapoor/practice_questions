#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp =*a;
	*a=*b;
	*b=temp;
}

void insertion_sort(int a[], int n)
{
	int i,j,temp;
	for (i=1; i<n;i++)
	{
		temp = a[i];
		j=i-1;
		while(j>=0 && a[j]>temp)
			{
				swap(&a[j],&a[j+1]);
				j--;
				temp = a[j+1];
			} 
			
	}
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
	insertion_sort(a,n);
	for(int i =0;i <n ;i++)
	{
		cout<<a[i]<<endl;
	}
	
}