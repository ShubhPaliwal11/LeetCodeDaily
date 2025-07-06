/*
1865. Finding Pairs With a Certain Sum

You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

Add a positive integer to an element of a given index in the array nums2.
Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
Implement the FindSumPairs class:

FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.
 

Example 1:

Input
["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
[[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]
Output
[null, 8, null, 2, 1, null, null, 11]

Explanation
FindSumPairs findSumPairs = new FindSumPairs([1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]);
findSumPairs.count(7);  // return 8; pairs (2,2), (3,2), (4,2), (2,4), (3,4), (4,4) make 2 + 5 and pairs (5,1), (5,5) make 3 + 4
findSumPairs.add(3, 2); // now nums2 = [1,4,5,4,5,4]
findSumPairs.count(8);  // return 2; pairs (5,2), (5,4) make 3 + 5
findSumPairs.count(4);  // return 1; pair (5,0) makes 3 + 1
findSumPairs.add(0, 1); // now nums2 = [2,4,5,4,5,4]
findSumPairs.add(1, 1); // now nums2 = [2,5,5,4,5,4]
findSumPairs.count(7);  // return 11; pairs (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) make 2 + 5 and pairs (5,3), (5,5) make 3 + 4
 

Constraints:

1 <= nums1.length <= 1000
1 <= nums2.length <= 105
1 <= nums1[i] <= 109
1 <= nums2[i] <= 105
0 <= index < nums2.length
1 <= val <= 105
1 <= tot <= 109
At most 1000 calls are made to add and count each.
*/

// personal observation : 
/*
so this was my first concurrency question there were few mistakes which I made like initializing the vector size before the c
constructor and errors like:

Line 21: Char 20: warning: ISO C++17 does not permit structured binding declaration in a condition [-Wbinding-in-condition]
   21 |             if(hash[toFind]!=0){
      |                    ^~~~~~~~
Line 21: Char 20: error: decomposition declaration cannot be declared with type 'hash'; declared type must be 'auto' or reference to 'auto'

although abhi bhi sab samajh nahi aya hai but we will learn stuff for sure!

Now the naive solution:
*/

// TC : O(N^2) , so IT WONT PASS!

class FindSumPairs {
public:
vector <int> ans1 ;
vector <int> ans2 ; 
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        ans1 = nums1;
        ans2 = nums2;
    }
    
    void add(int index, int val) {
        ans2[index] += val;
    }
    
    int count(int tot) {
        int count = 0;
        for(int i = 0 ; i < ans1.size() ; i++){
            for(int j = 0 ; j < ans2.size() ; j++){
                if(ans1[i]+ans2[j]==tot){
                    count++;
                }
            }
        }
        return count;
    }
};

// the solution which passes: 
// using unorderd_map reason:
/*
🧠 What's Going On?
In your code, you're trying to do:

hash[ans2[i]]++;
This works only if hash supports arbitrary keys like ans2[i]. That’s the key point.

❌ Why vector<int> hash doesn’t work:
A vector is indexed by non-negative integers only, and you must know the maximum value in advance.

So if:

ans2[i] = 1000005
Then doing:
hash[1000005]++;
will cause out-of-bounds error unless you've resized hash to at least size 1000006.

✅ Why unordered_map<int, int> Works:
An unordered_map can handle any integer key, including large numbers or non-contiguous keys (like 5, 1002, 10^6, etc.).

It automatically creates the key if it doesn't exist.

No need to resize or worry about bounds.

So this:
hash[ans2[i]]++;
works even if ans2[i] is some random large number.
*/

class FindSumPairs {
public:
    vector<int> ans1;
    vector<int> ans2;
    unordered_map<int, int> hash;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        ans1 = nums1;
        ans2 = nums2;
        for (int i = 0; i < ans2.size(); i++) {
            hash[ans2[i]]++;
        }
    }

    void add(int index, int val) {
        hash[ans2[index]]--;
        ans2[index] += val;
        hash[ans2[index]]++;
    }

    int count(int tot) {
        int count = 0;
        for (int i = 0; i < ans1.size(); i++) {
            int toFind = tot - ans1[i];
            if (hash[toFind] != 0) {
                count += hash[toFind];
            }
        }
        return count;
    }
};
