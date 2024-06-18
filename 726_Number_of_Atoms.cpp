class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string,int>>s;
        map<string,int>freq;
        s.push(freq);
        string name="";
        int num=0;
        int i=0;
        while(i<formula.size()){
            if(formula[i]>='A' && formula[i]<='Z'){
                if(name!=""){
                    s.top()[name]+=(num==0?1:num);
                    name="";
                    num=0;
                }
                name+=formula[i];
                i++;
            }
            else if(formula[i]>='a' && formula[i]<='z'){
                name+=formula[i];
                i++;
            }
            else if(formula[i]>='0' && formula[i]<='9'){
                num=num*10+formula[i]-'0';
                i++;
            }
            else if(formula[i]=='('){
                if(name!=""){
                    s.top()[name]+=(num==0?1:num);
                    name="";
                    num=0;
                }
                map<string,int>new_freq;
                s.push(new_freq);
                i++;
            }
            else if(formula[i]==')'){
                if(name!=""){
                    s.top()[name]+=(num==0?1:num);
                    name="";
                    num=0;
                }
                map<string,int>pop_freq=s.top();
                s.pop();
                i++;
                int mul=0;
                while(formula[i]>='0' && formula[i]<='9'){
                    mul=mul*10+formula[i]-'0';
                    i++;
                }
                for(auto iter=pop_freq.begin();iter!=pop_freq.end();iter++){
                    s.top()[iter->first]+=iter->second*(mul==0?1:mul);
                }
            }
        }
        if(name!=""){
            s.top()[name]+=(num==0?1:num);
            name="";
            num=0;
        }
        string ans="";
        for(auto iter=s.top().begin();iter!=s.top().end();iter++){
            ans+=iter->first;
            if(iter->second!=1){
                ans+=to_string(iter->second);
            }
        }
        return ans;
    }
};