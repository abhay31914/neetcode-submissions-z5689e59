class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> s;

        for(int ele: nums){

            if(s.find(ele) != s.end()) return true;
            s.insert(ele);
        }
        return false;
        
    }
};