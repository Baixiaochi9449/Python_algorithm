#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//������
double kmi(double a,int b){  //a��b�η� 
	double sum=1; 
	while(b>0){
		if(b & 1){ //���һλ��1 
			sum=(double)sum*a;
		}
		a=(double)a*a;
		b/=2; //��2���� ���� 
	} 
	return sum;
}

int main(){
	int n;
	cin >> n;
	//������i�Ľ׳�
	vector<double> JC(n+1);
	JC[0]=1;   //0�Ľ׳���ʲô���϶�����0 
	JC[1]=1;
	
	for(int i=2;i<=n;i++){
		JC[i]=JC[i-1]*i;
	}  
	
	double sum=0;
	for(int i=0;i<=n;i++){
		sum+=double(1/JC[i]); 
	}
	printf("%.3f ",sum);
	
	double un=0;
	double temp=1+(double)1/n;  //���������������Ҫд��double 
    // printf("%.3f",temp);
	un=kmi(temp,n);
	printf("%.3f",un);
	
	return 0;
	
} 
