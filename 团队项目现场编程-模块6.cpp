#include<bits/stdc++.h>
#define inf 1e18+5
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int mod=998244353;
const int N=1e5+5;


//-------------Module begin------------------ 
double str_to_dou(string s){
	double res;
	stringstream ss;
	ss<<s;
	ss>>res;
	return res;
}
string dou_to_str(double x){
	string res;
	stringstream ss;
	ss<<x;
	ss>>res;
	return res;
}

double getres(string s){
	double res=0;
	string cur="";
	vector<string>v;
	for(int i=0;i<s.size();i++){
		char ch=s[i];
		if(ch=='.' || (ch>='0'&&ch<='9'))cur+=ch;
		else if(!('0'<=ch&&ch<='9')){
			v.push_back(cur);
			cur="";
			cur+=ch;
			v.push_back(cur);
			cur="";
		}
	}
	v.push_back(cur);
	vector<string>::iterator it=v.begin();
	for(;it!=v.end();it++){
		string tmp=(*it);
		if(tmp=="*"){
			double val1=str_to_dou(*(it-1)),val2=str_to_dou(*(it+1));
			val1*=val2;
			*(it-1)=dou_to_str(val1);			
			v.erase(it);
			v.erase(it);
			it--;
		}
		else if(tmp=="/"){
			double val1=str_to_dou(*(it-1)),val2=str_to_dou(*(it+1));
			val1/=val2;
			*(it-1)=dou_to_str(val1);			
			v.erase(it);
			v.erase(it);		
			it--;	
		} 
	}	
	it=v.begin();
	for(;it!=v.end();it++){
		string tmp=(*it);
		if(tmp=="+"){
			double val1=str_to_dou(*(it-1)),val2=str_to_dou(*(it+1));
			val1+=val2;
			*(it-1)=dou_to_str(val1);			
			v.erase(it);
			v.erase(it);
			it--;
		}
		else if(tmp=="-"){
			double val1=str_to_dou(*(it-1)),val2=str_to_dou(*(it+1));
			val1-=val2;
			*(it-1)=dou_to_str(val1);			
			v.erase(it);
			v.erase(it);
			it--;			
		} 
	}
	return str_to_dou(v[0]);
}

double GetValue(string s)//use this to calculate string which contains '(' and ')'
{
	string tmp="",t="";
	string::iterator it=s.begin(),it1;
	for(;it!=s.end();it++){
		if((*it)==')'){
			it1=it-1;
			while((*it1)!='('){
				tmp=(*it1)+tmp;
				it1--;
			}
			tmp=dou_to_str(getres(tmp));
			while(1){
				char ch=*it1;
				s.erase(it1);
				if(ch==')')break;
			}
			int pos=it1-s.begin();
			s.insert(pos,tmp);
			it=it1;
//			cout<<tmp<<endl;
			tmp="";
		}
	}
//	cout<<s<<endl;
	return getres(s);
}
//-------------Module end------------------ 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	string s;
//	cin>>s; 
//	cout<<fixed<<setprecision(2)<<GetValue(s);
	return 0;
}

