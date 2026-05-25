class Solution {
public:

    bool isCheck(string s, int i, int j, int count){

        if(count > 1) return false;

        if(i >= j) return true;

        if(s[i] == s[j]){
            return isCheck(s, i+1, j-1, count);
        }
        else{
            return isCheck(s, i, j-1, count+1) || isCheck(s, i+1, j, count+1);
        }

    }

    bool validPalindrome(string s) {

        return isCheck(s, 0, s.size()-1, 0);
        
    }
};