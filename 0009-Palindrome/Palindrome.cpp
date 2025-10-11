#include <iostream>
using namespace std;

bool isPalindrome()
{
    int x, rev;
    cin >> x;
    int safe = x;
    rev = 0;
    if (x < 0 || (x != 0 && x % 10 == 0)) {
        return false;
    }
    while (x > rev) {
        rev = rev * 10 + x % 10;
        x = x / 10;
    }
    return (x == rev) || (x == rev / 10);
}

int main() {
    bool p=isPalindrome();
    if(p==true){
        cout<<"true"<<endl;
     }
     else{
        cout<<"false"<<endl;
     }
}