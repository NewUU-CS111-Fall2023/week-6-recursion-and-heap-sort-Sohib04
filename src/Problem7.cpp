#include <iostream>

using namespace std;

int reverse(int n){
    static int result = 0;
    if(n==0){
        return result/10;
    }
    else{
        int temp = n%10;
        result = (result+temp)*10;
        n /= 10;
    }
    return reverse(n);
}

int main(){

    int n;
    cin>>n;
    cout<<reverse(n);

    return 0;
}