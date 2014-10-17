/* Pow(x,n)
Implement pow(x, n).
*/

double pow(double x, int n) {
	if (n < 0) return 1/pow(x, -n);  // 1.0/pow(x, -n-1)/x;  
	else if (n == 0) return 1.0;

	int res = pow(x, n/2);
	if (n % 2 == 0) 
		return res * res;
	else 
		return res * res * x;
}