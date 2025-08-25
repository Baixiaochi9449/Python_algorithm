class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            //遍历strs,先排序， 看看unordered_map里面有没有，有的话，就放到相应的数组下标里，没有的话，就建立一个，存放下标为res.size()
            vector<vector<string>> res;
            unordered_map<string,int> memo;
            for(int i=0;i<strs.size();i++){
                string key=strs[i];
                sort(key.begin(),key.end());
                if(memo.count(key)){  //字典中已经存在了
                    res[memo[key]].push_back(strs[i]);
                }
                else{  //字典中不存在
                    memo[key]=res.size();
                    vector<string> temp;
                    temp.push_back(strs[i]);
                    res.push_back(temp);
                }
            }
            return res;
        }
    };