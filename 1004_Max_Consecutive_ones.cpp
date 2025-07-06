/**
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in 
the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
 */

/*
Topics: Majorly sliding window and two pointers 
*/

/*
intution:
ham log hamesha ye check kr rhe hai ke kitne number of times ham k ko use kr sakte hai

uske hisab se ham jab bhi 0 incounter hota hai 

lets take an example : [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1] with k = 3

in the first step we have 0 and the number of operations we can perform is 3 so we use that operation 
increase our window size and decrease the amount of operations left to 2

now in the next iteration we do the same till we reach a point where we can no longer apply any operations 
ie k <= 0 


now using this loop 
        while (k < 0) {
                if (nums[j] == 0) {
                    k++;
                }
                j++;
            }
    we increase the value of k 

    and then update the size of the window with - 
    answer = max(answer,i-j+1)
*/

// striver:

class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int j = 0;
            int ans = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    k--;
                }
                while (k < 0) {
                    if (nums[j] == 0) {
                        k++;
                    }
                    j++;
                }
                ans = max(ans, i - j + 1);
            }
            return ans;
        }
    };

// GOAT lee:

public int longestOnes(int[] A, int K) {
    int i = 0, j;
    for (j = 0; j < A.length; ++j) {
        if (A[j] == 0) K--;
        if (K < 0 && A[i++] == 0) K++;
    }
    return j - i;
}

// I still have to figure out how this is working but will revise a few times

// date : 2nd July
