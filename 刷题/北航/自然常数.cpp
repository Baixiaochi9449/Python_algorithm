#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//快速幂
double kmi(double a,int b){  //a的b次方 
	double sum=1; 
	while(b>0){
		if(b & 1){ //最后一位是1 
			sum=(double)sum*a;
		}
		a=(double)a*a;
		b/=2; //除2就是 右移 
	} 
	return sum;
}

int main(){
	int n;
	cin >> n;
	//首先求i的阶乘
	vector<double> JC(n+1);
	JC[0]=1;   //0的阶乘是什么？肯定不是0 
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
	double temp=1+(double)1/n;  //！！！这里必须需要写上double 
    // printf("%.3f",temp);
	un=kmi(temp,n);
	printf("%.3f",un);
	
	return 0;
	
} 
