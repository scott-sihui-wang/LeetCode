class Solution {
public:
    struct TrieNode{
        TrieNode* next[2];
        bool isEnd;
        TrieNode(){
            next[0]=nullptr;
            next[1]=nullptr;
            isEnd=false;
        }
    };
    string numToStr32(int num){
        string ans;
        if(num==0){
            return string(32,'0');
        }
        while(num>0){
            ans+=(num%2)+'0';
            num=num/2;
        }
        if(ans.size()<32){
            ans+=string(32-ans.size(),'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void insert(TrieNode* root,string& s){
        TrieNode* ptr=root;
        for(int i=0;i<s.size();i++){
            if(ptr->next[s[i]-'0']==nullptr){
                ptr->next[s[i]-'0']=new TrieNode();
            }
            ptr=ptr->next[s[i]-'0'];
        }
        ptr->isEnd=true;
    }
    string inv(string& s){
        string ans(s.size(),' ');
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                ans[i]='1';
            }
            else if(s[i]=='1'){
                ans[i]='0';
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root=new TrieNode();
        vector<string> str;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            str.push_back(numToStr32(nums[i]));
            insert(root,str[i]);
        }
        for(int i=0;i<str.size();i++){
            int XOR=0;
            string str_inv=inv(str[i]);
            TrieNode *ptr=root;
            for(int j=0;j<32;j++){
                if(ptr->next[str_inv[j]-'0']!=nullptr){
                    ptr=ptr->next[str_inv[j]-'0'];
                    XOR=XOR*2+1;
                }
                else{
                    ptr=ptr->next[str[i][j]-'0'];
                    XOR=XOR*2;
                }
            }
            ans=max(ans,XOR);
        }
        return ans;
    }
};