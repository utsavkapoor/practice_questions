/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <vector>
using namespace std;

void spiral_print(vector< vector <int> > &array, int m, int n){
    int i=0,j=0;
    while (i<m && j<n){
        //print ith row
        for(int start = j;start<=n;start++){
            cout<<array[i][start]<<" ";
        }
        i++;
        //print (n-1)th row
        for(int start = i;start<=m;start++){
            cout<<array[start][n]<<" ";
        }
        n--;
        for(int start = n;start>=j;start--){
            cout<<array[m][start]<<" ";
        }
        m--;
        for(int start = m;start>=i;start--){
            cout<<array[start][j]<<" ";
        }
        j++;
    }
    cout<<endl;
}


int main() {
    vector<vector<int> > arr(6, vector<int>(6,0));
    int num = 1;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            arr[i][j] = num;
            num++;
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
    spiral_print(arr,arr.size()-1,arr[0].size()-1);
    return 0;
}
