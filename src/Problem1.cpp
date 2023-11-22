/*
 * Date:11.21.2023
 * Name:Abdimannabov Sohibjon
 */

#include <iostream>

using namespace std;

void ascending(int start, int end){
    if(start == end+1){
        return;
    }
    ascending(start+1, end);
    cout<<start<<" ";
}

void descending(int start, int end){
    if(start == end-1){
        return;
    }
    descending(start-1, end);
    cout<<start<<" ";
}

int main() {
    
    int x, y;
    cin>>x>>y;

    if(x>y){
        descending(x, y);
    }
    else{
        ascending(x, y);
    }

    return 0;
}
