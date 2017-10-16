/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   merge_sort.cpp
 * Author: utsavkapoor
 *
 * Created on October 11, 2017, 4:59 PM
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * 
 */
void merge(vector<int> &array,int lower, int mid, int higher){
    int i,j,k=lower;
    cout<<"Entered Merge Step with:"<<lower<<"->"<<mid<<"->"<<higher<<endl;
    int left_size = mid-lower+1;
    int right_size = higher-mid;
    int left[left_size],right[right_size];
    for (int l=0;l<left_size;l++){
        left[l] = array[lower+l];
    }
    for (int l=0;l<right_size;l++){
        right[l] = array[mid+1+l];
    }
    i=0;j=0;
    while(i<left_size && j<right_size){
        if(left[i] <= right[j]){
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<left_size){
        array[k++] = left[i++];
    }
    while(j<right_size){
        array[k++] = right[j++];
    }
}

void mergesort(vector<int> &array,int lower,int higher){

    if (lower<higher){
        int mid = (lower+higher)/2;
        mergesort(array,lower,mid);
        mergesort(array,mid+1,higher);
        merge(array,lower,mid,higher);
    } else {
        return;
    }
    
}
int main() {
    vector<int> array;
    int size = 6;
    for (int i=0;i<size;i++){
        int temp;
        cout<<"Enter Element:";
        cin>>temp;
        array.push_back(temp);
    }
    cout<<"Array Elements before sorting are:"<<endl;
    for (int i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    mergesort(array,0,array.size()-1);
    for (int i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}

