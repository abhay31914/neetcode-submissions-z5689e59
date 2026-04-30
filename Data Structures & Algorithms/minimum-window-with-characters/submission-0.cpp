class Solution {
public:
    string minWindow(string s, string t) {

        if(t == "") return "";

        unordered_map<char, int> count_t, window;

        for(const char c: t){
            count_t[c]++; 
        }
        int uniq = count_t.size();
        int eleNum = 0;

        pair<int, int> res{-1, -1};
        int l = 0;
        int minLen = INT_MAX;

        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            window[c]++;

            if(count_t.count(c) && window[c] == count_t[c]){
                eleNum++;
            }

            while(uniq == eleNum){

                if((r-l+1) < minLen){
                    minLen = r-l+1;
                    res = {l, r};
                }
                window[s[l]]--;
                if(count_t.count(s[l]) && window[s[l]] < count_t[s[l]]){
                    eleNum--;
                }
            l++;
            }
        }
        return minLen <= s.size() ? s.substr(res.first, minLen): "";


        
    }
};
