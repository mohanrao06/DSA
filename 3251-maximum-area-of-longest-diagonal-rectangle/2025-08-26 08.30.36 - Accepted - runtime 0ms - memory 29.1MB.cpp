class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
       
        double d1=0;
        int ans=0;
        for(int i=0;i<dimensions.size();i++){
            int l2=dimensions[i][0];
            int w2=dimensions[i][1];
            double d2=sqrt(l2*l2+w2*w2);
            int area=l2*w2;
            if(d1<d2 || (d1==d2 && area>ans)){
                d1=d2;
                ans=area;
            }

        }
        return ans;


    }
};