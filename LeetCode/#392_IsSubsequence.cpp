class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0 && t.length()==0)
            return true;
        int pos = 0;
        for(int i = 0; i < t.length(); i++){
            if(t[i] == s[pos]){
                pos = pos+1;
            }
            if(pos == s.length()){
                return true;
            }
        }
        return false;
    }
};