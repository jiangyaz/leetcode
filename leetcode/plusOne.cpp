/* Plus One
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list. 
*/

vector<int> plusOne(vector<int> &digits) {
    int carry = 1, index = digits.size()-1;
    while (index >= 0 && carry > 0) {
        digits[index] += carry;
	    carry = (digits[index] >= 10) ? 1 : 0;
	    digits[index] %= 10;
	    index--;
    }

    if (carry > 0) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}