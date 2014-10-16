/* Reverse Words in a String

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

void reverseWords(string &s) {
	stack<string> sta;
	int index = 0; 
	while (index < s.length()) {
		string word;
		while (s[index] == ' ' && index < s.length()) index++;
		while (s[index] != ' ' && index < s.length()) {
			word += s[index++];
		}
		if (word.length() > 0) sta.push(word);
	} 
	
	s.clear();
	while (!sta.empty())  {
		s += sta.top() + ' ';
		sta.pop();
	}    
	if (s.length() > 0) s.pop_back();
}