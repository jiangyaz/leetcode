/* Permutation Sequence 

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

int permute(int n) {
	int out = 1;
	while (n > 0) {
		out *= n;
		n--;
	}
	return out;
}

string getPermutation(int n, int k) {
	string res;
	string numbers = "123456789";  // this is important

	for (int i = 1; i <= n; i++) {
		int N = permute(n-i);
		int index = (k-1)/N;
		res.push_back(numbers[index]);
		numbers.erase(numbers.begin() + index);
		k = (k - 1) % N + 1;  // k -= index * N
	}  
	return res;     
}