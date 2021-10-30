class student1:public student
{
	public:
		string RandomNum()
		{
			srand(time(0));
			return to_string(rand()%100);
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
