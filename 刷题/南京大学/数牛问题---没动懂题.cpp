//��ʼ�ڵ�һ����
//��¼����x=0��Ҫ������ 
//һ������洢 �룬������ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool compare(pair<int,int>& a,pair<int,int>& b){
	return a.first<b.first;  //����ʱ���С�������� 
} 

int main(){
	int n;
	cin >> n;
	map<int,int> cows;  //������Ӧy   //һ�����ʣ�map���������� 
	for(int i=0;i<n;i++){
		int x,y,t;
		cin >> x >> y >> t;
		//�����ͬһʱ�̣��ͱ�����С���Ǹ�y��ֵ 
		int time=(-1)* x*t;
		if(cows.find(time)!=cows.end()){
			cows[time]=min(y,cows[time]);
		}
		else cows[time]=y; 
	}
	//��С��������
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
