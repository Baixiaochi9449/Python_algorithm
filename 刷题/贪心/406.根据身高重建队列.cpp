//先按照身高排序从高到低，因为数的是前面比自己高的，再按照k插入到相应的位置
//当身高相同的时候，返回k值更小的在前面
class Solution {
    public:
        static bool compare(vector<int>& a,vector<int>& b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            else return a[0]>b[0];
        }
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            sort(people.begin(),people.end(),compare);
            vector<vector<int>> res;
            for(int i=0;i<people.size();i++){
                int position=people[i][1];
                res.insert(res.begin()+position,people[i]);   //位置，插入的内容
            }
            return res;
        }
    };
    