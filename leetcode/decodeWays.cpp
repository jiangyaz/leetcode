/*  Decode Ways 
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.
*/

int numDecodings(string s) {
	if (s.length() == 0) return 0;
	vector<int> d(s.length(), 0);

	// Initial condition, tricky!
	if (s[0] != '0') d[0] = 1;
	if (s.length() == 1) return d[0];

	if (s[0] == '1' || (s[0] == '2' && s[1] <='6'))
		d[1]++;
	if (s[1] != '0' && s[0] != '0')  
		d[1]++;

	// Populate the DP table
	for (int i = 2; i < s.length(); i++) {
		if (s[i] != '0')
			d[i] += d[i-1];
		if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <='6'))
			d[i] += d[i-2];
	}

	return d[s.length()-1];
}