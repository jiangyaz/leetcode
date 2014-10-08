/*  Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

*/

string countAndSay(int n) {
	string curStr = "1";
	
	for (int i = 1; i < n; i++) {
		char num = curStr[0];
		int count = 0; 
		string nextStr = "";
		for (int j = 0; j < curStr.length(); j++) {
			if (curStr[j] == num) {
				count++;
			} else {
				nextStr += count + '0';
				nextStr += num;
				num = curStr[j];
				count = 1;
			}
		}
		nextStr += count + '0';
		nextStr += num;
		curStr = nextStr;
	}
	return curStr;
}