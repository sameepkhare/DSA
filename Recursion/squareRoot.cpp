#include <iostream>

int sqrtHelper(int x, int low, int high) {
    if (low > high) {
        // If we overshoot, return high which will be the largest integer
        // whose square is less than or equal to x
        return high;
    }

    int mid = low + (high - low) / 2;
    long long midSquared = (long long)mid * mid; // Use long long to avoid overflow

    if (midSquared == x) {
        return mid;
    } else if (midSquared < x) {
        // Mid squared is less than x, it is a potential candidate,
        // but there might be a closer value in the upper half
        return sqrtHelper(x, mid + 1, high);
    } else {
        // Mid squared is more than x, look in the lower half
        return sqrtHelper(x, low, mid - 1);
    }
}

int sqrt(int x) {
    return sqrtHelper(x, 0, x);
}

int main() {
    int x = 10;
    std::cout << "The integer square root of " << x << " is " << sqrt(x) << std::endl;

    x = 25;
    std::cout << "The integer square root of " << x << " is " << sqrt(x) << std::endl;

    return 0;
}


