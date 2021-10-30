class student1:public student
{
	public:
		string RandomNum()
		{
			srand(time(0));
			return dou_to_str(rand()%100);
		}
		string RandomOp()
		{
			string str1="+", str2="-";
			srand(time(0));
			if (rand()%2==0)
			{
				return str1;
			}
			else
			{
				return str2;
			}
		}  
}
