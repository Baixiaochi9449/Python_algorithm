//模拟分数相加
//先加整数部分，再加分数部分，然后再把分数部分化简
//先处理string,读入数字
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int GCD(int a,int b){
    if(b==0) return a;
    else return GCD(b,a%b);
}

//a1  a2 表示2个的整数
//b1   c1  和b2 c2这是分子和分母
int main(){
    string num1,num2;
    cin >> num1 >> num2;
    int a1=0,a2=0;
    int b1=0,b2=0;
    int c1=0,c2=0;
    //处理num1;
    int i=0;
    while(num1[i]>='0' && num1[i]<='9'){
        a1=a1*10;
        a1=a1+(num1[i]-'0');
        i++;
    }
    //此时num1=+
    i++;
    while(num1[i]>='0' && num1[i]<='9'){
        b1=b1*10;
        b1=b1+(num1[i]-'0');
        i++;
    }
    //此时 /
    i++;
    while(num1[i]>='0' && num1[i]<='9'){
        c1=c1*10;
        c1=c1+(num1[i]-'0');
        i++;
    }

    //处理num2;
    int j=0;
    while(num2[j]>='0' && num2[j]<='9'){
        a2=a2*10;
        a2=a2+(num2[j]-'0');
        j++;
    }
    //此时num1=+
    j++;
    while(num2[j]>='0' && num2[j]<='9'){
        b2=b2*10;
        b2=b2+(num2[j]-'0');
        j++;
    }
    //此时 /
    j++;
    while(num2[j]>='0' && num2[j]<='9'){
        c2=c2*10;
        c2=c2+(num2[j]-'0');
        j++;
    }

    int res=a1+a2;
    //两个分数相加. 先求最大公约数
    int mu=c1*c2;
    int zi=b1*c2+b2*c1;
    //化简分数
    int gcd=GCD(mu,zi);
    mu=mu/gcd;
    zi=zi/gcd;
    //变为真分数
    int addnum=0;
    if(zi>mu){
        addnum=zi/mu;
        zi=zi%mu;
    }
    else if(zi==mu){
        addnum=1;
        zi=0;
    }
    //最终需要 整数  分子  分母
    res=res+addnum;
    if(res!=0 && zi!=0) cout << res<< '+'<< zi << '/'<< mu << endl;
    else if(res==0 && zi!=0) cout << zi << '/' << mu << endl;
    else if(res==0 && zi==0) cout << 0 << endl;
    else cout << res << endl;
    return 0;

}