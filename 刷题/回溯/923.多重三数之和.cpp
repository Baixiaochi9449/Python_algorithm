//用回溯做一下
class Solution {
    private:
        int result=0;
        void backtracking(vector<int>& arr,int target,int index,int curnum,int cout){
            if(cout==3){
                if(curnum==target) result++;
                return ;
            }
            for(int i=index;i<arr.size();i++){
                if(curnum+arr[i]>target) continue;
                curnum+=arr[i];
                cout+=1;
                backtracking(arr,target,i+1,curnum,cout);
                curnum-=arr[i];
                cout-=1;
            }
            return ;
        }
    public:
        int threeSumMulti(vector<int>& arr, int target) {
            backtracking(arr,target,0,0,0);
            return result;
        }
    };