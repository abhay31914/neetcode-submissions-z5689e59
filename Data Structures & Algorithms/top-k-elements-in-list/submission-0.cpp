class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> count;
        int n = nums.size();

        for(int x: nums){
            count[x]++;
        }

        vector<vector<int>> bucket(n);

        for(auto& [key, value]: count){
            bucket[value-1].push_back(key);
        }

        vector<int> result;

        for(int i = n-1; i>= 0; i--){

            for(int element: bucket[i]){
                result.push_back(element);
                k--;
                if(k < 1) return result;
                
            }
        }

    }
};
