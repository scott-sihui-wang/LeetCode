class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int begin=0;
        int end=letters.size()-1;
        while(begin!=end){
            int mid=(begin+end)/2;
            if(letters[mid]<=target){
                begin=mid+1;
            }
            else if(letters[mid]>target){
                end=mid;
            }
        }
        if(letters[begin]<=target){
            return letters[(begin+1)%(end+1)];
        }
        else{
            return letters[begin];
        }
    }
};