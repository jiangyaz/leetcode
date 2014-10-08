/* 3Sum
Given an array S of n integers, are there elements a, b, c in S such that 
a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},
    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > res;
    vector<int> sol;
    sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
	    if (i > 0 && num[i] == num[i-1]) continue;  // important
	    int target = - num[i];
	    int start = i+1, end = num.size()-1;

	    while (start < end) {
		    if (num[start] + num[end] == target) {
			    sol.push_back(num[i]);
			    sol.push_back(num[start]);
			    sol.push_back(num[end]);
			    res.push_back(sol);
			    sol.clear();
			    start++; end--;
			    // avoid duplicate solutions
			    while (num[start] == num[start-1]) 
			    	start++; 
			    while (num[end] == num[end+1]) 
			    	end--;
		    } else if (num[start] + num[end] > target) {
			    end--;
		    } else {
			    start++;
		    }
	    }
    }
    return res;
}




