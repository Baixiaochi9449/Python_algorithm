//推到公式： 推导公式两边同时异或上oriinal[i] , ----  original[i+1]=original[i] ^ derived[i]
//第一种情况，枚举original[0]=0,然后一直计算到最后一个数，判断 0 与n-1异或是否可以得到derived[n-1]
//第二种情况，枚举 。。。。。。=1
class Solution {
    public:
        bool doesValidArrayExist(vector<int>& derived) {
            int n=derived.size();
            vector<int> original(n);
            original[0]=0;
            for(int i=0;i<n-1;i++){
                original[i+1]=original[i] ^ derived[i];
            }
            if(original[n-1] ^ original[0]==derived[n-1]) return true;
    
            original[0]=1;
            for(int i=0;i<n-1;i++){
                original[i+1]=original[i] ^ derived[i];
            }
            if(original[n-1] ^ original[0]==derived[n-1]) return true;
            else return false;
            
        }
    };