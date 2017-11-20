#include <iostream>
#include <vector>
using namespace std;

int missing_number(vector<int> &arr,int low,int high,int d){
    if(low<high){
        if(low+1 == high ){
            if(arr[low]+2*d == arr[high]){
                return arr[low];
            } else {
                return -1;
            }
        }
        int mid = (low+high)/2;
        if((arr[mid] + 2*d) == arr[mid+1]){
            // number found
            return arr[mid];
        } 
        else if((arr[mid]-arr[low])/d == (mid-low)){
            return missing_number(arr,mid,high,d);
        } else {
            return missing_number(arr,low,mid,d);
        }
    }
}

int main() {
    vector<int> array;
    int n = 10;
    int a = 5;
    int d = 7;
    for(int i=0;i<n;i++){
        int temp;
        if(i>7){
            temp = a+(i+1)*d;
        } else {
            temp = a+i*d;
        }
        array.push_back(temp);
    }
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    int answer = missing_number(array,0,array.size()-1,d);
    if(answer == -1){
        cout<<"number not found"<<endl;
    } else {
        cout<<(answer+d)<<endl;
    }
    
}