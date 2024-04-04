class Solution {
public:
    int partition(int arr[],int begin,int end){
        int pivot=arr[end];
        int j=begin-1;
        for(int i=begin;i<=end;i++){
            if(arr[i]<pivot){
                j++;
                int tmp=arr[j];
                arr[j]=arr[i];
                arr[i]=tmp;
            }
        }
        int tmp=arr[end];
        arr[end]=arr[j+1];
        arr[j+1]=tmp;
        return j+1;
    }
    void Qsort(int arr[],int begin,int end){
        if(begin<end){
            int mid=partition(arr,begin,end);
            Qsort(arr,begin,mid-1);
            Qsort(arr,mid+1,end);
        }
    }
    bool closeStrings(string word1, string word2) {
        int freq1[26];
        int freq2[26];
        memset(freq1,0,sizeof(freq1));
        memset(freq2,0,sizeof(freq2));
        for(int i=0;i<word1.size();i++){
            freq1[word1[i]-'a']++;
        }
        for(int i=0;i<word2.size();i++){
             freq2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if((freq1[i]==0 && freq2[i]!=0) || (freq1[i]!=0 && freq2[i]==0))return false;
        }
        Qsort(freq1,0,25);
        Qsort(freq2,0,25);
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i])return false;
        }
        return true;
    }
};