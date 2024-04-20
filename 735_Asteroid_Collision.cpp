class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int _stack[10000];
        int top=-1;
        bool direction[10000];
        for(int i=0;i<asteroids.size();i++){
            if(i>0 && top>=0 && _stack[top]>0 && asteroids[i]<0){
                if(_stack[top]==-asteroids[i]){
                    top--;
                }
                else if(_stack[top]<-asteroids[i]){
                    _stack[top]=asteroids[i];
                    direction[top]=false;
                    int j=top;
                    while(j>=1 && direction[j]==false && direction[j-1]==true){
                        if(_stack[j-1]>-_stack[j]){
                            top--;
                            j--;
                        }
                        else if(_stack[j-1]==-_stack[j]){
                            top-=2;
                            j-=2;
                        }
                        else{
                            _stack[--top]=_stack[j];
                            direction[top]=false;
                            j--;
                        }
                    }
                }
            }
            else{
                _stack[++top]=asteroids[i];
                direction[top]=(asteroids[i]>0?true:false);
            }
        }
        vector<int> ans;
        for(int i=0;i<=top;i++){
            ans.push_back(_stack[i]);
        }
        return ans;
    }
};