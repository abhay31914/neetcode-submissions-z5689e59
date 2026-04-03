class Solution {
public:

    string odd_l(string& s, int i, int n){
        int j = i-1;
        int k = i+1;

        while(j>= 0&& k< n && s[j] == s[k]){
            j--;
            k++;
        }

        return s.substr(j+1, k - j-1);
    }
    string even_l(string& s, int i, int n){
        int j = i-1;
        int k = i;

        while(j>= 0&& k< n && s[j] == s[k]){
            j--;
            k++;
        }
        return s.substr(j+1, k - j-1);
    }

    string longestPalindrome(string s) {

        int n = s.size();

        string max_result;

        for(int i = 0; i< n; i++){
            
            string s1 = even_l(s, i, n);
            string s2 = odd_l(s, i, n);

            string cur_str = (s1.size() > s2.size()) ? s1: s2;

            max_result = (cur_str.size() > max_result.size()) ? cur_str: max_result;
        }
        return max_result;
        
    }
};
