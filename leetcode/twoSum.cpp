/* Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

vector<int> twoSum(vector<int> &numbers, int target) {
	unordered_map<int, int> mp;
	vector<int> res;
	for (int i = 0; i < numbers.size(); i++) {
		if (mp.find(target - numbers[i]) != mp.end()) {
			res.push_back(mp[target - numbers[i]]);
			res.push_back(i+1);
			return res;
		} else {
			mp[numbers[i]] = i+1;
		}
	}
	return res;
}