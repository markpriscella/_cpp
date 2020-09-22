/*
    https://leetcode.com/problems/reverse-integer/

    Given a 32-bit signed integer, reverse digits of an integer.
    Example 1:
    Input: 123
    Output: 321
    Example 2:
    Input: -123
    Output: -321
    Example 3:
    Input: 120
    Output: 21
*/

class Solution {
public:
    int reverse(int x) {
        
        // variables to be used later
        int length;
        string answer;
        // long int used for overflow testing
        long int temp;
        // flag for negative values
        bool isNegative = false;
        
        // check if value is negative
        if(x < 0) {
            isNegative = true;
        }
        
        // convert value to string
        answer = to_string(x);
        // get size of string
        length = answer.size();
        
        // reverse string
        for (int i = 0; i < length / 2; i++) {
            swap(answer[i], answer[length - i - 1]);
        }
        
        // convert string back to number -> temp
        temp = stol(answer);
        //check if temp should be negative
        if(isNegative) {
            temp *= -1;
        }
        
        // test if temp has overflowed
        if(temp < -2147483647 || temp > 2147483646) {
            return 0;
        }
        // TEMP HAS NOT OVEFLOWED
        
        // test if answer needs to be negative
        if(isNegative) {
            return stoi(answer)*-1;
        }
        
        return stoi(answer);
    }
};