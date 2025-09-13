#include <iostream>
#include <vector>
#include <string>
using namespace std;

int stoi(string str){
	int i=0;
	int n=str.size();
	while(i<n && str[i]=='0'){
		i++;
	}
	//��ʱi��λ�ò���0
	int sum=0;
	for(int i;i<n;i++){
		sum*=10;
		sum+=(str[i]-'0');
	} 
	return sum;
}

int main(){
	string str;
	cin >> str;
	//����������������ǰ��0
	int n=str.size();
	int num=stoi(str);
	bool success=false;
	for(int i=1;i<=n-1;i++){
		string str1=str.substr(0,i); //��λ��0��ʼ����ȡ�����i����
		string str2=str.substr(i);
		int num1=stoi(str1);
		int num2=stoi(str2);
		if(num1*num1+num2*num2==num){
			success=true;
			break;
		} 
	} 
	if(success) cout<< "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
