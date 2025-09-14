//����ɸѡ��ѡ����������
//�����������洢��һ��vector�С� ͬʱ�洢�� map�д洢��������λ��
//���ڷ�Χ�������洢��һ��vecotr��

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cmath> 
using namespace std;

const int N=1e4;
vector<int> isprim(N,true);
vector<int> primnum;
map<int,int> memo;

void init(){ 
	isprim[1]=false;
	for(int i=2;i<N;i++){
		if(isprim[i]==true){
			for(int j=i*i ;j<N;j+=i){
				isprim[j]=false;
			}
			//i������
			primnum.push_back(i); 
			memo[i]=primnum.size();	
		}
	}
}

int revernum(int x){
	int sum=0;
	int fuc=1;
	string num=to_string(x);
	for(int i=0;i<num.size();i++){
		int a=num[i]-'0';
		sum+=fuc*a;
		fuc*=10;
	}
	return sum;
}

int multi(int x){ //������λ���ֳ˻�
	 string num=to_string(x);
	 int sum=1;
	 for(int i=0;i<num.size();i++){
	 	int a=num[i]-'0';
	 	sum*=a;
	 } 
	 return sum;
} 

int main(){
	init(); 
	int n1,n2,t;
	cin >> n1 >> n2 >> t;
	
	vector<int> res;
	
	for(int i=n1;i<=n2;i++){  //i�ǲ������� 
		if(isprim[i]==true){
			int renum=revernum(i);
			if(isprim[renum]==true){  //����1 
				int idx1=memo[i];
				int idx2=memo[renum];
				if(abs(idx1-idx2)<=t){  //����2 
					int multinum=multi(i);
					if(abs(idx1-multinum)<=t){ //����3 
						res.push_back(i);
					}
				}
			}
		} 
	} 
	
	sort(res.begin(),res.end());
	for(int i=0;i<res.size();i++){
		cout << res[i] << endl;
	}
	return 0;
} 
