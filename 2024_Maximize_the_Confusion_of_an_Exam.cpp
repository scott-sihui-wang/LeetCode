class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left=0,right=0;
        int len_T=0,cnt_F=0;
        while(right<answerKey.size()){
            while(right<answerKey.size() && cnt_F<=k){
                if(answerKey[right]=='F'){
                    cnt_F++;
                }
                right++;
            }
            if(cnt_F>k){
                len_T=max(len_T,right-left-1);
            }
            else{
                len_T=max(len_T,right-left);
            }
            while(left<=right && right<answerKey.size() && cnt_F>k){
                if(answerKey[left]=='F'){
                    cnt_F--;
                }
                left++;
            }
        }
        left=0;
        right=0;
        int len_F=0,cnt_T=0;
        while(right<answerKey.size()){
            while(right<answerKey.size() && cnt_T<=k){
                if(answerKey[right]=='T'){
                    cnt_T++;
                }
                right++;
            }
            if(cnt_T>k){
                len_F=max(len_F,right-left-1);
            }
            else{
                len_F=max(len_F,right-left);
            }
            while(left<=right && right<answerKey.size() && cnt_T>k){
                if(answerKey[left]=='T'){
                    cnt_T--;
                }
                left++;
            }
        }
        return max(len_F,len_T);
    }
};