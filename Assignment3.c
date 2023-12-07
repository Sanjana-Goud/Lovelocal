Hard 3
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
Example 1:
Input: n = 13
Output: 6
Example 2:
Input: n = 0
Output: 0
 
Constraints:
0 <= n <= 109

code:
#include <stdio.h>

int countDigitOne(int n) {
    int count = 0;
    long long factor = 1;  // Represents the current digit position
    int higherPart = n;    // Represents the higher part of the number

    while (higherPart > 0) {
        int currentDigit = higherPart % 10;
        higherPart /= 10;

        count += higherPart * factor;

        if (currentDigit > 1) {
            count += factor;
        } else if (currentDigit == 1) {
            count += (n % factor) + 1;
        }

        factor *= 10;
    }

    return count;
}

int main() {
    // Example 1
    int n1 = 13;
    printf("Example 1: %d\n", countDigitOne(n1));

    // Example 2
    int n2 = 0;
    printf("Example 2: %d\n", countDigitOne(n2));

    return 0;
}
output:
Example 1: 6
Example 2: 0
