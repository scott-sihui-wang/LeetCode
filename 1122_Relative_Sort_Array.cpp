class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        set<int> elem_arr2;
        unordered_map<int,int> freq_arr1;
        vector<int> distinct_arr1;
        for(int i=0;i<arr2.size();i++){
            elem_arr2.insert(arr2[i]);
        }
        for(int i=0;i<arr1.size();i++){
            if(elem_arr2.find(arr1[i])!=elem_arr2.end()){
                freq_arr1[arr1[i]]++;
            }
            else{
                distinct_arr1.push_back(arr1[i]);
            }
        }
        sort(distinct_arr1.begin(),distinct_arr1.end());
        vector<int>ans;
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<freq_arr1[arr2[i]];j++){
                ans.push_back(arr2[i]);
            }
        }
        for(int i=0;i<distinct_arr1.size();i++){
            ans.push_back(distinct_arr1[i]);
        }
        return ans;
    }
};