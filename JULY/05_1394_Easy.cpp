// Title : 1394. Find Lucky Integer in an Array

/*
Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.

Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
Example 3:

Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.
 

Constraints:

1 <= arr.length <= 500
1 <= arr[i] <= 500
*/

// First Solution: 

class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> hash(501,0);
        for(int i = 0 ; i < arr.size() ; i++){
            hash[arr[i]]++;
        }
        for(int i = hash.size()-1 ; i >= 1 ; i--){
            if(hash[i]==i){
                return i;
            }
        }
        return -1;
    }
};

// this one is pretty much brute force no optimizations or anything


// 2nd solution: 

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int answer = -1;
        for(int i = 1 ; i < 501 ; i++){
            int toFind = i;
            int Freq = i;
            int count = 0;
            for(int j = 0 ; j < arr.size() ; j++){
                if(arr[j]==toFind){
                    count++;
                }
            }
            if(count == i){
                answer = max(ans,i);
            }
        }
        return answer;
    }
};

// now this solution is O ( n ) * 500 , idk if that counts as still linear but yeah we are not using any extra space
// so that's cool!
