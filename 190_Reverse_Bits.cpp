class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t sol=0;
        for(int i=0;i<32;i++){
            sol=(sol<<1)+n%2;
            n=n>>1;
        }
        return sol;
    }
};