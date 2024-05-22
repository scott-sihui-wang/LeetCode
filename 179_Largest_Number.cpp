class Solution {
public:
    static bool compare(int& n1, int& n2){
        string s1=to_string(n1),s2=to_string(n2);
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        string ans("");
        for(int i=0;i<nums.size();i++){
            ans+=to_string(nums[i]);
        }
        if(ans[0]=='0'){
            if(ans.size()==1){
                return ans;
            }
            else{
                int j=0;
                while(j<ans.size()&& ans[j]=='0'){
                    j++;
                }
                if(j==ans.size()){
                    return string("0");
                }
                else{
                    return ans.substr(j);
                }
            }
        }
        else{
            return ans;
        }
    }
};