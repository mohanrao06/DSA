class ProductOfNumbers {
public:
    vector<int> arr;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        if (k > arr.size()) return 0;
        long long  sum=1;
        for(int i=arr.size()-1;k>0 &&  i>=0;i--){
            sum*=arr[i];
            k--;
        }
        return sum;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */