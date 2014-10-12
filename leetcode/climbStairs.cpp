/* Climbing Stairs 
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

int climbStairs(int n) {
    if (n == 1 || n == 2)
        return n;
    int num1 = 1, num2 = 2;
    for (int i = 2; i < n; i++) {
        int tmp = num2; 
        num2 += num1;
        num1 = tmp;
    }
    return num2;
}

int climbStairs(int n) {
    if (n == 1 || n == 2)
        return n;
    else 
    	return climbStairs(n-1) + climbStairs(n-2);
}