//string��find ���it���ص��ǵ�һ��ƥ���λ��
//��һ����string�洢��vector<string> ��
 //�ж��Ƿ���ȵ�ʱ�� ��Ҫ�����ж�һ�¡�
 //���жϳ������滻��ʱ��Ҫԭ�����Ƿ�����ĸ��д��  
 //������һ�����飬����е����� i ,Ҫ�滻ΪI 
 
 
 #include <iostream>
 #include <vector>
 #include <string>
 #include <map>
 #include <cstdio>
 using namespace std; 
 
 
 //ȫ����map�е��ַ��������Сд
 string change_small(string str){  //��ֵ���ı�ԭ���� 
 	for(int i=0;i<str.size();i++){
 		if(str[i]<='Z' && str[i]>='A'){
 			char c=str[i];  //��ֵ�� C-'A 
 			str[i]='a' +(c-'A');
		 }
	 }
	 return str;
 } 
 
 //�Ȳ��ܴ�Сд���ƥ�䣬ֻ�ȹ�ע��ȫƥ��� 
 
 bool isbig(string str){
 	if(str[0]<='Z' && str[0]>='A') return true;
 	else return false;
 } 
 
 string change_big(string str){ //��ֵ //������ĸ��Ϊ��д 
 	if(isbig(str)) return str;
 	else{
 		char c=str[0]; //��ֵ��c-'a'
 		char newc= 'A'+ (c-'a');
 		str[0]=newc;
	 }
	 return str;
 }
 
bool allbig(string str){
	
	for(int i=0;i<str.size();i++){
		if(str[0]>'Z' || str[0]<'A') return false;
	}
	return true;
} 

bool allsmall(string str){
	
	for(int i=0;i<str.size();i++){
		if(str[0]>'z' || str[0]<'a') return false;
	}
 	return true;
} 

 string stay_same(string pattern,string str){
 	if(pattern[0]>='A'&& pattern[0]<='Z'){  //����ĸ�Ǵ�д 
 		//���ȱ�Ϊ����ĸ��д 
		if(str[0]<='z'&& str[0]>='a'){
			str[0]='A'+(str[0]-'a');
		 }
	}
 	if(allbig(pattern)){
 		for(int i=0;i<str.size();i++){
 			if(str[i]<='z'&& str[i]>='a'){
 				str[i]='A'+ (str[i]-'a');
			 }
		 }
	 }
	if(allsmall(pattern)){
 		for(int i=0;i<str.size();i++){
 			if(str[i]<='Z'&& str[i]>='A'){
 				str[i]='a'+ (str[i]-'A');
			 }
		 }
	}

	return str;
 }
 
 int main(){
 	int n;
 	cin >> n;
 	map<string,string> needchange;
 	for(int i=0;i<n;i++){
 		string str1,str2;
 		cin >> str1 >> str2;
		string newstr1=change_small(str1);
		needchange[newstr1]=str2;
	 }
	
	string str, ign;
	getline(cin ,ign);   //��ô����һ�У������� 
	getline(cin,str);
//	cout << str;
	
	vector<string> res;  //����ÿ�����ʴ洢�������� 
	//����ÿ�����ʣ��ж��Ƿ���Ҫ�滻 
	int i=0; 
	while(i<str.size()){
		//i����ʼλ�ã�j�Ǻ���Ŀո��λ�� 
		int j=i+1;
		while(j<str.size() && str[j]!=' '){
			j++;
		}
		string curstr=str.substr(i,j-i);
		
//		cout<< "��ǰ���ַ���" << curstr << endl; 
		
		i=j+1;
		//map���У���Ҫ�滻
		string smallstr=change_small(curstr);
		if(needchange.find(smallstr)!=needchange.end()){
			string origstr=needchange[smallstr];
			string thesame=stay_same(curstr,origstr);
			res.push_back(thesame);
		}
		
		//i��Ҫ�滻
		else if(curstr=="i"){
			res.push_back("I");
		}
		//����Ҫ�滻 
		else{
			res.push_back(curstr);
		}
	}
//	cout << res.size() << endl;
	
	for(int k=0;k<res.size();k++){
		cout << res[k] << " ";
	}
	return 0;
 }
