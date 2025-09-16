//初始时，把窗口内的都放到队列中
//往后推移的时候： 先输出当前窗口最小值， 判断加入的数和弹出的数
//使用窗口的左右边界来判断
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	priority_queue<int,vector<int>,greater<int> > que;  //默认最大值 
	for(int i=0;i<k;i++){
		que.push(arr[i]);
	}
	int l=0,r=k; //左右边界  左开右闭 
	while(r<n){
		int minval=que.top();
		cout << minval <<" ";
		//如果新的数比minval小，把队列清空
		if(arr[r]<minval){
			while(!que.empty()) que.pop(); 
		} 
		else{
			if(arr[l]==minval){ //要弹出的数是最小值 
				que.pop(); 
			}
		}
		que.push(arr[r]);
		r++;
		l++;
	} 
	cout << que.top() << endl;  //在把最后一个输出 
	
	//处理最大值 
	priority_queue<int> que2;  //默认最大值 
	for(int i=0;i<k;i++){
		que2.push(arr[i]);
	}
	
	l=0,r=k; //左右边界  左开右闭 
	while(r<n){
		int maxval=que2.top();
		cout << maxval <<" ";
		//如果新的数比minval小，把队列清空
		if(arr[r]>maxval){
			while(!que2.empty()) que2.pop(); 
		} 
		else{
			if(arr[l]==maxval){ //要弹出的数是最小值 
				que2.pop(); 
			}
		}
		que2.push(arr[r]);
		r++;
		l++;
	} 
	cout << que2.top() << endl;  //在把最后一个输出 
	
	
	return 0; 
} 
