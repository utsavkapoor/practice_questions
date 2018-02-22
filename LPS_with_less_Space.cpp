#include <iostream>
#include <vector>
#include <string>
using namespace std;

string LPS(string &str){
    string temp_str = "@";
    int n = str.size();
    int k =0;
    for (int i=0;i<(2*n)+1;i++){
        if(i%2 ==0){
            temp_str += "#";
        } else {
            temp_str += str[k++];
        }
    }
    temp_str += "!";
    int start = 0;
    int max_length = 0;
    for(int i=1;i<temp_str.size();i++){
        int k = i-1;
        int m = i+1;
        int len = 1;
        while (k > 0 && m < temp_str.size()){
            if(temp_str[k] == temp_str[m]){
                len += 2;
                k--;
                m++;
            } else {
                break;
            }

        }
        if (len > max_length){
            max_length = len;
            start = i;
        }
    }
    string answer = "";
    string x = temp_str.substr(start-(max_length/2),max_length);
    for(int i=0;i<x.size();i++){
        if(x[i] != '#'){
            answer += x[i];
        }
    }
    return answer;
}

int main() {
    string s ="forgeeksskeegfor";
    string k = LPS(s);
    cout<<"Ans is: "<<k<<endl;
}
