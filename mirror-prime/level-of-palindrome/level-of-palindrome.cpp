#include <iostream>
using namespace std;

int isReversed(int num){
    int reversed = 0;
    while(num > 0){
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return reversed;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    int n;
    cin>>n;
    cout<< isReversed(n);
}
