/* String to Integer
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely 
(ie, no given input specs). You are responsible to gather all the input 
requirements up front.

*/

int atoi(const char *str) {
    long long res = 0;
    bool isPositive = true;
    while (*str == ' ') {str++;}
	if (*str == '-') {
	    isPositive = false;
	    str++;
    } else if (*str == '+') {
	    str++;
    }
    while (*str != '\0') {
	    if (*str < '0' || *str > '9') break;
	    res = res * 10 + (*str - '0');
	    if (res > INT_MAX) {
		    return isPositive ? INT_MAX : INT_MIN;
	    }
	    str++;
    }
    return isPositive ? res: -res;
}