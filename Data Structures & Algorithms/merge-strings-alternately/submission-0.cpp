class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int s1 = word1.size();
        int s2 = word2.size();

        int n = s1+s2;

        string result(n, 0);

        int i = 0, j= 0, k = 0;

        while(k < n && i < s1 && j < s2){

            if(k%2 == 0){
                result[k] = word1[i];
                i++;
            }
            else{
                result[k] = word2[j];
                j++;
            }
            k++;
        }
        //cout<<i<<" "<<j<<endl;

        if(i < s1){
            while(i < s1){
                result[k] = word1[i];
                i++;
                k++;
                
            }
        }
        if(j < s2){
            while(j < s2){
                result[k] = word2[j];
                j++;
                k++;
                
            }
        }
        return result;
        
    }
};