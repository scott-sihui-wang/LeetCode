class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int n1=num1.size(),n2=num2.size();
        int idx1=0,idx2=0;
        while(num1[idx1]!='+'){
            idx1++;
        }
        while(num2[idx2]!='+'){
            idx2++;
        }
        int r1=stoi(num1.substr(0,idx1)),i1=stoi(num1.substr(idx1+1,n1-idx1-2));
        int r2=stoi(num2.substr(0,idx2)),i2=stoi(num2.substr(idx2+1,n2-idx2-2));
        int r=r1*r2-i1*i2;
        int i=r1*i2+r2*i1;
        return string(to_string(r)+"+"+to_string(i)+"i");
    }
};