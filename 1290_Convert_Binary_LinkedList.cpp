/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

Example 1:

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
 
Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
*/

// Most Optimum solution: 

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int numberOfNodes = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            numberOfNodes++;
            temp = temp -> next;
        }
        numberOfNodes--;
        int answer = 0;
        while(head!=NULL){
            int x = head -> val;
            answer += x*pow(2,numberOfNodes);
            numberOfNodes--;
            head = head -> next;
        }
        return answer;
    }
};

// naive O (n) space complexity solution:
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector <int> ans;
        int sum = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            int x = temp->val;
            ans.push_back(x);
            temp = temp->next;
        }
        for(int i = ans.size() - 1 , j = 0 ; i >= 0 ; i-- , j++){
            int a = pow(2,j);
            int y = ans[i]*(a);
            sum = sum + y;
        }
        return sum;
    }
};
