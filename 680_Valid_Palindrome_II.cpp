class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0;
        while(i<n/2 && s[i]==s[n-1-i]){
            i++;
        }
        if(i<n/2){
            int j=i+1;
            while(j<=n/2 && s[j]==s[n-j]){
                j++;
            }
            if(j>n/2){
                return true;
            }
            else{
                int j=i;
                while(j<n/2 && s[j]==s[n-j-2]){
                    j++;
                }
                if(j>=n/2){
                    return true;
                }
                else{
                    return false;
                }

            }
        }
        else{
            return true;
        }
    }
};