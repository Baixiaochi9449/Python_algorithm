//string的find 后的it返回的是第一个匹配的位置
//把一整行string存储到vector<string> 中
 //判断是否相等的时候 需要额外判断一下。
 //当判断出可以替换的时候，要原单词是否首字母大写。  
 //最后遍历一遍数组，如果有单独的 i ,要替换为I 
 
 
 #include <iostream>
 #include <vector>
 #include <string>
 #include <map>
 #include <cstdio>
 using namespace std; 
 
 
 //全都把map中的字符串都变成小写
 string change_small(string str){  //传值不改变原来的 
 	for(int i=0;i<str.size();i++){
 		if(str[i]<='Z' && str[i]>='A'){
 			char c=str[i];  //差值是 C-'A 
 			str[i]='a' +(c-'A');
		 }
	 }
	 return str;
 } 
 
 //先不管大小写情况匹配，只先关注完全匹配的 
 
 bool isbig(string str){
 	if(str[0]<='Z' && str[0]>='A') return true;
 	else return false;
 } 
 
 string change_big(string str){ //传值 //把首字母变为大写 
 	if(isbig(str)) return str;
 	else{
 		char c=str[0]; //差值是c-'a'
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
 	if(pattern[0]>='A'&& pattern[0]<='Z'){  //首字母是大写 
 		//首先变为首字母大写 
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
	getline(cin ,ign);   //怎么读入一行？？？？ 
	getline(cin,str);
//	cout << str;
	
	vector<string> res;  //最后把每个单词存储在数组中 
	//遍历每个单词，判断是否需要替换 
	int i=0; 
	while(i<str.size()){
		//i是起始位置，j是后面的空格的位置 
		int j=i+1;
		while(j<str.size() && str[j]!=' '){
			j++;
		}
		string curstr=str.substr(i,j-i);
		
//		cout<< "当前的字符串" << curstr << endl; 
		
		i=j+1;
		//map中有，需要替换
		string smallstr=change_small(curstr);
		if(needchange.find(smallstr)!=needchange.end()){
			string origstr=needchange[smallstr];
			string thesame=stay_same(curstr,origstr);
			res.push_back(thesame);
		}
		
		//i需要替换
		else if(curstr=="i"){
			res.push_back("I");
		}
		//不需要替换 
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
