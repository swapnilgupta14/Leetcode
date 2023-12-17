class Solution {
public:
    int kthFactor(int n, int k) {
        if(n == 0){
            return 0;
        }
        if(n == 2){
            int th[2] = {1,2};
            if(k > 2) return -1;
            return th[k-1];
        }
        vector<int> factorList = factor(n);
        for(auto j : factorList){
            cout << j << " ";
        }
        if(k > factorList.size()){
            return -1;
        }
            return factorList[k-1];
        
    }

    vector<int> factor(int n){
        vector<int> res;
        for(int i = 1; i<n/2+1 ; i++){
            if(n%i == 0){
                res.push_back(i);
            }
        }
        res.push_back(n);
        return res;
    }
};