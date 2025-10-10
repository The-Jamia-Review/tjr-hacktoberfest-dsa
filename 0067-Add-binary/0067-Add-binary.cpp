#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(const string& a, const string& b) {
    string result = "";
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        result.push_back((sum % 2) + '0');
        carry = sum / 2;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a, b;

    cout << "Enter first binary string: ";
    cin >> a;

    cout << "Enter second binary string: ";
    cin >> b;

    string sum = addBinary(a, b);
    cout << "Binary Sum: " << sum << endl;

    return 0;
}
