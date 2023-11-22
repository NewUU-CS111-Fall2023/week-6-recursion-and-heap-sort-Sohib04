#include <iostream>

using namespace std;

void check(int n){
    if(n%2==0){
        check(n/2);
    }
    else if(n==1){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}

int main(){

    int n;
    cin>>n;
    check(n);
    return 0;
}