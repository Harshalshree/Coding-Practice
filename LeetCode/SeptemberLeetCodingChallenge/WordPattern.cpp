class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(pattern=="" and str=="")return false;
        unordered_map<char,string> dp;
        unordered_map<string,int> dpr;
        stringstream gek(str);
        string tmp;
        for(int i=0;i<pattern.length();i++){
            getline(gek,tmp,' ');
            if(tmp==""){
                return false;
            }
            if(dp[pattern[i]]==""){
                dp[pattern[i]]=tmp;
                dpr[tmp]++;
                if(dpr[tmp]>1){
                    return false;
                }
            }else{
                if(dp[pattern[i]]!=tmp){
                    return false;
                }
            }
        }
        int c=0;
        while(getline(gek,tmp,' ')){
            c++;
        }
        if(c>0)
            return false;
        return true;
    }
};
