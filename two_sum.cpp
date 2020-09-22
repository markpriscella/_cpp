/*
    https://leetcode.com/problems/two-sum/

    Given an array of integers nums and and integer target, return the indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.
 
    Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Output: Because nums[0] + nums[1] == 9, we return [0, 1]
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int i, k, a, b;
        
        vector<int> solution;
        
        // loop to get first value from nums
        for(i = 0; i < nums.size(); i++) {
            // loop to get second value from nums
            for(k = 0; k < nums.size(); k++) {
                // make sure the same index isnt used twice AND
                // see if the two indice's value add up to the target value
                if(i != k && nums[i] + nums[k] == target) {
                    // values add up to target so add indices to 
                    solution.push_back(i);
                    solution.push_back(k);
                    return solution;
                    }
                }
            }
        cout << nums.size();
        return solution;   
    }
};