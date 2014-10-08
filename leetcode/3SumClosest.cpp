/* 3Sum Closest 
Given an array S of n integers, find three integers in S such that the sum is 
closest to a given number, target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.
*/


int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int closestSum, minDiff = INT_MAX;

    for (int i = 0; i < num.size(); i++) {
    	int targetSum = target - num[i];
    	int start = i+1, end = num.size() - 1;
    	
    	while (start < end) {
    		int diff = abs(num[start] + num[end] - targetSum);
    		if (diff < minDiff) {
    			minDiff = diff;
    			closestSum = num[start] + num[end] + num[i];
    		}
    		if (diff == 0) {
    			return target;
    		} else if (num[start] + num[end] > targetSum) {
    			end--;
    		} else {
    			start++;
    		}
    	}
    }
    return closestSum;      
}