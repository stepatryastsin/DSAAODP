#include <limits.h>
int reverse(int x) {
    long int prev = 0;
    while (x != 0) {
        int pop = x % 10;
        prev = prev * 10 + pop;
        if ((pop > 2147483647 || pop < -2147483648)) return 0;
        x /= 10;
    }
    return prev;
}