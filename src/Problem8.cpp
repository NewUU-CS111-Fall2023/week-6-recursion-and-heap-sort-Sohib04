#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addStrings(string a, string b) {
    int carry = 0;
    string result = "";

    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += (a[i--] - '0');
        if (j >= 0) sum += (b[j--] - '0');

        carry = sum / 10;
        sum %= 10;

        result = to_string(sum) + result;
    }

    return result;
}

string subtractStrings(string a, string b) {
    string result = "";
    int borrow = 0;

    int len_a = a.length();
    int len_b = b.length();

    int i = len_a - 1;
    int j = len_b - 1;

    while (i >= 0) {
        int digit = (a[i--] - '0') - borrow;

        if (j >= 0) digit -= (b[j--] - '0');

        if (digit < 0) {
            digit += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result = to_string(digit) + result;
    }

    return result;
}

string multiply(string X, string Y) {
    int n = max(X.length(), Y.length());

    if (n == 1) {
        return to_string((X[0] - '0') * (Y[0] - '0'));
    }

    if (n % 2 != 0) {
        n++;
        X = "0" + X;
        Y = "0" + Y;
    }

    int mid = n / 2;

    string Xl = X.substr(0, mid);
    string Xr = X.substr(mid, n - mid);
    string Yl = Y.substr(0, mid);
    string Yr = Y.substr(mid, n - mid);

    string P1 = multiply(Xl, Yl);
    string P2 = multiply(Xr, Yr);

    string term1 = P1 + string(2 * (n - mid), '0');
    string term2 = subtractStrings(subtractStrings(multiply(addStrings(Xl, Xr), addStrings(Yl, Yr)), P1), P2) + string(n - mid, '0');

    return addStrings(addStrings(term1, term2), P2);
}

int main() {
    string num1, num2;
    cin>>num1>>num2;

    string result = multiply(num1, num2);
    cout << "Result of multiplication: " << result << endl;

    return 0;
}
