
/* Edit Distance
Given two words word1 and word2, find the minimum number of steps required to convert 
word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

int minDistance(string word1, string word2) {
	int l1 = word1.length();
	int l2 = word2.length();
	vector<vector<int> >table(l1+1, vector<int>(l2+1, 0));

	// Set up initial conditions
	for (int i = 0; i <= l1; i++) 
		table[i][0] = i;
	for (int j = 0; j <= l2; j++) 
		table[0][j] = j;
    
    // Populate the DP table
    for (int i = 1; i <= l1; i++) {
    	for (int j = 1; j <= l2; j++) {
    		if (word1[i-1] == word2[j-1]) {
    			table[i][j] = table[i-1][j-1];
    		} else {
    			table[i][j] = min(table[i-1][j], table[i][j-1]) + 1;
    			table[i][j] = min(table[i][j], table[i-1][j-1] + 1);
    		}
    	}   
    }  
    return table[l1][l2];
}