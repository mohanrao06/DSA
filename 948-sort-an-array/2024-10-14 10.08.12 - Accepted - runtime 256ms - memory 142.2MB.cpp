class Solution {
public:
    void merge(vector<int>& arr, int start, int end, int mid){
    vector<int> temp(end-start+1);
    int left=start;
    int right=mid+1;
    int index=0;
    while (left<= mid && right <=end)
    {
        if(arr[left]<=arr[right]){
            temp[index]=arr[left];
            index++;
            left++;
        }
        else{
            temp[index]=arr[right];
            index++;
            right++;
        }
    }
    while(left<=mid){
        temp[index]=arr[left];
        index++;
        left++;
    }
    while(right<=end){
        temp[index]=arr[right];
        index++;
        right++;
    }
    index=0;
    while(start<=end){
        arr[start]=temp[index];
        start++;
        index++;
    }
    

}


void mergeSort(vector<int>& arr, int start, int end)
{
    if (start == end) // base case
        return;
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);   // left
    mergeSort(arr, mid + 1, end); // right
    merge(arr, start, end, mid);
}
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};