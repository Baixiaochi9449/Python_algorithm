//在最后 判断并收集结果
//每层有3种方式
//递归参数为 cursum, curstr,starindex从1开始
class Solution {
private:
    vector<string> result;
    
    void backtracking(string num,int target,int starindex){
        if(num.size()<=starindex){ //已经添加了最后一个符号了
            //计算“1+2+3”的值 1+23
            int sum=compute(num);
            if(sum==target) result.push_back(num);
            return ;
        }

        for(int i=0;i<3;i++){ //4种选择，其中包含不添加运算符
            if(i==0){
                num.insert(starindex,"+");
                starindex+=2;
                backtracking(num,target,starindex);
                starindex-=2;
                num.erase(starindex,1);
            }
            if(i==1){
                num.insert(starindex,"-");
                starindex+=2;
                backtracking(num,target,starindex);
                starindex-=2;
                num.erase(starindex,1);                
            }
            if(i==2){
                num.insert(starindex,"*");
                starindex+=2;
                backtracking(num,target,starindex);
                starindex-=2;
                num.erase(starindex,1);                
            }
            if(i==3){
                starindex++;
                backtracking(num,target,starindex);
                starindex--;
            }
        }
        return ;
    }
    int compute(string s) {
        stack<int> nums;   // 存储数字
        stack<char> ops;    // 存储运算符
        int num = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // 拼接多位数
            }
            if (!isdigit(c) || i == s.size() - 1) {
                nums.push(num);
                num = 0;
                // 处理栈内优先级更高的运算符（*）
                while (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) {
                    int b = nums.top(); nums.pop();
                    int a = nums.top(); nums.pop();
                    char op = ops.top(); ops.pop();
                    if (op == '*') nums.push(a * b);
                    else if (op == '/') nums.push(a / b);
                }
                if (c != ' ' && i != s.size() - 1) {
                    ops.push(c);
                }
            }
        }
        
        // 处理剩余的加减法
        while (!ops.empty()) {
            int b = nums.top(); nums.pop();
            int a = nums.top(); nums.pop();
            char op = ops.top(); ops.pop();
            if (op == '+') nums.push(a + b);
            else if (op == '-') nums.push(a - b);
        }
        
        return nums.top();
    }
public:
    vector<string> addOperators(string num, int target) {
        result.clear();
        int n=num.size()+num.size()-1;
        backtracking(num,target,1);
        return result;
    }
};


class Solution {
private:
    vector<string> result;
    
    void backtracking(string num, int target, string curExpr, long curSum, long prevNum, int pos) {
        if (pos == num.size()) {
            if (curSum == target) {
                result.push_back(curExpr);
            }
            return;
        }
        
        for (int i = pos; i < num.size(); i++) {
            if (i != pos && num[pos] == '0') break; // 避免前导零
            
            string currStr = num.substr(pos, i - pos + 1);
            long currNum = stol(currStr);
            
            if (pos == 0) {
                backtracking(num, target, currStr, currNum, currNum, i + 1);
            } else {
                // 尝试 + 
                backtracking(num, target, curExpr + "+" + currStr, curSum + currNum, currNum, i + 1);
                // 尝试 -
                backtracking(num, target, curExpr + "-" + currStr, curSum - currNum, -currNum, i + 1);
                // 尝试 *
                backtracking(num, target, curExpr + "*" + currStr, curSum - prevNum + prevNum * currNum, prevNum * currNum, i + 1);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        result.clear();
        if (num.empty()) return result;
        backtracking(num, target, "", 0, 0, 0);
        return result;
    }
};