// 921. Minimum Add to Make Parentheses Valid

/*
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

 

Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3
 

Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'.
*/

MY FIRST WRONG SOLUTION:
class Solution {
public:
    int minAddToMakeValid(string s) {
      if(s.length()==0){
        return 0;
      } 
      int left = 0;
      for(int i = s.length() - 1  ; i >= 0 ; i--){
        if(s[i] == ')'){
            left++;
        }else{
            left--;
        }
      }
      return abs(left);
    }
};

CORRECT SOLUTION:
class Solution {
public:
    int minAddToMakeValid(string s) {
      if(s.length()==0){
        return 0;
      } 
      int answer = 0 , open = 0;
      for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '('){
            open++;
        }else{
            if(open>0){
                open--;
            }else{
                answer++;
            }
        }
      }
      return answer + open;
    }
};
