class Solution {
public:
    bool checkInclusion(string s1, string s2){

    int l1 = s1.length();
    int l2 = s2.length();

    if(l1 > l2) return false;

    vector<int> freq1(26, 0), freq2(26, 0);

    for(int i =0; i< l1; i++){
        freq1[s1[i] - 'a']++;
    }

    for(int i = 0; i< l2; i++){
        
        freq2[s2[i]-'a']++;

        if(i >= l1){
            freq2[s2[i-l1]-'a']--;
        }
        if(freq1 == freq2) return true;
    }
    return false;

}
};
