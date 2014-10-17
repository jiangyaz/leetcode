/*  Sqrt(x) 
Implement int sqrt(int x).

Compute and return the square root of x.
*/

int sqrt(int x) {
   	if (x == 0 || x == 1) return x;
    long long start = 0, end = x;
    while (start <= end-2) {
	    long long mid = (start + end)/2;
	    if (mid * mid == x) {
		    return mid;
	    } else if (mid * mid > x) {
		    end = mid;     // remember this condition
	    } else {
		    start = mid;   // remember this condition
	    }
    }
    return start;
}
