/*
    https://leetcode.com/problems/longest-substring-without-repeating-characters/

    Given a string, find the length of the longest substring without repeating characters.
    Example 1:
    Input: "abcabcbb"
    Output: 3 
    Explanation: The answer is "abc", with the length of 3.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSize = s.size();
        
        int ans = 0, i = 0, k = 0, j = 0;
        
        if(maxSize == 1) {
            return maxSize;
        }
        
    
            for(k = 0; k < maxSize; k++) {
                if(i == k) {
                    continue;
                }
                else if(s[i] == s[k]) {
                    i++;
                }
                else {
                    for(j = i+1; j < k; j++) {
                        if(s[j] == s[i]) {
                            i = j;
                        }
                        else if(s[j] == s[k]) {
                            i = j + 1;
                        }
                    }
                }
                ans = max(ans,k-i+1);
            }
        
        
        return ans;
    }
    
};