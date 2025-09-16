class Solution {
public:
    string longestPrefix(string s) {
        //next���������ʲô�������ǰ����ַ������ǰ��׺�ĳ���
        //����ֱ����next����Ϳ���
        int n=s.size();
        vector<int> next(n,0);
        int j=0;
        for(int i=1;i<n;i++){
            while(j>0 && s[i]!=s[j]){
                j=next[j-1];
            }
            if(s[i]==s[j]) j++;
            next[i]=j;
        }
        //���һ���ַ������ǰ��׺����
        int len=next[n-1];
        string res=s.substr(0,len);
        return res;
    }
};
