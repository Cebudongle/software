class student3:public Student{
	public:
		string RandomNum()
		{
			srand(time(0));
			return tp_string(rand()%10001/10000.0);
		}
		string RandomOp()
		{
			string str1="+",str2="-",str3="*",str4="/";
			srand(time(0));
			if(rand()%4==0)
			{
				return str1;
			}
			else if(rand()%4==1)
			{
				return str2;
		    }
		    else if(rand()%4==2)
		    {
		    	return str3;
			}
			else if(rand()%4==3)
			{
				return str4;
			}
		}
};
