#include <iostream>

using namespace std;
int digits;
void sumDigits(int n){
    if(n==0){
        cout<<digits;
    }
    else{
        int temp = n%10;
        digits+=temp;
        sumDigits(n/10);
    }
}

int main(){

    int n;
    cin>>n;
    sumDigits(n);

    return 0;
}