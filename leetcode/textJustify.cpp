/* Text Justification
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/

vector<int> getSpaceNum(int totalNum, int slots) {
    vector<int> out(slots, 0);
    int index = 0;
    while (totalNum > 0) {
        out[index++]++;
        if (index == slots) index = 0;
        totalNum--;
    }
    return out;
}

vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> res;
    int index = 0;

    while (index < words.size()) {
        string row;
        vector<int> endIndex;
        int len = 0;
        while (words[index].length() < L-len+1) {
            row += words[index] + " ";
            len += words[index].length() + 1;
            endIndex.push_back(len-1);
            index++;
            if (index == words.size()) break;
        }
        row.pop_back();

        // Process row
        int wordNum = endIndex.size()-1;
        if (wordNum == 0 || index == words.size()) {
            string blankStr(L-row.size(), ' ');
            row += blankStr;
        } else {
            vector<int> slots = getSpaceNum(L-row.size(), wordNum);
            for (int i = wordNum-1; i >= 0; i--) {
                string blankStr(slots[i], ' ');
                row.insert(endIndex[i], blankStr);
            }
        }
        res.push_back(row);
    }
    return res;
}









