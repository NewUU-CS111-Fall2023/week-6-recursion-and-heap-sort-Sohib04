#include <iostream>

using namespace std;
int counter=0;
int isPrime(int n, int temp){
    if(n == 2){
        return 3;
    }
    else if(n>=temp){
        if(n%temp==0){
            counter++;
        }
        isPrime(n, temp+1);
    }

    return counter;
}

int main(){

    int n;
    cin>>n;
    if(n<=1){
        cout<<"Wrong Input";
    }
    else{
        if(isPrime(n, 1)>2){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
    }

    return 0;
}