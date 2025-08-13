class Solution {
    public:
        int threeSumMulti(vector<int>& arr, int target) {
            const int MOD=1e9+7;
            unordered_map<int,int> fre;
            int res=0;
            for(int i=0;i<arr.size();i++){
                for(int j=i+1;j<arr.size();j++){
                    int T=target-arr[i]-arr[j];
                    if(fre.count(T)){
                        res=(res+fre[T])%MOD;
                    }
                }
                fre[arr[i]]++;
            }
            return res%MOD;
        }
    };