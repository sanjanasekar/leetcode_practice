// Source : https://leetcode.com/problems/maximal-rectangle/description/
// Author : Sanjana Sekar
// Date   : 2017-12-04

/***********************************************
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.

Using my function of largestRectangleArea for this solution.
************************************************/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> row;
        int max_area;
        if(matrix.size() > 0){
            
            for(vector<char>::iterator itr1 = matrix[0].begin(); itr1 != matrix[0].end(); ++itr1){
              
                    row.push_back(((*itr1) - '0'));
                    //cout << " row" << row.at((itr1 - matrix[0].begin())) << endl;     
            }
            max_area = largestRectangleArea(row); 
            //cout << "max_area\t" << max_area << endl;
            for(vector<vector<char> >:: iterator itr = matrix.begin() + 1; itr!= matrix.end(); ++itr){
                for(vector<char>::iterator itr1 = (*itr).begin(); itr1 != (*itr).end(); ++itr1){
                   if((*itr1) == '1'){
                       row[((itr1) - (*itr).begin())] += ((*itr1) - '0');
                   }
                   else{
                       row[((itr1) - (*itr).begin())] = 0;
                   }
                   //cout << " row" << row.at((itr1 - (*itr).begin())) << endl; 
                }
                int max_area_per_row = largestRectangleArea(row);  
                    if(max_area_per_row > max_area){
                        max_area = max_area_per_row;
                        //cout << "max_area2\t" << max_area << endl;
                    }
            }
            return max_area;     
        }
        else{
            return 0;
        }
         
    }
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
