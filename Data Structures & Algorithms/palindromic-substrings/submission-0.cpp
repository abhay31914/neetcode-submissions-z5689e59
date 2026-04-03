class Solution {
public:
    int odd_l(string& s, int i, int n){
    int j = i-1;
    int k = i+1;
    int count = 1;

    while(j>= 0&& k< n && s[j] == s[k]){
        count++;
        j--;
        k++;
    }

    return count;
}
int even_l(string& s, int i, int n){
    int j = i-1;
    int k = i;
    int count = 0;

    while(j>= 0&& k< n && s[j] == s[k]){
        count++;
        j--;
        k++;
    }
    return count;
}

int countSubstrings(string s) {

    int n = s.size();

    int max_result = 0;

    for(int i = 0; i< n; i++){
        
        max_result += odd_l(s, i, n);
        max_result += even_l(s, i, n);
    }
    return max_result;
    
}
};
