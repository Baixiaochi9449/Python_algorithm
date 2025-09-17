// patternÿ������ʾ����˼������2�����Ĺ�ϵ
// �����Ҫ��pattern����ƥ�䣬��ô�ڱ���nums��ʱ���������ҵ����ǵĹ�ϵ�����ǵĹ�ϵ�ͱ����һ����1��0��-1��������
// �����顣
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
        // ��Ҫ��pattern����ƥ�䣬����������Ҫ���ص������
        // ��һ��nums��������patternƥ���ģʽ���Ϳ���ת�����Ȱ�nums����ת��ֻ��0
        // 1 -1����ʽ
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
