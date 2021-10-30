string expression()
{
	for(int i=0;i<=rand()%3;i++)
	{
		str.append(student.RandomNum);
		str.append(student.RandomOp);
	}
	str.append(student.RandomNum);
	return str;
}
