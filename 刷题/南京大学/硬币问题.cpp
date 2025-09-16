//这是一个贪心算法
// curval 记录当前硬币能组合的最大价值 while(curval< v)   当coins[i] <=curval+1 当前的硬币面值比下一个可能覆盖的价值数小，就依然使用当前价值
//如果 coins[i] >curval+1  //s说明有空缺，不能连续覆盖， 所以要加一个面值为 curval+1的硬币

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	vector<int> coins(n);
	for(int i=0;i<n;i++){
		cin >> coins[i];
	}
	int c ,v;
	cin >> c >> v;
	
	//首先要把硬币从小到大排序
	sort(coins.begin(),coins.end()); 
	
	int curval=0;
	int idx=0; //遍历硬币 
	int res=0;
	while(curval<v){
		if(idx<n && coins[idx]<=curval+1){
			curval=curval+coins[idx]*c;  
			idx++;
		} 
		else{
			int add=curval+1; //因为要尽量加入少的硬币
			curval=curval+add*c; 
			res++;
			//在这里，硬币没有向后遍历哦，因为目前是卡在这个硬币上了 
		}
	}
	
	cout << res << endl;
	return 0;
} 
