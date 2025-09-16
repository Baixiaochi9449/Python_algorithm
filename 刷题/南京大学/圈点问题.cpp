//单个矩形最小面积可以，直接找最左边的点，最右边的点...
//枚举每一列，枚举每一行
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF= 1e9; 

bool left_compare(pair<int,int>& a,pair<int,int>& b){
	return a.first<b.first;
}

bool up_compare(pair<int,int>& a,pair<int,int>& b){
	return a.second<b.second;
}

pair<int,int> find_up_down(vector<pair<int,int> >& pos,int left,int right){
	int up=pos[left].second;
	int down=pos[right].second;
	for(int i=left;i<=right;i++){
		up=max(up,pos[i].second);
		down=min(down,pos[i].second);
	}
	return {up,down};
}

pair<int,int> find_left_right(vector<pair<int,int> >& pos,int down,int up){
	int left=pos[down].first;
	int right=pos[up].first;
	for(int i=down;i<=up;i++){
		left=min(left,pos[i].first);
		right=max(right,pos[i].first);
	}
	return {left,right};
}

int main(){
	int n;
	cin >> n;
	vector<pair<int,int> > position(n);
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		position[i]={a,b};
	}
	
	sort(position.begin(),position.end(),left_compare);
	
	int res=INF; //只算2个面积的
	//先枚举列
	int left_1=position[0].first;
	int right_2=position[n-1].first;
	for(int i=1;i<n-1;i++){
		int j;
		if(i==n-2) j=i;
		else j=i+1;
		
		int right_1=position[i].first;
		int left_2=position[j].first;
		
		pair<int,int> temp_1=find_up_down(position,0,i);
		int up_1=temp_1.first;
		int down_1=temp_1.second;
		int res_1=(right_1-left_1)*(up_1-down_1);
		
		pair<int,int> temp_2=find_up_down(position,j,n-1);
		int up_2=temp_2.first;
		int down_2=temp_2.second;
		int res_2=(right_2-left_2)*(up_2-down_2);
		
		res=min(res,res_1+res_2);
	} 
	
	//再枚举行 
	sort(position.begin(),position.end(),up_compare);
	int down_1=position[0].second;
	int up_2=position[n-1].second;
	for(int i=1;i<n-1;i++){
		int j;
		if(i==n-2) j=i;
		else j=i+1;
		
		int up_1=position[i].second;
		int down_2=position[j].second;
		
		pair<int,int> temp_1=find_left_right(position,0,i);
		int left_1=temp_1.first;
		int right_1=temp_1.second;
		int res_1=(right_1-left_1)*(up_1-down_1);
		
		pair<int,int> temp_2=find_left_right(position,j,n-1);
		int left_2=temp_2.first;
		int right_2=temp_2.second;
		int res_2=(right_2-left_2)*(up_2-down_2);
		
		res=min(res,res_1+res_2);
	} 
	
	cout << res << endl;
	return 0;
	
}
