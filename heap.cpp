#include <iostream>
#include <vector>
#include <stdlib.h> 
using namespace std;

class heap {
    vector<int> array;
    int length;
    int parent(int index);
    int left_child(int index);
    int right_child(int index);
    void heapify(int i);
    void build_initial_heap();
    void Make_Min_Heap();
    public:
    heap(int size);
    int extractMin();
    int decreaseKey(int index, int new_val);
    int deleteKey(int index);
    int insertKey(int value);
    void display_heap();
};

heap::heap(int n){
    length = n;
    build_initial_heap();
}

void heap::build_initial_heap(){
    for(int i=0;i<length;i++){
        array.push_back(rand()%100);
    }
    Make_Min_Heap();
}

void heap::display_heap(){
    cout<<length<<endl;
    for(vector<int>::iterator it = array.begin(); it != array.end(); it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
    //heapify();
}

int heap::extractMin(){
    if (array.empty()){
        return -1;
    }
    //heapify();
    int mini = array[0];
    array.erase(array.begin());
    return mini;
}

int heap::insertKey(int value){
    if(array.size() > 20){
        return -1;
    }
    array.push_back(value);
    //heapify();
    return 0;
}

int heap::deleteKey(int index){
    if(index > 20 || index < 0){
        return -1;
    }
    vector<int>::iterator it = array.begin();
    advance(it,index);
    it = array.erase(it);
    //heapify();
    return 0;
}

int heap::parent(int index){
    if(index%2 == 1){
        return index/2;
    } else {
        return (index/2)-1;
    }
}

int heap::left_child(int index){
    return 2*index+1;
}

int heap::right_child(int index){
    return 2*(index+1);
}

void heap::heapify(int i){


}

void heap::Make_Min_Heap(){
    for(int i=(length-2)/2;i>=0;i--){
        heapify(i);
    }
    cout<<endl;
}


int main() {
    heap temp(20);
    temp.display_heap();
    return 0;
}
