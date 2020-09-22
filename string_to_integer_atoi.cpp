/*
    https://leetcode.com/problems/string-to-integer-atoi/

    Implement atoi which converts a string to an integer.
    The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
    The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
    If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
    If no valid conversion could be performed, a zero value is returned.
    Note:
    Only the space character ' ' is considered as whitespace character.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
    Example 1:
    Input: "42"
    Output: 42
    Example 2:
    Input: "   -42"
    Output: -42
    Explanation: The first non-whitespace character is '-', which is the minus sign.
                Then take as many numerical digits as possible, which gets 42.
    Example 3:
    Input: "4193 with words"
    Output: 4193
    Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
    Example 4:
    Input: "words and 987"
    Output: 0
    Explanation: The first non-whitespace character is 'w', which is not a numerical 
                digit or a +/- sign. Therefore no valid conversion could be performed.
    Example 5:
    Input: "-91283472332"
    Output: -2147483648
    Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/

class Solution {
public:
    int myAtoi(string str) {
        
        // boolean to flag if str is a negative number
        bool isNegative = false;
        // set to true if number string has started
        bool numberStarted = false;
        // long long int to account for overflow before testing
        long long int temp = 0;
        // result will be returned; i is used in for loop;  
        int result = 0, i;
        
        // for loop to cycle through string indices
        for(i = 0; i < str.size(); i++) {
            
            // WHITE SPACE CHECK
            if(str[i] == 32) {
                
                if( numberStarted == true ) {
                    break;
                }
                else {
                    continue;
                }
               
            }
            // '-' CHECK
            else if(str[i] == 45) {
                if( numberStarted == true ) {
                    break;
                }
                else {
                    numberStarted = true;
                    isNegative = true;
                    continue;
                }
                
            }
            // '+' CHECK
            else if(str[i] == 43) {
                if( numberStarted == true ) {
                    break;
                }
                else {
                    numberStarted = true;
                    isNegative = false;
                    continue;
                }
                
            }
            // INDEX OUT OF ASCI NUM RANGE CHECK
            else if (str[i] < 48 || str[i] > 57) {
                // break out of loop if an ascii num is not detected
                break;
            }
            
            // test if temp has overflowed
            if(temp > 2147483648 && isNegative) {
                return -2147483648;
                }
            else if(temp > 2147483647 && !isNegative)
            {
                return 2147483647;
            }
            numberStarted = true;
            
            // append new digit to the end of temp
            temp = temp*10 + str[i]-48;
            
            cout << temp << " " << i << endl;
        } // end for loop
        
        cout << temp << endl;
        // check if temp should be negative
        if(isNegative) {
            temp *= -1;
        }
        
        cout << temp << endl;
        
        // test if temp has overflowed
        if(temp < -2147483648) {
            return -2147483648;
            }
        else if(temp > 2147483647)
        {
            return 2147483647;
        }
                                
        // temp has not int overflowed so set result to temp
        result = (int)temp;
        
        // return converted string to int -> result
        return result;
    }
};