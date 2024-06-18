class Solution {
public:
    string smallestString(string s) {
        int i=0;
        while(i<s.size()){
            while(i<s.size() && s[i]!='a'){
                s[i]--;
                i++;
            }
            if(i==s.size()){
                return s;
            }
            else{
                if(i>0){
                    return s;
                }
                else{
                    while(i<s.size() && s[i]=='a'){
                        i++;
                    }
                    if(i==s.size()){
                        s[s.size()-1]='z';
                        return s;
                    }
                    else{
                        while(i<s.size() && s[i]!='a'){
                            s[i]--;
                            i++;
                        }
                        return s;
                    }
                }
            }
        }
        return s;
    }
};