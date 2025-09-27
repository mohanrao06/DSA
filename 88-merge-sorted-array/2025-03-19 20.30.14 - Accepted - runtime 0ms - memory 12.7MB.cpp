class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n);
        int k=0;
        int l=0;
        int r=0;
        while(l<m && r<n){
            if(nums1[l]<=nums2[r]){
                ans[k]=nums1[l];
                l++;
                k++;
            }else{
                ans[k]=nums2[r];
                r++;
                k++;
            }
        }
        while(l<m){
            ans[k]=nums1[l];
            l++;
            k++;
        }
        while(r<n){
            ans[k]=nums2[r];
            r++;
            k++;
        }
        for(int i=0;i<m+n;i++){
            nums1[i]=ans[i];
            
        }

    }
};