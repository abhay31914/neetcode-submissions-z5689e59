class Solution {
public:
    int characterReplacement(string s, int k) {

        int l = 0;
        int r = 0;

        unordered_map<char, int> map;
        int max_len = 0;
        int maxFreq = 0;

        while(r < s.size()){

            map[s[r]]++;
            maxFreq = max(maxFreq, map[s[r]]);

            while((r-l+1)-maxFreq > k){
                map[s[l]]--;
                l++;
            }

            max_len = max(max_len, r-l+1);
            r++;
    
        }
        return max_len;
        
    }
};
