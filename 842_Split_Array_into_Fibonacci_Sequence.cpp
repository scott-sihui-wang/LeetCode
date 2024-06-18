class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        int n=num.size();
        int len=min((n-1)/2,((n>10 && num.substr(0,10)<=string("2147483647"))?10:9));
        for(int i=1;i<=(num[0]=='0'?1:len);i++){
            int len2=min((n-1)/2,((n>i+10 && num.substr(i,10)<=string("2147483647"))?10:9));
            for(int j=1;((num[i]=='0' && j<=1) || (num[i]!='0' && j<=len2 && ((j<=i && 2*i+j<=n) || (j>i && i+2*j<=n))));j++){
                vector<int> nums;
                string opr1=num.substr(0,i);
                string opr2=num.substr(i,j);
                cout<<opr1<<" "<<opr2<<endl;
                nums.push_back(stoi(opr1));
                nums.push_back(stoi(opr2));
                string result=to_string(stoll(opr1)+stoll(opr2));
                string rest=num.substr(i+j);
                while(result.size()<=rest.size()){
                    cout<<result<<endl;
                    if(result!=rest.substr(0,result.size()) || result.size()>10 || (result.size()==10 && result>string("2147483647"))){
                        break;
                    }
                    nums.push_back(stoi(result));
                    if(result.size()==rest.size()){
                        return nums;
                    }
                    rest=rest.substr(result.size());
                    opr1=opr2;
                    opr2=result;
                    result=to_string(stoll(opr1)+stoll(opr2));
                }
            }
        }
        return {};
    }
};