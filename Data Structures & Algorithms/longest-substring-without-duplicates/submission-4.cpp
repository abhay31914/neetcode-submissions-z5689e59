class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    int n = s.size();

    unordered_map<char, int> map;

    int max_len = 0;
    int i = 0;
    int j = 0;

    while(j < n){

        if(map.find(s[j]) != map.end()){
            i = max(i, map[s[j]]+1);
        }

        max_len = max(max_len, j-i+1);       
        map[s[j]] = j;
        j++;
        
    }
    return max_len;  
        
    }
};
