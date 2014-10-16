// Single Number II
// Given an array of integers, every element appears three times 
// except for one. Find that single one.

int singleNumber(int A[], int n) {
	vector<int> num(32, 0);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 32; k++) {
			num[k] += (A[i] >> k) & 1;   // it's "&" not "^" !!
			if (num[k] == 3) num[k] = 0;  
		}
	}        
	int res = 0, div = 1;
	for (int k = 0; k < 32; k++) {
		res += num[k] * div;
		div = div * 2;
	}
	return res;
}