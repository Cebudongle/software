#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std; 
int main()
{ }
class question
{
	private:
		string str;
	public:
		int check(double x,double y);
};
question::check (double x,double y)
{
	if(x == y)
	{
		return 1; 
	}
	if(x != y)
	{
		return 0;
	}
}
