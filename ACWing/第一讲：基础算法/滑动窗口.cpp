//��ʼʱ���Ѵ����ڵĶ��ŵ�������
//�������Ƶ�ʱ�� �������ǰ������Сֵ�� �жϼ�������͵�������
//ʹ�ô��ڵ����ұ߽����ж�
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
	priority_queue<int,vector<int>,greater<int> > que;  //Ĭ�����ֵ 
	for(int i=0;i<k;i++){
		que.push(arr[i]);
	}
	int l=0,r=k; //���ұ߽�  ���ұ� 
	while(r<n){
		int minval=que.top();
		cout << minval <<" ";
		//����µ�����minvalС���Ѷ������
		if(arr[r]<minval){
			while(!que.empty()) que.pop(); 
		} 
		else{
			if(arr[l]==minval){ //Ҫ������������Сֵ 
				que.pop(); 
			}
		}
		que.push(arr[r]);
		r++;
		l++;
	} 
	cout << que.top() << endl;  //�ڰ����һ����� 
	
	//�������ֵ 
	priority_queue<int> que2;  //Ĭ�����ֵ 
	for(int i=0;i<k;i++){
		que2.push(arr[i]);
	}
	
	l=0,r=k; //���ұ߽�  ���ұ� 
	while(r<n){
		int maxval=que2.top();
		cout << maxval <<" ";
		//����µ�����minvalС���Ѷ������
		if(arr[r]>maxval){
			while(!que2.empty()) que2.pop(); 
		} 
		else{
			if(arr[l]==maxval){ //Ҫ������������Сֵ 
				que2.pop(); 
			}
		}
		que2.push(arr[r]);
		r++;
		l++;
	} 
	cout << que2.top() << endl;  //�ڰ����һ����� 
	
	
	return 0; 
} 
