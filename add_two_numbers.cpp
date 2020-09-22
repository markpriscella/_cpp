/*
    https://leetcode.com/problems/add-two-numbers/

    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    Example:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //create new list to return and keep track of head
        ListNode* head = new ListNode();
        // create current node pointer and set it to head
        ListNode* current = head;
        // boolean flag incase we need to carry a digit
        bool carry = false;
        
        head->val = l1->val + l2->val;
        
        if(head->val >= 10) {
            head->val = head->val % 10;
            carry = true;
        }
        
        
        //set l1 and l2 to next node in singley-linked list
        l1 = l1->next;
        l2 = l2->next;
        
        //make sure l1 or l2 exist
        while(l1 != NULL || l2 != NULL || carry) {
            ListNode* temp = new ListNode();
            //both l1 and l2 exist
            if(l1 != NULL && l2 != NULL) {
                temp->val = l1->val + l2->val;
            }
            //l1 exists and l2 does not
            else if(l1 != NULL && l2 == NULL) {
                temp->val = l1->val;
            }
            //l1 does not exist and l2 exists
            else if(l1 == NULL && l2 != NULL){
                temp->val = l2->val;
            }
            
            //check if carry is flagged and add one if so
            if(carry) {
                temp->val++;
            }
            //set carry to false after dealing with it above
            carry = false;
            //check if carry needs to be flagged
            if(temp->val >= 10) {
                temp->val = temp->val % 10;
                carry = true;
            }
            //make current node point to temp (next node in singley-linked list)
            current->next = temp;
            current = temp;
            //set l1 and l2 to next node in singley-linked list
            if(l1 != NULL) {l1 = l1->next;}
            if(l2 != NULL) {l2 = l2->next;}
            
        }
        
        
        return head;
    }
};