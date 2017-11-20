#include <iostream>
using namespace std;
// each line show 2 indices which are 2 pairs

int main() {
    int array[10] = {10, 30, 2, 6, 3, 100,35,1,0};
    int value = 135;
    int flag = 0;
    unordered_map <int,int> dict;
    for(int i=0;i<10;i++){
        if(dict.find(array[i]) == dict.end()){
            dict[value-array[i]] = i;
        } else {
            cout<<i<<" "<<dict[array[i]]<<endl;
            flag = 1;
        }
    }
    if (flag==0){
        cout<<"pair not found"<<endl;    
    }
    return 0;
}

