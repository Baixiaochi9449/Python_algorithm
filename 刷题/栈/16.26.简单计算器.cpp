class Solution {
public:
    int operat(char op, int num1, int num2) {
        if (op == '+') return num1 + num2;
        if (op == '-') return num1 - num2;
        if (op == '*') return num1 * num2;
        if (op == '/') return num1 / num2;
        return -1;
    }
    
    int calculate(string s) {
        stack<int> numbers;
        stack<char> operation;
        unordered_map<char, int> pority = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2}
        };
        
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            
            if (s[i] == '+' || s[i] == '/' || s[i] == '*' || s[i] == '-') {
                while (!operation.empty() && pority[operation.top()] >= pority[s[i]]) {
                    char op = operation.top();
                    operation.pop();
                    
                    int num1 = numbers.top();
                    numbers.pop();
                    int num2 = numbers.top();
                    numbers.pop();
                    
                    int temp = operat(op, num2, num1);
                    numbers.push(temp);
                }//只要栈里面的操作符的优先级大，就一直运行一直运行，操作完，再把新的压进去
                operation.push(s[i]);//如果是空，就压进去；如果当前的操作符优先级小，就压进去
                i++;
            } else {
                string te = "";
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    te += s[i];
                    i++;
                }
                if (te.size() > 0) {
                    numbers.push(stoi(te));
                }
            }
        }
        
        while (!operation.empty()) {
            char op = operation.top();
            operation.pop();
            
            int num1 = numbers.top();
            numbers.pop();
            int num2 = numbers.top();
            numbers.pop();
            
            int temp = operat(op, num2, num1);
            numbers.push(temp);
        }
        
        return numbers.top();
    }
};