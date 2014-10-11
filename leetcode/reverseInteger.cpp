/* Reverse Integer 
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

int reverse(int x) {
    long res = 0;
    bool flag = true;
    if (x < 0) {
    	flag = false;
    	x = -x;
    }
    while (x > 0) {
    	res = res * 10 + x % 10;
    	x /= 10;
    }
    if (res > INT_MAX) {
    	return flag ? INT_MAX : INT_MIN;
    }
    return flag ? res : -res;
}