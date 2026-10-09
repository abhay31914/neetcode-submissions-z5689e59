// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {

        int n = pairs.size();

        if(n == 0) return {};

        vector<vector<Pair>> result;
         result.push_back(pairs);
        

        for(int i = 1; i < n; i++){
           

            Pair ele = pairs[i];
            int j = i;

            while( j > 0 && ele.key < pairs[j-1].key){
                pairs[j] = pairs[j-1];
                j--;
            }
            pairs[j] = ele;

            result.push_back(pairs);
        }
        

        return result;

    }
};
