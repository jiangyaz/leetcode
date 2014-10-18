/* Divide Two Integer
Divide two integers without using multiplication, division and mod operator.

*/

int divide(int dividend, int divisor) {
	bool isPos = true;
	if (dividend < 0) { dividend = -dividend; isPos = !isPos;} 
	if (divisor < 0) { divisor = -divisor; isPos = !isPos;}   

	if (divisor > dividend) return 0;
	if (divisor == 1) return dividend;

	int res = 0, div = 1; 
	int tmp = divisor;
	while (tmp < dividend) {
		tmp <<= 1;
		div <<= 1;
	}   

	while (dividend >= divisor) {
		while (dividend > tmp) {
			dividend -= tmp;
			res += div;
		}
		tmp >>= 1;
		div >>= 1;
	}  
	return isPos? res: -res;
}