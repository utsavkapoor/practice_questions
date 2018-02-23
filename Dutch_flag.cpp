#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dutch_flag_algorithm(vector<int> &arr){
    int mid = 1;
    int i = 0;
    int j =0;
    int n = arr.size()-1;
    while(j<=n){
        if(arr[j]<mid){
            swap(arr[i],arr[j]);
            i++;j++;
        }
        else if(arr[j]>mid){
            swap(arr[j],arr[n]);
            n--;
        }
        else{
            j++;
        }
    }
}

int main() {
    vector <int> array;
    int n = 30;
    for(int i=0;i<n;i++){
        int temp = rand()%3;
        array.push_back(temp);
    }
    dutch_flag_algorithm(array);
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
