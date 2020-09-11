class Solution {
public:
    string getHint(string secret, string guess) {
        if(guess.length()!=secret.length())
            return "0A0B";
        int cnt1=0,cnt2=0;
        for(int i=0;i<secret.length();i++)
            if(secret[i]==guess[i])
                cnt1++;                                      //counting numbers that have same position and value
        vector<int> v(10,0);
        for(int i=0;i<secret.size();i++)
            v[secret[i]-'0']+=1;
        for(int i=0;i<guess.size();i++)
        {
            if(v[guess[i]-'0']>0)
            {
                v[guess[i]-'0']-=1;
                cnt2++;                                  //counting total numbers of equal numbers
            }
        }
        cnt2=cnt2-cnt1;
        return to_string(cnt1)+"A"+to_string(cnt2)+"B";
    }
};
