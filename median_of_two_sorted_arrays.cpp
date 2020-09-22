/*
    https://leetcode.com/problems/median-of-two-sorted-arrays/

    Given two sorted arrays nums1 and nums2 of size m and n respectively.
    Return the median of the two sorted arrays.
    Follow up: The overall run time complexity should be O(log (m+n)).
 
    Example 1:
    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000
    Explanation: merged array = [1,2,3] and median is 2.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector to combine num1 and num2
        vector<int> allNums;
        // i used in for loop
        int i = 0;
        // will be the size of nums1 and nums2 combined
        int size = 0;
        // needed when size is even
        int a, b;

        // add all items from nums1 to allNums
        for(i=0; i < nums1.size(); i++) {
            allNums.push_back(nums1[i]);
        }
        // add all items from nums2 to allNums
        for(i=0; i < nums2.size(); i++) {
            allNums.push_back(nums2[i]);
        }
        
        // set size to size of allNums
        size = allNums.size();
        // sort allNums in ascending order
        sort(allNums.begin(), allNums.end());
        
        // CALCULATE - allNums size is ODD
        if (size % 2 == 1) {
            // median is int at middle index
            return allNums[size/2];
        }
        // CALCULATE - allNums size is EVEN
        else {
            a = size/2 -1;
            b = size/2;
            // median is average between allNums[a] and allNums[b]
            return ((double)allNums[a]+(double)allNums[b]) / 2;
        }
        
        // return 1 in case of failure
        return 1;
        
    }
};