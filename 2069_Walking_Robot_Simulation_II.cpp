class Robot {
private:
    int w,h,len,s;
public:
    Robot(int width, int height) {
        w=width;
        h=height;
        len=(w+h-2)*2;
        s=0;
    }
    
    void step(int num) {
        s+=num;
    }
    
    vector<int> getPos() {
        int s1=s%len;
        if(s1>=0 && s1<w){
            return {s1,0};
        }
        else if(s1<w+h-1){
            return {w-1,s1-w+1};
        }
        else if(s1<2*w+h-2){
            return {(w-1-(s1-(w+h-2))),h-1};
        }
        else{
            return {0,(h-1-(s1-(2*w+h-3)))};
        }
    }
    
    string getDir() {
        int s1=s%len;
        if(s==0 || (s1>0 && s1<w)){
            return "East";
        }
        else if(s1>=w && s1<w+h-1){
            return "North";
        }
        else if(s1>= w+h-1 && s1<2*w+h-2){
            return "West";
        }
        else{
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */