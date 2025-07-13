class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const int mod = 1e9 + 7;
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        // 计算水平方向最大间隔
        int max_h = horizontalCuts.empty() ? h : horizontalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            max_h = max(max_h, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        if (!horizontalCuts.empty()) {
            max_h = max(max_h, h - horizontalCuts.back());
        }
        
        // 计算垂直方向最大间隔
        int max_w = verticalCuts.empty() ? w : verticalCuts[0];
        for (int i = 1; i < verticalCuts.size(); ++i) {
            max_w = max(max_w, verticalCuts[i] - verticalCuts[i-1]);
        }
        if (!verticalCuts.empty()) {
            max_w = max(max_w, w - verticalCuts.back());
        }
        
        // 转换为long long防止溢出，然后取模
        return ((long long)max_h % mod) * ((long long)max_w % mod) % mod;
    }
};