/*
Created by : Sanjana Sekar
Created on : August 15, 2018
Source     : https://leetcode.com/problems/random-pick-index/description/

Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
*/

class Solution {
    unordered_map<int, vector<int> > map_index;
public:
    Solution(vector<int> nums) {
        for(vector<int>::iterator itr = nums.begin(); itr!= nums.end(); ++itr){
             map_index[(*itr)].push_back((itr- nums.begin()));
        }
    }
    
    int pick(int target) {
        if(map_index.find(target) != map_index.end()){
            int no_of_indices = map_index[target].size();
            int pick_index = rand() % no_of_indices;
            return map_index[target][pick_index];
        }
        else
            return -1;
    }
};
