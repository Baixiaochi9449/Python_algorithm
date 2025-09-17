// pattern每个数表示的意思是相邻2个数的关系
// ，如果要与pattern进行匹配，那么在遍历nums的时候，我们先找到他们的关系，他们的关系就变成了一个【1，0，-1，。。】
// 的数组。
class Solution {
private:
    vector<int> get_next(vector<int>& pattern) {
        int j = 0;
        int n = pattern.size();
        vector<int> next(n, 0);
        for (int i = 1; i < n; i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = next[j - 1];
            }
            if (pattern[i] == pattern[j])
                j++;
            next[i] = j;
        }
        return next;
    }

public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        // 想要与pattern进行匹配，还是这种需要有重叠的情况
        // 把一个nums数组有与pattern匹配的模式，就可以转换，先把nums数组转成只有0
        // 1 -1的形式
        int n = nums.size();
        vector<int> formatch(n - 1);
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1])
                formatch[i] = 1;
            else if (nums[i] == nums[i + 1])
                formatch[i] = 0;
            else
                formatch[i] = -1;
        }
        vector<int> next = get_next(pattern);
        int res = 0;
        int j = 0;
        for (int i = 0; i < n-1; i++) {
            while (j > 0 && pattern[j] != formatch[i]) {
                j = next[j - 1];
            }
            if (pattern[j] == formatch[i])
                j++;
            if (j == pattern.size()) {
                res++;
                j = next[j - 1];
            }
        }
        return res;
    }
};
