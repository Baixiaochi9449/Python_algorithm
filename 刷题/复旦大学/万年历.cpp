#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


map<int,int> months={
						{1,31},
						{3,31},
						{4,30},
						{5,31},
						{6,30},
						{7,31},
						{8,31},
						{9,30},
						{10,31},
						{11,30},
						{12,31}
					};
					
bool isrun(int year){
	if(year%4==0 && year%100!=0) return true;
   
	else return false;
}

int days_cont(int year,int month){
	if(month==2){
		if(isrun(year)) return 29;
		else return 28;
	}
	else{
		return months[month];
	}
}


long long computedays(int year,int month,int day){  //从1.1.1开始算
	 //先算差几年，从1--year-1年
	 long long sum=0;
	 for(int i=1;i<year;i++){
	 	if(isrun(i)) sum+=366;
	 	else sum+=365;
	 } 
	 //开始算year这一年的  1.1.1  到 3.1.2 差2年 1天 所以算8.26 与1.1差多少天
	long long days=0; //算1 月 2月 ...到month-1的日子   
	for(int i=1;i<month ;i++){
		days+=days_cont(year,month);
	} 
	return sum+days+day-1;  // 1.2 与1.1差1天  
	
}


int main(){
	int T;
	cin >> T;
	while(T--){
		int year,month,day;
		cin >> year >> month >> day;
		
	
      vector<int> arr1={2,3,4,5,6,7,1};
      vector<int> arr2={2,1,7,6,5,4,3};
      
      long long cont2025=computedays(2025,8,26);
      long long contyear=computedays(year,month,day);
      
      int chazhi=abs(cont2025-contyear);
      if(cont2025>contyear){
         int idx=chazhi%7;
         cout << arr2[idx] << endl;
      }
      else{
         int idx=chazhi%7;
         cout << arr1[idx]<< endl;
      }
   }
	return 0;
	
}