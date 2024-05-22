/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s[0]!='[')return NestedInteger(stoi(s));
        stack<NestedInteger> st;
        bool sgn=false,isNum=false;
        int num=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='-'){
                sgn=true;
                isNum=true;
            }
            if(s[i]>='0' && s[i]<='9'){
                isNum=true;
                num=num*10+s[i]-'0';
            }
            if(s[i]==','||s[i]==']'){
                if(isNum){
                    num=sgn?-num:num;
                    st.top().add(NestedInteger(num));
                    sgn=false;
                    num=0;
                    isNum=false;
                }
                if(s[i]==']'){
                    NestedInteger tmp=st.top();
                    st.pop();
                    if(st.empty()){
                        return tmp;
                    }
                    else{
                        st.top().add(tmp);
                    }
                }
            }
            if(s[i]=='['){
                st.push(NestedInteger());
            }
        }
        return st.top();
    }
};