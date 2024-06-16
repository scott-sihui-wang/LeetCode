class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2){
        return v1[1]<v2[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),compare);
        priority_queue<int>q;
        int endTime=0;
        for(int i=0;i<courses.size();i++){
            q.push(courses[i][0]);
            endTime+=courses[i][0];
            if(endTime>courses[i][1]){
                endTime-=q.top();
                q.pop();
            }
        }
        return q.size();
    }
};