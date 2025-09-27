class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int i=0,j=0;
        int ele1=n/2-1;
        int ele2=n/2;
        int cnt=0;
        int indele1=-1;
        int indele2=-1;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==ele1)indele1=nums1[i];
                if(cnt==ele2)indele2=nums1[i];
                cnt++;
                i++;
            }else{
                if(cnt==ele1)indele1=nums2[j];
                if(cnt==ele2)indele2=nums2[j];
                cnt++;
                j++;
            }
        }
        while(i<n1){
            if(cnt==ele1)indele1=nums1[i];
                if(cnt==ele2)indele2=nums1[i];
                cnt++;
                i++;
        }
        while(j<n2){
            if(cnt==ele1)indele1=nums2[j];
                if(cnt==ele2)indele2=nums2[j];
                cnt++;
                j++;
        }
        if(n%2!=0)return (double)indele2;
        else{
            return (double)(indele1+indele2)/2;
        }
    }
};