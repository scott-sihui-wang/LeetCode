class Solution {
public:
    int queryMin(int *segTree, int l, int r){
        if(r<=l)return INT_MAX;
        if(l%2==1 && r%2==1){
            return min(min(segTree[l],segTree[r-1]),queryMin(segTree,l+1,r-1));
        }
        else if(l%2==1){
            return min(segTree[l],queryMin(segTree,l+1,r));
        }
        else if(r%2==1){
            return min(segTree[r-1],queryMin(segTree,l,r-1));
        }
        else{
            return queryMin(segTree,l/2,r/2);
        }
    }
    int findLeftB(int *segTree, int minHeight, int begin, int end, int len){
        if(begin>end){
            return end+1;
        }
        else if(begin==end){
            if(minHeight<=segTree[begin+len]){
                return begin;
            }
            else{
                return end+1;
            }
        }
        else if(begin==end-1){
        	if(minHeight<=segTree[begin+len] && minHeight<=segTree[end+len]){
        		return begin;
			}
			else if(minHeight<=segTree[end+len]){
				return end;
			}
			else{
				return end+1;
			}
		}
        else{
            int mid=(begin+end)/2;
            int res=queryMin(segTree,mid+len,end+len+1);
            if(res>=minHeight){
                return findLeftB(segTree,minHeight,begin,mid,len);
            }
            else{
                return findLeftB(segTree,minHeight,mid+1,end,len);
            }
        }
    }
    int findRightB(int *segTree, int minHeight, int begin, int end, int len){
        if(begin>end){
            return begin-1;
        }
        else if(begin==end){
            if(minHeight<=segTree[begin+len]){
                return end;
            }
            else{
                return begin-1;
            }
        }
        else if(begin==end-1){
        	if(minHeight<=segTree[begin+len] && minHeight<=segTree[end+len]){
        		return end;
			}
			else if(minHeight<=segTree[begin+len]){
				return begin;
			}
			else{
				return begin-1;
			}
		}
        else{
            int mid=(begin+end)/2;
            int res=queryMin(segTree,begin+len,mid+len+1);
            if(res>=minHeight){
                return findRightB(segTree,minHeight,mid,end,len);
            }
            else{
                return findRightB(segTree,minHeight,begin,mid-1,len);
            }
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int len=heights.size();
        if(len==1)return heights[0];
        int segTree[2*len];
        memset(segTree,0,sizeof(segTree));
        for(int i=len;i<2*len;i++){
            segTree[i]=heights[i-len];
        }
        for(int i=len-1;i>0;i--){
            segTree[i]=min(segTree[2*i],segTree[2*i+1]);
        }
        int ans=0;
        for(int i=0;i<len;i++){
            int bound_l=min(findLeftB(segTree,heights[i],0,i-1,len),i);
            int bound_r=max(findRightB(segTree,heights[i],i+1,len-1,len),i);
            ans=max(ans,(bound_r-bound_l+1)*heights[i]);
        }
        return ans;
    }
};