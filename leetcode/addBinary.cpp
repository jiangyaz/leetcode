/* Add binary
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

string addBinary(string a, string b) {
    int L = max(a.length(), b.length());
    string out = "";
    int carry = 0;

    for (int i = 0; i < L; i++) {
    	// Tricky part
        int aInt = a.length() > i ? a[a.length()-i-1]-'0' : 0;
        int bInt = b.length() > i ? b[b.length()-i-1]-'0' : 0;

        int sum = aInt + bInt + carry;
        carry = sum/2;
        out.insert(out.begin(), sum % 2 + '0'); // user "insert", instead of +=
    }

    if (carry > 0) {
        out.insert(out.begin(), '1');
    }

    return out;
}