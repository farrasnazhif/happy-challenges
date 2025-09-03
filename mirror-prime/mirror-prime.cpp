#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int reverseDigits(int n){
  int reversed = 0;
  while(n > 0){
    int digit = n % 10;
    reversed = reversed * 10 + digit;
    n /= 10;
  }

  return reversed;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
     int idx = 0;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
      
        if (isPrime(i)) {
          int rev = reverseDigits(i);
          if(isPrime(rev)){
            idx++;
          }
        }
    }
    
    cout << idx;
    cout << "\n";
    return 0;
}
