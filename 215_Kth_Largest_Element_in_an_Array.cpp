class Solution {
public:
    void shiftUp(int heap[],int idx){
        while(idx>0 && heap[(idx-1)/2]>heap[idx]){
            int tmp=heap[(idx-1)/2];
            heap[(idx-1)/2]=heap[idx];
            heap[idx]=tmp;
            idx=(idx-1)/2;
        }
    }
    void shiftDown(int heap[],int idx,int available){
        while(idx*2+1<available){
            if(idx*2+2<available){
                if(heap[idx]>heap[idx*2+1] || heap[idx]>heap[idx*2+2]){
                    if(heap[idx*2+1]<heap[idx*2+2]){
                        int tmp=heap[idx*2+1];
                        heap[idx*2+1]=heap[idx];
                        heap[idx]=tmp;
                        idx=idx*2+1;
                    }
                    else{
                        int tmp=heap[idx*2+2];
                        heap[idx*2+2]=heap[idx];
                        heap[idx]=tmp;
                        idx=idx*2+2;
                    }
                }
                else{
                    break;
                }
            }
            else{
                if(heap[idx]>heap[idx*2+1]){
                    int tmp=heap[idx*2+1];
                    heap[idx*2+1]=heap[idx];
                    heap[idx]=tmp;
                    idx=idx*2+1;
                }
                else{
                    break;
                }
            }
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int heap[100001];
        int available=0;
        for(int i=0;i<nums.size();i++){
            if(available<k){
                heap[available]=nums[i];
                shiftUp(heap,available);
                available++;
            }
            else if(nums[i]>heap[0]){
                heap[0]=nums[i];
                shiftDown(heap,0,available);
            }
        }
        return heap[0];
    }
};