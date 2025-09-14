#include <iostream>
#include <vector>
#include <algorihtm>
using namespace std;

int main(){
	vector<int> nums={1,2,3};

    int n=nums.size();
    int i=n-1;
    int nextidx=-1;
    while(i>=0){
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i]){
                nextidx=j;
                break;
            }
        }
        if(nextidx==-1) i--;
        else break;
    }
	
	//没找到 
    if(nextidx==-1){
        sort(nums.begin(),nums.end());
    }
    //i与nextid进行替换 
    else{
        int temp=nums[i];
        nums[i]=nums[nextidx];
        nums[nextidx]=temp;
        sort(nums.begin()+nextidx+1,nums.end());
    }
	
	for(int i=0;i<n;i++){
		cout << nums[i] << endl;
	}
}
