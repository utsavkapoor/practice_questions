#include <iostream>
using namespace std;

int peak_element(int array[30],int low,int high){
    if (low < high){
        if (low+1 == high){
            return array[low];
        }
        if(array[low] > array[low+1]){
            return array[low];
        }
        if(array[high] > array[high+1]){
            return array[high];
        }
        int mid = (high+low)/2;
        if ((array[mid] > array[mid-1]) && (array[mid] > array[mid+1])){
            return array[mid];
        }
        else if ((array[mid] > array[mid-1]) && (array[mid] < array[mid+1])){
            return peak_element(array,mid+1,high);
        } else {
            return peak_element(array,low,mid-1);
        }
    }
    return 0;
}

int main() {
    int arr[30];
    int increase = 80;
    int decrease = 20;
    for(int i=0;i<30;i++){
        if( i < 16){
            arr[i] = increase++;
        } else {
            arr[i] = decrease--;
        }
    }
    for(int i=0;i<30;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int answer = peak_element(arr,0,29);
    cout<<answer<<endl;
}