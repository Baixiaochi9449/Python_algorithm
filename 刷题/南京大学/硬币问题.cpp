//����һ��̰���㷨
// curval ��¼��ǰӲ������ϵ�����ֵ while(curval< v)   ��coins[i] <=curval+1 ��ǰ��Ӳ����ֵ����һ�����ܸ��ǵļ�ֵ��С������Ȼʹ�õ�ǰ��ֵ
//��� coins[i] >curval+1  //s˵���п�ȱ�������������ǣ� ����Ҫ��һ����ֵΪ curval+1��Ӳ��

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
	
	//����Ҫ��Ӳ�Ҵ�С��������
	sort(coins.begin(),coins.end()); 
	
	int curval=0;
	int idx=0; //����Ӳ�� 
	int res=0;
	while(curval<v){
		if(idx<n && coins[idx]<=curval+1){
			curval=curval+coins[idx]*c;  
			idx++;
		} 
		else{
			int add=curval+1; //��ΪҪ���������ٵ�Ӳ��
			curval=curval+add*c; 
			res++;
			//�����Ӳ��û��������Ŷ����ΪĿǰ�ǿ������Ӳ������ 
		}
	}
	
	cout << res << endl;
	return 0;
} 
