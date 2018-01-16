/*
  Author: Sanjana Sekar
  Source: https://leetcode.com/problems/first-unique-character-in-a-string/description/
  Created on: Jan 15 2018
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map_str;
        for(int i = 0;i < s.size();i++){
            if(map_str.find(s[i]) == map_str.end()){
                map_str[s[i]] = 1;
            }
            else{
                map_str[s[i]] = map_str[s[i]] + 1;
            }
        }
        /*for(unordered_map<char,int>::iterator itr = map_str.begin();itr!=map_str.end();++itr){
            cout<< (*itr).first <<"\t"<< (*itr).second<< endl;
        }*/
        int count = 0;
        for(int i = 0;i < s.size();i++){
            if(map_str[s[i]] == 1){
                return i;
            }
            else{
                count++;
            }
        }
        if(count == s.size()){
            return -1;
        }
    }
};
