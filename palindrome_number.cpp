/*
    https://leetcode.com/problems/palindrome-number/

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
Example 1:
Input: 121
Output: true
Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        // reversed will hold x backwards or reversed; 
        // temp is temporary int to perfrom operations on
        long long reversed = 0, temp = x;
        
        //if the number is negative it can't be a palindrome
        if(x < 0) {
            return false;
        }
        
        // reverse x and set it equal to reversed
        while( temp > 0 && reversed*10 < INT_MAX) {
            // make room for and append current last digit of temp to reversed
            reversed = reversed*10 + temp%10;
            // chop off last digit of temp
            temp = temp/10;
        }
        
        // see if reversed is equal to paramter x
        if (reversed == x) {
            // ITS A PALINDROME
            return true;
        }
        // NOT A PALINDROME
        return false;
    }
};