// Source : hhttps://leetcode.com/problems/intersection-of-two-linked-lists/description/
// Author : Sanjana Sekar
// Date   : 2017-12-2

/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
     while(m < n){
         n = n & (n - 1);
     }
     return n;
    }
};
