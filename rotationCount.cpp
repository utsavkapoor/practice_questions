#include <iostream>
#include <vector>
using namespace std;
// there is a guarntee that the array given is rotated
int rotationCount(int arr[],int low,int high){
    //cout<<low<<" "<<(low+high)/2<<" "<<high<<endl;
    if(low<high){
        if (low+1==high){
            //cout<<"I am here"<<endl;
            if(arr[low]<arr[high]){
                return low;
            } else {
                return high;
            }
        } else {
            int mid = (low+high)/2;
            if(arr[low] > arr[mid]){
                return rotationCount(arr,low,mid);
            } 
            else if(arr[high] < arr[mid]){
                return rotationCount(arr,mid,high);
            } else {
                return low;
            }
        }
    }
    return -1;
}

int main() {
    int array[] = {7, 9, 11, 12, 15};
    int size = 5;
    int k = rotationCount(array,0,size-1);
    cout<<k<<endl;
}
