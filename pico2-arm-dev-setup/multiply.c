#include <stdbool.h>

bool odd(int n) { return n & 0x01; }
int half(int n) { return n >> 1; }

static int mult_acc(int r, int n, int a) {
    while (1) {
        if (odd(n)) {
  	        r += a;
  	        if (n == 1) return r;
  	    }
  	    n = half(n);
  	    a += a;
    }
}

int multiply(int n, int a) {
    while (!odd(n)) {
        a += a;
        n = half(n);
    }
    if (n == 1) return a;
    return mult_acc(a, half(n - 1), a + a);
}
