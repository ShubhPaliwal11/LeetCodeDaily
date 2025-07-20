// this quesiton is fucking phenomenol

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.

// SOLUTION:

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        for(int i = 0 ; i < nums.size() ; i++){
            int index = abs(nums[i]) - 1;
            if(nums[index]>0){
                nums[index]=nums[index]*(-1);
            }else{
                answer.push_back(abs(nums[i]));
            }
        }
        return answer;
    } 
};

this is the most optimum solution 


// navie solution just for the sake yk

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> hash(1e5+10,0);
        for(int i = 0 ; i < nums.size() ; i++){
            hash[nums[i]]++;
        }
        vector<int>answer;
        for(int i = 0 ; i < hash.size() ; i++){
            if(hash[i]==2){
                answer.push_back(i);
            }
        }
        return answer;
    }
};
