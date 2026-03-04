#include <iostream>
#include <string>
#include <math.h>
using namespace std;
#define d 10

void rabinKarp(string pat, string text, int q) {
    int n = text.length();
    int m = pat.length();
    int h = (int)pow(d, m-1) % q;
    int p = 0, t = 0;

    for (int i = 0; i < m; i++) {
        p = (d*p + pat[i]) % q;
        t = (d*t + text[i]) % q;
    }

    for (int s = 0; s <= n-m; s++) {          // ✅ <= to include last position
        if (p == t) {
            int i;
            for (i = 0; i < m; i++)           // ✅ verify each character
                if (pat[i] != text[s+i]) break;
            if (i == m) cout << "Match found at: " << s << endl;  // ✅ print once
        }

        if (s < n-m)
            t = (d*(t - text[s]*h) + text[s+m] + q*d*q) % q;  // ✅ correct rolling hash
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    rabinKarp(pattern, text, 101);
}
