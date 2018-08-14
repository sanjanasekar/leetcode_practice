/*  

Creadted by : Sanjana Sekar
created on  : August 12, 2018
Source:      https://leetcode.com/explore/interview/card/top-interview-questions-medium/114/others/824/

Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> num_count_map;
        for(vector<int>::iterator i = nums.begin(); i != nums.end();++i){
            if(num_count_map.find(*i) != num_count_map.end())
                num_count_map[(*i)]++;
            else {
                num_count_map[(*i)] = 0;
                num_count_map[(*i)]++;
            }
        }
        map<int,int>::iterator i = num_count_map.begin();
        int max = i->second;
        int num = i->first;
        for(i = num_count_map.begin(); i != num_count_map.end(); ++i){
            if(max < i->second){
                max = i->second;
                num = i->first;
            }
            else 
                continue;
        }
        return num;
    }
};
