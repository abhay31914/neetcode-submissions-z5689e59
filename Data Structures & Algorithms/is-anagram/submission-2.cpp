class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        vector<int> letter(26, 0);

        for(auto x : s){
            letter[x-'a']++;
        }

        for(auto x: t){
            if(letter[x-'a'] == 0) return false;
            letter[x-'a']--;
        }
        return true;
        
    }
};
