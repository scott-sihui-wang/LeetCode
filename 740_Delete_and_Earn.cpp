class Solution {
public:
    void sort(vector<int>& nums,int begin,int end){
        if(begin>=end)return;
        int i=begin;
        int j=end;
        int key=nums[begin];
        while(1){
            while(nums[i]<=key){
                i++;
                if(i==end){
                    break;
                }
            }
            while(nums[j]>=key){
                j--;
                if(j==begin){
                    break;
                }
            }
            if(i>=j)break;
            int tmp=nums[i];
            nums[i]=nums[j];
            nums[j]=tmp;
        }
        nums[begin]=nums[j];
        nums[j]=key;
        sort(nums,begin,j-1);
        sort(nums,j+1,end);
    }
    int deleteAndEarn(vector<int>& nums) {
        int len=nums.size();
        sort(nums,0,len-1);
        int item[len];
        int freq[len];
        int top=0;
        item[top]=nums[0];
        freq[top++]=1;
        for(int i=1;i<len;i++){
            if(nums[i]==item[top-1]){
                freq[top-1]++;
            }
            else{
                item[top]=nums[i];
                freq[top++]=1;
            }
        }
        if(top==1){
            return item[0]*freq[0];
        }
        else{
            int val[top+1];
            val[0]=0;
            val[1]=item[0]*freq[0];
            for(int i=2;i<=top;i++){
                if(item[i-1]>item[i-2]+1){
                    val[i]=val[i-1]+item[i-1]*freq[i-1];
                }
                else{
                    val[i]=max(val[i-2]+item[i-1]*freq[i-1],val[i-1]);
                }
            }
            return val[top];
        }
    }
};