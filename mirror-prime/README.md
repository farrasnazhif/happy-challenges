# "Mirror Prime" Numbers

A short description of the project goes here.

We will call the "mirror prime" if the reversed prime numbers are prime as well.

**Short Example :**

- Prime numbers between 10 and 20 = 11, 13, 17, 19
- Reversed prime numbers = 11, 31, 71 (91 is not prime)

## Input

[ 10 25 ]

## Output

[ 3 ]

## Code Explanation

### **isPrime** function

```cpp
  bool isPrime(int n) {
    // First
    if (n < 2) return false;
    // Second
    if (n == 2) return true;
    // Third
    if (n % 2) return false;
    // Fourth
    for(int i = 3; i * i <= n; i += 2){
      if(n % i == 0) return false;
    }
    // Last
    return true;
  }
```

I'll explain the step based on the step I commented in the code.

Prime number is a number that can only be divided by 1 and itself. However, 0 and 1 is not a prime, so the **first** computation is returning any numbers lower than 2 as non prime numbers.

Second step, the only even prime number is 2. Therefore we always return 2 as a prime.

Third, any numbers that can be divided by 2 is not a prime.

Fourth, iterate only odd numbers due to what i said previously on second step.

**But, why are we start with i = 3?** Well it's because primes with one digit is the odd numbers (1, 3, 5, 7) except 9. So, in the iteration, we'll check whether odd numbers greater than 9 are prime or not.

Additionally, not all odd numbers greater than 9 are prime. For that reason, we need to check if the number can be divided other than itself or not. The operation is the one that i commented below.

```cpp
  for(int i = 3; i * i <= n; i += 2){
    // This
    if(n % i == 0) return false;
  }
```

Lastly, always return even numbers as prime numbers.

### **reverseDigits** function

```cpp
  int reverseDigits(int n){
  int reversed = 0;
  while(n > 0){
    int digit = n % 10;
    reversed = reversed * 10 + digit;
    n /= 10;
  }

  return reversed;
  }
```

The next step we need to reverse the prime number. In order to do that, I'll explain this with simple visualization.

Suppose we have (n = 17),

```
  int reversed = 0

  First Iteration
  while(17 > 0) {
    int digit = 17 % 10 = 7;
    reversed = 0 * 10 + 7 = 7;
    n = 17/10 = 1;
  }

  Second,
  while(1 > 0){
    int digit = 1 % 10 = 1;
    reversed = 7 * 10 + 1 = 71
    n = 1/10 = 0;
  }

  return reversed = 71;
```

That is my simple visualization, hope it helps :).

### **main** function

```c
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
```

- a & b are the intervals.
- idx is to add the total number required as a prime numbers.

The for loop will run from the interval of a and b.

First, it will check the origin numbers as prime or not.

Second, we reverse the prime numbers with `reverseDigits` function.

Lastly, we check again whether the reversed prime numbers is a prime or not. If its a prime, the index will be incremented until the last reversed prime numbers.

Short example, if the reversed numbers are 31, 11, and 71. So, the index will be 3.
