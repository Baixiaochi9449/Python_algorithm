#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        // 统计 words1 和 words2 中每个字符串的出现次数
        unordered_map<string, int> count1, count2;
        for (const string& word : words1) count1[word]++;
        for (const string& word : words2) count2[word]++;

        // 遍历 words1，找到在 words1 中只出现一次的字符串
        unordered_set<string> candidates;
        for (const string& word : words1) {
            if (count1[word] == 1) candidates.insert(word);
        }

        // 检查这些字符串是否在 words2 中也只出现一次
        int result = 0;
        for (const string& word : candidates) {
            if (count2[word] == 1) result++;
        }

        return result;
    }
};