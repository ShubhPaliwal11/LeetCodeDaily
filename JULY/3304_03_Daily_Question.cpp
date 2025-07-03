/*
Question title : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/

Problem can be solved by brute force due to low constraints but the efficient solution of the problem is really beautiful
it involves using recurrsion

Firstly the brute force: 
*/
class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.length()<k){
            string temp = "";
            for(int i = 0 ; i < word.length() ; i++){
                char x = (word[i] + 1 - 'a')%26 + 'a';
                temp.push_back(x);
            }
            word = word + temp;
        }
        return word[k-1];
    }
};

/*
Here we simply build the string we are doing DAD here

Time complexity analysis:
In each iteration:

You loop over all characters in word (which is O(n) time where n = word.length())

You generate a new temp of size n

You concatenate word + temp → O(n + n) = O(n)

Let’s sum up the cost of all iterations:

Let’s denote each iteration's cost as:


Iteration 0: 1
Iteration 1: 2
Iteration 2: 4
Iteration 3: 8
...
So the total time is:

1 + 2 + 4 + 8 + ... + 2^i = 2^(i+1) - 1
Since 2^i ≥ k, this becomes:
O(2 * k) = O(k)
*/

/*
Recurrsion answer:
*/
class Solution {
public:
    char kthCharacter(int k) {
        return getKth(k, 0);
    }

    char getKth(int k, int shiftCount) {
        if (k == 1)
            return (char)('a' + shiftCount % 26);
        
        // Find the largest power of 2 less than k
        int power = 1;
        while (power * 2 < k)
            power *= 2;

        if (k <= power)
            return getKth(k, shiftCount);
        else
            return getKth(k - power, shiftCount + 1);
    }
};
/*
Time complexity: Log k 

better due to recurrsion and no extra space is used to space complexity is constant
*/
