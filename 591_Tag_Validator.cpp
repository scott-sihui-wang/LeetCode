class Solution {
public:
    bool isTagName(string& s){
        if(s.size()<1 || s.size()>9) return false;
        for(int i=0;i<s.size();i++){
            if(s[i]<'A' || s[i]>'Z')return false;
        }
        return true;
    }
    bool startTag(string& code, int& i, stack<string>& tags){
        if(code[i]!='<')return false;
        i++;
        int start=i;
        while(i<code.size() && code[i]!='>'){
            i++;
        }
        if(i>=code.size())return false;
        string tag_name=code.substr(start,i-start);
        bool ans=isTagName(tag_name);
        if(ans){
            i++;
            tags.push(tag_name);
        }
        return ans;
    }
    bool endTag(string& code, int& i, stack<string>& tags, int& idx){
        if(i+1>=code.size() || code[i]!='<' || code[i+1]!='/')return false;
        i+=2;
        int start=i;
        while(i<code.size() && code[i]!='>'){
            i++;
        }
        if(i>=code.size())return false;
        string tag_name=code.substr(start,i-start);
        bool ans=isTagName(tag_name);
        if(ans){
            if(!tags.empty() && tags.top()==tag_name){
                tags.pop();
                idx=i;
                i++;
                return ans;
            }
            else{
                return !ans;
            }
        }
        else{
            return ans;
        }
    }
    bool cDATA(string& code, int& i){
        string template_start=string("<![CDATA[");
        string template_end=string("]]>");
        for(int j=0;j<template_start.size();j++){
            if(i>=code.size() || code[i++]!=template_start[j]){
                return false;
            }
        }
        if(i>=code.size())return false;
        while(i<code.size()){
            while(i<code.size() && code[i]!='>'){
                i++;
            }
            if(i>=code.size())return false;
            bool b=true;
            for(int j=0;j<template_end.size();j++){
                if(code[i-j]!=template_end[template_end.size()-1-j]){
                    b=false;
                    break;
                }
            }
            i++;
            if(b){
                return true;
            }
        }
        return false;
    }
    bool isValid(string code) {
        stack<string> tags;
        int last_end_idx=-1;
        int i=0;
        string first_tag,last_tag;
        if(startTag(code,i,tags)==false)return false;
        first_tag=tags.top();
        while(i<code.size()){
            while(i<code.size() && code[i]!='<'){
                i++;
            }
            if(i<code.size() && code[i]=='<'){
                bool b;
                if(i+1<code.size() && code[i+1]=='!'){
                    b=cDATA(code,i);
                }
                else if(i+1<code.size() && code[i+1]=='/'){
                    if(!tags.empty()){
                        last_tag=tags.top();
                    }
                    else{
                        return false;
                    }
                    b=endTag(code,i,tags,last_end_idx);
                }
                else{
                    b=startTag(code,i,tags);
                }
                if(!b)return b;
            }
        }
        return last_end_idx==code.size()-1 && tags.empty() && first_tag==last_tag;        
    }
};