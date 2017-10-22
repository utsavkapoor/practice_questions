#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

void swap (int *a, int *b)
{
	int temp= *a;
	*a=*b;
	*b= temp;
}

int partition(vector<int> &a,int low,int high){
    int pivot = a[high];
    int i = (low-1);
    for(int j = low;j<high;j++){
        if(a[j] <= pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return (i+1);
}

void quicksort(vector<int> &a,int low,int high){
    if(low<high){
        int pivot = partition(a,low,high);
        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high);
    }
}


int main()
{
	int n;
	cout<<"Enter the number of elements:";
	cin>>n;
	vector<int> a;
	cout<<"This is Randomized Quick Sort. So randomly a pivot is selected"<<endl;
	cout<<"Enter array elements:";
	for(int i =0;i<n;i++)
	{       
                int temp;
		cin>>temp;
                a.push_back(temp);
	}
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        quicksort(a,0,n);
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
}