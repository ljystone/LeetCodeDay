// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;

void fun(int i)
{
	int a = i / 100;
	int b = i / 10 % 10;
	int c = i % 10;
	if ((a*a*a + b*b*b + c*c*c) == i)
	{
		
		cout << " true " << endl;
	}
	else
	{
		cout <<" false "<< endl;
		
	}
}
int main() {
	
	cout << strlen("\\\"ABCDE\"\\")<< endl;
	int i = 3;
	do {
	if (++i==16)
	{
		break;
	}
	if (i%3==0)
	{
		printf("*", i);
	}
	} while (1);
	return 0;
}
