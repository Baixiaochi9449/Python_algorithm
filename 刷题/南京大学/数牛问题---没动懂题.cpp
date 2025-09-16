//初始在第一象限
//记录到达x=0需要多少秒 
//一个数组存储 秒，纵坐标 
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool compare(pair<int,int>& a,pair<int,int>& b){
	return a.first<b.first;  //按照时间从小到大排序 
} 

int main(){
	int n;
	cin >> n;
	map<int,int> cows;  //秒数对应y   //一个疑问，map可以排序吗 
	for(int i=0;i<n;i++){
		int x,y,t;
		cin >> x >> y >> t;
		//如果是同一时刻，就保存最小的那个y的值 
		int time=(-1)* x*t;
		if(cows.find(time)!=cows.end()){
			cows[time]=min(y,cows[time]);
		}
		else cows[time]=y; 
	}
	//从小到大排序
	vector<pair<int,int> > arr;
	for(auto it=cows.begin();it!=cows.end();it++){
		arr.push_back({it->first,it->second});
	} 
	
	sort(arr.begin(),arr.end(),compare);
	
	int res=0;
	int miny=1e9;
	
	for(int i=0;i<arr.size();i++){
		if(arr[i].second<miny){
			res++;
			miny=arr[i].second;
		}
	} 
	cout << res << endl;
	return 0;
	
} 
