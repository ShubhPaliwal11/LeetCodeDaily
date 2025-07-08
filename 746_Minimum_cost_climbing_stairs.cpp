// 746. Min Cost Climbing Stairs

/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/

/*
the question is tagged with dynamic programming but we can do this without using extra space:

But first lets see the extra space solution:
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        vector<int> dp(N,1000);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2 ; i < cost.size() ; i++){
            dp[i] = min(cost[i]+dp[i-1],cost[i]+dp[i-2]);
        }
        int n = dp.size();
        return min(dp[n - 1], dp[n - 2]);
    }
};

// my only doubt is that vo last wala return statmenet , initially I returned only the last index but that was incorrect 
// kyuki har index se 2 ka jump mar sakte hai to , OH OK OK OK , I got it

// now O 1 space solution:

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = cost[0];
        int prev1 = cost[1];
        
        for (int i = 2; i < cost.size(); ++i) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return min(prev1, prev2);  
    }
};
// kinda straightforward and cute solution!

// thanks for reading folks!
