string expression()
	{
		string str="";
		char ch1='(',ch2=')';
		int number_num=rand()%3+1;		//操作数的个数 
		if(number_num>=2) 
			str+=ch1;			//个数大于2才加括号 
		for(int i=0;i<number_num;i++)
		{
			str.append(RandomNum());
			if(number_num>=2&&i==1)
			str+=ch2;
			str.append(RandomOp());
		}
		str.append(RandomNum());
		
		return str;
	}
