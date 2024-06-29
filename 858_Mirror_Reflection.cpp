class Solution {
public:
    int GCD(int p,int q){
        if(p<q)return GCD(q,p);
        if(p%q==0)return q;
        return GCD(q,p%q);
    }
    int mirrorReflection(int p, int q) {
        int gcd=GCD(p,q);
        int lcm=p*q/gcd;
        if((lcm/q)%2==0){
            return 2;
        }
        else if((lcm/q)%2==1 && (lcm/p)%2==1){
            return 1;
        }
        else{
            return 0;
        }
    }
};