class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream s(preorder);
        string node;
        int cnt=1;
        while(getline(s,node,',')){
            cnt--;
            if(cnt<0)return false;
            if(node!="#"){
                cnt+=2;
            }
        }
        return cnt==0;
    }
};