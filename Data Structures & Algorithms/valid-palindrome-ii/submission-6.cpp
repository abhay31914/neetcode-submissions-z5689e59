class Solution { //self solved, but the time complexity is exponential
public:

    bool isCheck(string s, int i, int j){

        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;

    }

    bool validPalindrome(string s) {

        int i = 0;
        int j = s.size()-1;

        while(i < j){

            if(s[i] != s[j]){
                return isCheck(s, i+1, j) || isCheck(s, i, j-1);
            }
            i++;
            j--;
        }
        return true;
        
    }
};