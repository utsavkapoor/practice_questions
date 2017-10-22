/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Quickselect.cpp
 * Author: utsavkapoor
 *
 * Created on October 21, 2017, 9:11 PM
 */

#include <iostream>
#include<vector>
#include<climits>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b=temp;
}

int partition(vector<int> &arr,int low,int high){
    int i= low-1;
    int pivot = arr[high];
    for(int j=low;j<high;j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[high],&arr[i+1]);
    return (i+1);
}

int randompartition(vector<int> &arr,int low,int high){
    int val = high-low+1;
    int t = rand()%val;
    swap(&arr[low+t],&arr[high]);
    int temp = partition(arr,low,high);
    return temp;
}

int quickselect(vector<int> &arr,int low,int high,int order){
    if(order >0 && order<=high-low+1){
        int pos = randompartition(arr,low,high);
        if(pos-low==order-1){
            return arr[pos];
        }
        if(pos-low > order-1){
            return quickselect(arr,low,pos-1,order);
        } else {
            return quickselect(arr,pos+1,high,order-pos+low-1);
        }
    }
    return 0;
}



int main() {
    vector<int> arr;
    arr.push_back(20);arr.push_back(10);arr.push_back(2);arr.push_back(200);arr.push_back(19);arr.push_back(205);arr.push_back(25);arr.push_back(30);arr.push_back(101);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int k = quickselect(arr,0,arr.size()-1,2);
    cout<<k<<endl;
}

