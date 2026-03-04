#include <iostream>
#include <string>
using namespace std;

int main() {
    string pattern, text;
    cin >> text >> pattern;

    for (int i = 0; i <= (int)text.length() - (int)pattern.length(); i++) {
        bool match = true;
        for (int j = 0; j < pattern.length(); j++) {  // < not <=
            if (text[i+j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) cout << "Match found at: " << i << endl;  // outside inner loop
    }
}
