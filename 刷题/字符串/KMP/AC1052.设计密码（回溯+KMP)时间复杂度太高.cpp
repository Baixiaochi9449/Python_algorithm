//简单的想法： 回溯。当长度为N的时候，收集结果（先判断是否包含子串） 感觉时间复杂度会很高
//再剪枝一下，每添加一个字符，就判断一下curstr是否包含子串。 到长度为N时候收集结果。 //再剪枝一下的就是，如果当前长度<子串长度的时候，就不判断。
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int MAX=100;
vector<int> next(MAX,0);
int MOD = 1e9+7;

vector<int> bulid_next(string pattern,vector<int> next){
  int j=0;
  for(int i=0;i<pattern.size();i++){
    while(j>0 && pattern[i]!=pattern[j]){
      j=next[j-1];
    }
    if(pattern[i]==pattern[j]){
      j++;
    }
    next[i]=j;
  }
  return next;
}

bool run_KMP(string text,string pattern){
  vector<int> next(pattern.size(),0);
  next = bulid_next(pattern,next);
  int j=0;
  for(int i=0;i<text.size();i++){
    while(j>0 && text[i]!=pattern[j]){
      j=next[j-1];
    }
    if(text[i]==pattern[j]){
      j++;
    }
    if(j==pattern.size()){
      return true;
    }
  }
  return false;
}

int Count=0;
void backtracking(int n,string T,string curstr){
  if(curstr.size()==n){
    if(!run_KMP(curstr,T)){
      Count++;
      Count = Count %MOD;
    }
    return ;
  }
  for(int i=0;i<26;i++){
    char c = i+'a';
    if(run_KMP(curstr+c,T)) continue;
    backtracking(n,T,curstr+c);
  }
  return ;
}

int main(){
  int n;
  string T;
  while(cin >> n >> T){
    if(T.size()==0){
      int result = 1;
      for(int i=0;i<n;i++){
        result*=26;
        result = result % MOD;
      }
      cout << result << endl;
    }
    if(T.size()==1){
      int result = 1;
      for(int i=0;i<n;i++){
        result*=25;
        result = result % MOD;
      }
      cout << result << endl;
    }
    //开始回溯算法
    backtracking(n,T,"");
    cout << Count << endl;
    
  }
  return 0;
}
