
// Source : https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// Author : Sanjana Sekar
// Date   : 2017-12-4

/*************************************************************************************** 
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
***************************************************************************************/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack_index;
        int max_hist_area = 0;
        int top_of_stack = 0;
        int area_inc_top = 0;
        int i = 0 ;
        while(i < heights.size()){
            if(stack_index.empty() || heights[stack_index.top()] <= heights[i]){
                stack_index.push(i++);
            }
            else{
                top_of_stack = stack_index.top();
                stack_index.pop();
                area_inc_top = heights[top_of_stack] * (stack_index.empty() ? i : i - stack_index.top() - 1);
                
                if(max_hist_area < area_inc_top){
                    max_hist_area = area_inc_top;
                }
            }
        }
        while(!stack_index.empty()){
            top_of_stack = stack_index.top();
            stack_index.pop();
            area_inc_top = heights[top_of_stack] * (stack_index.empty() ? i : i - stack_index.top() - 1);
                
            if(max_hist_area < area_inc_top){
                max_hist_area = area_inc_top;
            }
        }
       return max_hist_area; 
        
    }
};
