#include <iostream>
#include <utility>
#include <cmath> 
#include <algorithm>

using namespace std;

int power10(int n) {
    int res = 1;
    for (int i = 0; i < n; i++) res *= 10;
    return res;
}

int return_digits(int x) {
    if (x / 10 == 0) return 1;
    else return 1 + return_digits(x / 10);
}

int karatsuba(int x, int y) {
    if (x < 10 || y < 10) return x * y;
    else {
        int n = max(return_digits(x), return_digits(y));
        int half = n / 2;

        int multiplier = power10(half);

        int a = x / multiplier;
        int b = x % multiplier;
        int c = y / multiplier;
        int d = y % multiplier;

        int ac = karatsuba(a, c);
        int bd = karatsuba(b, d);
        int ad_plus_bc = karatsuba((a + b), (c + d)) - ac - bd;

        return ac * power10(half * 2) + (ad_plus_bc * multiplier) + bd;
    }
}

int main() {
    int a, b;
    cout << "Enter the value of first number: ";
    cin >> a;
    cout << "Enter the value of second number: ";
    cin >> b;
    cout << endl;

    cout << "a*b = " << karatsuba(a, b) << endl;
}
