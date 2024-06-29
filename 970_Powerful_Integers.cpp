class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int>num;
        for(int i=0;(x>1 && pow(x,i)+1<=bound)||(x==1 && i<1 && pow(x,i)+1<=bound);i++){
            for(int j=0;(y>1 && pow(x,i)+pow(y,j)<=bound)||(y==1 && j<1 && pow(x,i)+pow(y,j)<=bound);j++){
                num.insert(pow(x,i)+pow(y,j));
            }
        }
        vector<int>ans;
        for(auto iter=num.begin();iter!=num.end();iter++){
            ans.push_back(*iter);
        }
        return ans;
    }
};