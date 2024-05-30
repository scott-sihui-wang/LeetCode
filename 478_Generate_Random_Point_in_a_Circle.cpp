class Solution {
public:
    double x,y,r;
    Solution(double radius, double x_center, double y_center) {
        x=x_center;
        y=y_center;
        r=radius;
    }
    
    vector<double> randPoint() {
        double theta=((double)rand()/RAND_MAX)*2*M_PI;
        double radius=sqrt((double)rand()/RAND_MAX)*r;
        vector<double> ans={x+radius*cos(theta),y+radius*sin(theta)};
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */