/* Add binary
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

string addBinary(string a, string b) {
    string out = "";
    int carry = 0, pA = a.length()-1, pB = b.length()-1;

    while (pA >= 0 || pB >= 0 || carry > 0) {
    	int aVal = (pA >= 0) ? a[pA]-'0' : 0;
    	int bVal = (pB >= 0) ? b[pB]-'0' : 0;

    	int sum = aVal + bVal + carry;
    	carry = sum/2;
    	out.insert(out.begin(), sum%2 +'0');
    	pA--; pB--;
    }

    return out;
}