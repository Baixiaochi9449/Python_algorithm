//�൱��b�ǲ�ѯ
//��a�洢��һ��map��,Ȼ���ѯ
 #include <iostream>
 #include <map>
 using namespace std;
 
 int main(){
 	int n,m;
 	cin >> n >> m;
 	map<int,int> memo;
 	for(int i=0;i<n;i++){
 		int a;
 		cin >> a;
 		memo[a]++;
	 }
	 
	 for(int i=0;i<m;i++){
	 	int q;
	 	cin >> q;
	 	if(memo.find(q)==memo.end()) cout<< 0 << " ";
	 	else cout << memo[q] << " ";
	 } 
	 return 0;
 }
