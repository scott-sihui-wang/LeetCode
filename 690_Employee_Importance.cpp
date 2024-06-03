/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void sum(unordered_map<int,Employee*>& dict, int id, int& ans){
        ans+=dict[id]->importance;
        for(int i=0;i<dict[id]->subordinates.size();i++){
            sum(dict,dict[id]->subordinates[i],ans);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        int ans=0;
        unordered_map<int,Employee*>dict;
        for(int i=0;i<employees.size();i++){
            dict[employees[i]->id]=employees[i];
        }
        sum(dict,id,ans);
        return ans;
    }
};