/*
    https://leetcode.com/problems/longest-palindromic-substring/

    Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
    Example 1:
    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        
        // starting position and current max palindrome length
        int startPos = 0, maxLength = 1;
        // left and right indices while expanding from center
        int left, right;
        
        // check if string s is empty
        if(s.size() == 0)
        {
            return s;
        }
        
        // cycle through middle positions to expand around
        for(int i=0; i < s.size(); i++)
        {
            // set left and right starting indices to i
            left=i;
            right=i;
            // get the middle character
            char mid = s[i];
            //check for repeating characters
            
            while(s[right] == mid)
            {
                //move right index one to the right
                right++;
                //make sure right index is in bounds
                if(right == s.size())
                {
                    //break from loop if not in bounds
                    break;
                }
            }
            
            // compensate for first iteration of the loop above
            right--;
            // everything between left and right are the same character
            // so set i where right is and continue checking from there
            i = right;
            
            // start expanding left and right away from the center - i
            while(left >= 0 && right < s.size())
            {
                // check if left and right are not the same character
                if(s[left] != s[right])
                {
                    // break out of loop if theyre not the same character
                    break;
                }
                //move left and right to check next indices
                left--;
                right++;
            }
            
            // compensate for first iteration of the loop above
            left++;
            right--;
            
            // check if current right and left create a bigger palindrome
            // than current max palindrome length - maxLength
            if(right - left + 1 > maxLength)
            {
                // set maxLength to new longest palindrome length
                maxLength = right - left + 1;
                // set startPos to new longest palindrome to left index
                startPos = left;
            }
        }
        
        // return substring with startPos and maxLength of the curernt longets palindrome
        return s.substr(startPos, maxLength);
    }
    
};