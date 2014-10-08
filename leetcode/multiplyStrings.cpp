/* Multiply Strings
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

string multiply(string num1, string num2) {
    string multiply(string num1, string num2) {
    int l1 = num1.length();
    int l2 = num2.length();
    // Convenience for later processing
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    vector<int> res(l1+l2, 0);
    
    // Step 1: multiply
    for (int i = 0; i < l1; i++) 
	    for (int j = 0; j < l2; j++) 
		    res[i+j] += (num1[i] - '0') * (num2[j] - '0');

	// Step 2: make each slot to be single digit
    int carry = 0;
    for (int i = 0; i < l1+l2; i++) {
        res[i] += carry;
        carry = res[i] / 10;
        res[i] = res[i] % 10;
    }

    // Step 3: get rid of leading 0
    int index = l1 + l2 - 1;
    while (res[index] == 0) index--;
    if (index < 0) return "0";

    // Step 4: convert to string
    string out;
    for (int i = index; i >= 0; i--) {
	    out.push_back(res[i] + '0');
    }       
    return out;
}