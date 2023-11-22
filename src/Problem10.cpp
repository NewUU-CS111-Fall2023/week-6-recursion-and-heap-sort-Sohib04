#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string sortVowels(string s) {
    vector<pair<char, int>> vowels;

    for (int i = 0; i < s.length(); ++i) {
        if (isVowel(s[i])) {
            vowels.push_back({s[i], i});
        }
    }

    sort(vowels.begin(), vowels.end());

    for (int i = 0, j = 0; i < s.length(); ++i) {
        if (isVowel(s[i])) {
            s[i] = vowels[j++].first;
        }
    }

    return s;
}

int main() {
    string input = "newUzbekistanUniversity";
    string result = sortVowels(input);
    
    cout << "Original string: " << input << endl;
    cout << "Resulting string: " << result << endl;

    return 0;
}
