class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans="";
        int i=0;
        while(i<dominoes.size()){
            if(dominoes[i]=='.'){
                int start=i;
                while(i<dominoes.size() && dominoes[i]=='.'){
                    i++;
                }
                int end=i;
                if(start==0 && end==dominoes.size()){
                    return dominoes;
                }
                else if(start==0){
                    if(dominoes[end]=='L'){
                        ans+=string(end,'L');
                    }
                    else{
                        ans+=string(end,'.');
                    }
                }
                else if(end==dominoes.size()){
                    if(dominoes[start-1]=='R'){
                        ans+=string(end-start,'R');
                    }
                    else{
                        ans+=string(end-start,'.');
                    }
                }
                else{
                    if(dominoes[start-1]==dominoes[end]){
                        ans+=string(end-start,dominoes[start-1]);
                    }
                    else if(dominoes[start-1]=='L' && dominoes[end]=='R'){
                        ans+=string(end-start,'.');
                    }
                    else if(dominoes[start-1]=='R' && dominoes[end]=='L'){
                        ans+=string((end-start)/2,'R');
                        if((end-start)%2!=0){
                            ans+=string(1,'.');
                        }
                        ans+=string((end-start)/2,'L');
                    }
                }
            }
            else{
                ans+=string(1,dominoes[i]);
                i++;
            }
        }
        return ans;
    }
};