#include<bits/stdc++.h>
#include<cmath>
using namespace std;
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
class student
{
	private:
		int level;
		int num;
	public:
		student(){}
		void set_num(int nu){
			num=nu;
		}
		string RandomNum();
		string RandomOp();
		
};
class student1:virtual public student
{
	public:
		student1(){
		}
		string RandomNum()
		{
			return dou_to_str(rand()%100);
		}
		string RandomOp()
		{
			string str1="+", str2="-";
			if (rand()%2==0)
			{
				return str1;
			}
			else
			{
				return str2;
			}
		}  
		string expression()
		{
			string str="";
			for(int i=0;i<=rand()%3;i++)
			{
				str.append(RandomNum());
				str.append(RandomOp());
			}
			str.append(RandomNum());
			
			return str;
		}
};
class student2:virtual public student{
    public:
    	student2(){
		}
        string RandomNum(){
            return dou_to_str (rand()%10000);
        }
        string RandomOp(){
            string str1="+",str2="-",str3="*",str4="/";
            switch(rand()%4){
                case 0:
                    return str1;
                case 1:
                    return str2;
                case 2:
                    return str3;
                case 3:
                    return str4;
                default:
                    break;
            }
        }
		string expression()
		{
			string str="";
			for(int i=0;i<=rand()%3;i++)
			{
				str.append(RandomNum());
				str.append(RandomOp());
			}
			str.append(RandomNum());
			
			return str;
		}
};
class student3:virtual public student{
	public:
		student3(){
		}
		string RandomNum()
		{
			return dou_to_str((rand()%10000+rand()%10001/10000.0));
		}
		string RandomOp()
		{
			string str1="+",str2="-",str3="*",str4="/";
			int random=rand()%4;
			if(random==0)
			{
				return str1;
			}
			else if(random==1)
			{
				return str2;
		    }
		    else if(random==2)
		    {
		    	return str3;
			}
			else if(random==3)
			{
				return str4;
			}
		}
		string expression()
		{
			string str="";
			for(int i=0;i<=rand()%3;i++)
			{
				str.append(RandomNum());
				str.append(RandomOp());
			}
			str.append(RandomNum());
			
			return str;
		}
};

class question
{
	private:
		string str;
	public:
		bool check(double x,double y){
			return x==y;
		};


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
};

int main()
{
	string grade = "";
	srand((unsigned)time(NULL));
	cout << "输出：请输入你的年级?" << endl;
	
	cin >> grade;
	int nu,level;
	if (grade == "一年级" || grade == "二年级") level = 1;
	if (grade == "三年级" || grade == "四年级") level = 2;
	if (grade == "五年级" || grade == "六年级") level = 3;	
	
	cout << "输出：请输入题目数?" << endl;
	cin>>nu;
	question que1;
	student1 stu1;
	student2 stu2;
	student3 stu3;
	int count=0;
	for(int i=0;i<nu;i++)
	{	 
		cout << "输出: "; 		
		string s ;
		if(level==1)s=stu1.expression();
		if(level==2)s=stu2.expression();
		if(level==3)s=stu3.expression();	
		cout<<s<<"="<<"?"<<endl;
		cout<<"输入：";
		double temp,ans=que1.getres(s);
		cin>>temp;
		if(fabs(temp-ans)<1e-2)cout<<"Accepted";
		else {
		cout<<"Wrong Answer";
		count++;
	    }
		cout<<"  The answer is "<<fixed<<setprecision(2)<<ans<<endl;
		
	}
	if(count!=0)
	cout<<"真可惜,本次错了"<<count<<"题"<<endl; 
	else
	cout<<"恭喜你本次全对!"<<endl;
	return 0;
}
