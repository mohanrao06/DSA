class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
         bool a=false;
        bool b=false;
        long long volume=1LL*length*width*height;
        if(length>=10000 || width>=10000 || height>=10000 || volume>=1000000000LL){
            a=true;;
        }if(mass>=100){
            b=true;
        }
        if(a&&b){
            return "Both";
        }else if(a && !b){
            return "Bulky";
        }else if(!a && b){
            return "Heavy";
        }
        return "Neither";
    }
};