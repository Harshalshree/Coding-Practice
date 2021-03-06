class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        
        string result;
        
        sort(A.begin(), A.end());
        
        do{
            string hour = {char(A[0] + '0'), char(A[1] + '0')}, minute = {char(A[2] + '0'), char(A[3] + '0')};
            
            result = (hour <= "23" && minute <= "59") ? (hour + ":" + minute) : result;
            cout  << char(A[0]+'0') << endl;
   
        } while (next_permutation(A.begin(), A.end()));
            
        return result;
        
    }
};