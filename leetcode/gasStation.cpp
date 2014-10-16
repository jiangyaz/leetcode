/* Gas Station
There are N gas stations along a circular route,
where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] 
of gas to travel from station i to its next station (i+1). 
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, 
otherwise return -1.
*/

// O(N)
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int N = gas.size();
    int curSum = gas[N-1] - cost[N-1];
    int maxIndex = N-1, maxSum = curSum;

    for (int i = N-2; i >= 0; i--) {
	    curSum += gas[i] - cost[i];
	    if (curSum > maxSum) {
		    maxSum = curSum;
		    maxIndex = i;
	    }
    }
    if (curSum < 0) return -1;
    return maxIndex;   
}

// O(N^2)
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	int N = gas.size();
	for (int i = 0; i < N; i++) {
		int step = 0;
		int gasLeft = 0;
		while (step < N) {
			int index = (i + step) % N;
			gasLeft += (gas[index] - cost[index]);
			if (gasLeft <= 0) break;
			step++;
		}
		if (step == N) return i;
	}
	return -1;     
}