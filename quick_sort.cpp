#include<iostream>
#include<stdlib.h>
using namespace std;

void swap (int *a, int *b)
{
	int temp= *a;
	*a=*b;
	*b= temp;
}




int main()
{
	int n;
	cout<<"Enter the number of elements:";
	cin>>n;
	int a[n];
	cout<<"This is Randomized Quick Sort. So randomly a pivot is selected"<<endl;
	cout<<"Enter array elements:";
	for(int i =0;i<n:i++)
	{
		cin>>a[i];
	}
	int pivot = rand()/n;
	swap(&a[pivot],&a[n-1]);
	quick_sort(a,n,pivot);
}