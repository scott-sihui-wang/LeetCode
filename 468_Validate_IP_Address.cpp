class Solution {
public:
    bool isNumber(string s){
        if(s.size()==0 || s.size()>3)return false;
        for(int i=0;i<s.size();i++){
            if(s[i]<'0' || s[i]>'9')return false;
        }
        if(s[0]=='0' && s.size()>1)return false;
        return true;
    }
    bool isHex(string s){
        if(s.size()==0 || s.size()>4)return false;
        for(int i=0;i<s.size();i++){
            if(!(s[i]>='0' && s[i]<='9') && !(s[i]>='a' && s[i]<='f') && !(s[i]>='A' && s[i]<='F'))return false;
        }
        return true;
    }
    string validIPAddress(string queryIP) {
        vector<string> nums;
        int dot_cnt=0,colon_cnt=0;
        int prev=-1;
        for(int i=0;i<queryIP.size();i++){
            if(queryIP[i]=='.'){
                dot_cnt++;
                nums.push_back(queryIP.substr(prev+1,i-prev-1));
                prev=i;
            }
            else if(queryIP[i]==':'){
                colon_cnt++;
                nums.push_back(queryIP.substr(prev+1,i-prev-1));
                prev=i;
            }
        }
        nums.push_back(queryIP.substr(prev+1));
        if(dot_cnt==3 && colon_cnt==0 && nums.size()==4){
            for(int i=0;i<4;i++){
                if(!isNumber(nums[i]))return string("Neither");
                if(stoi(nums[i])>255)return string("Neither");
            }
            return string("IPv4");
        }
        else if(dot_cnt==0 && colon_cnt==7 && nums.size()==8){
            for(int i=0;i<8;i++){
                if(!isHex(nums[i]))return string("Neither");
            }
            return string("IPv6");
        }
        else{
            return string("Neither");
        }
    }
};