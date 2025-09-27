class Solution {
public:
    bool isOk(vector<int>& ranks,int cars,long long mid){
        long long cars_done=0;
        for(auto r:ranks){
            long long c2=mid/r;
            long long c=floor(sqrt(c2));
            cars_done+=c;
        }
        return (cars_done>=cars);
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=1;
        long long r=1e14;
        
        while(l<r){
            long long mid=l+(r-l)/2;
            if(isOk(ranks,cars,mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};