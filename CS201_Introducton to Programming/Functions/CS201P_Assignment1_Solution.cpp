#include <iostream>
using namespace std;

// Function to check whether a single digit is prime or not
bool isPrime(int digit) {
    // Prime digits are: 2, 3, 5, 7
    if (digit == 2 || digit == 3 || digit == 5 || digit == 7)
        return true;
    else
        return false;
}

// Function to count total prime digits in student ID
int countPrimeDigits(long studentId) {
    int count = 0;
    while (studentId > 0) {
        int digit = studentId % 10;  // Get last digit
        if (isPrime(digit))
            count++;                 // Increment count if prime
        studentId = studentId / 10;  // Remove last digit
    }
    return count;
}

// Function to calculate sum of all prime digits
int sumPrimeDigits(long studentId) {
    int sum = 0;
    while (studentId > 0) {
        int digit = studentId % 10;
        if (isPrime(digit))
            sum += digit;
        studentId /= 10;
    }
    return sum;
}

// Function to calculate average of prime digits
double averagePrimeDigits(long studentId) {
    int sum = 0, count = 0;
    while (studentId > 0) {
        int digit = studentId % 10;
        if (isPrime(digit)) {
            sum += digit;
            count++;
        }
        studentId /= 10;
    }
    if (count == 0)
        return 0; // Avoid divide-by-zero error
    return (double)sum / count;
}

// Function to find the maximum prime digit
int maxPrimeDigit(long studentId) {
    int max = -1;  // Initialize with -1 to detect if no prime found
    while (studentId > 0) {
        int digit = studentId % 10;
        if (isPrime(digit)) {
            if (digit > max)
                max = digit;
        }
        studentId /= 10;
    }
    return max;
}

// Function to find the minimum prime digit
int minPrimeDigit(long studentId) {
    int min = 10;  // Initialize with 10 (greater than any digit)
    bool found = false;
    while (studentId > 0) {
        int digit = studentId % 10;
        if (isPrime(digit)) {
            if (digit < min)
                min = digit;
            found = true;
        }
        studentId /= 10;
    }
    if (!found)
        return -1;  // No prime digits found
    return min;
}

int main() {
    // Step 1: Display complete VU Student ID
    cout << "Complete VU Student ID: BC240200582" << endl;

    // Step 2: Store the numerical part in a variable
    long studentId = 240200582;

    // Step 3: Display numerical part
    cout << "Numerical part of Student ID: " << studentId << endl;

    // Step 4: Display all prime digits
    cout << "Prime digits in your ID are: ";
    long temp = studentId;
    while (temp > 0) {
        int digit = temp % 10;
        if (isPrime(digit))
            cout << digit << " ";
        temp /= 10;
    }
    cout << endl;

    // Step 5: Count of prime digits
    cout << "Total number of prime digits: " << countPrimeDigits(studentId) << endl;

    // Step 6: Sum of prime digits
    cout << "Sum of prime digits: " << sumPrimeDigits(studentId) << endl;

    // Step 7: Average of prime digits
    cout << "Average of prime digits: " << averagePrimeDigits(studentId) << endl;

    // Step 8: Maximum and minimum prime digits
    cout << "Maximum prime digit: " << maxPrimeDigit(studentId) << endl;
    cout << "Minimum prime digit: " << minPrimeDigit(studentId) << endl;

    return 0;
}
