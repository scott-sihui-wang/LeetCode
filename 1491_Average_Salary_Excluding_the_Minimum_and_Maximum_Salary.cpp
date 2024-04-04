class Solution {
public:
    double average(vector<int>& salary) {
        int len=salary.size();
        int M=INT_MIN;
        int m=INT_MAX;
        int sum=0;
        for(int i=0;i<len;i++){
            sum+=salary[i];
            if(salary[i]>M){
                M=salary[i];
            }
            if(salary[i]<m){
                m=salary[i];
            }
        }
        return (sum-M-m)*1.0/(len-2);
    }
};