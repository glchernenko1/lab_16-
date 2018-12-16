#include <iostream>
#include <fstream>
#include "mylist.h"
#include <algorithm>


using namespace std;
int main()
{
	std::fstream file("Test.txt");
	mylist a; 
	file >> a;
	//list<int> c(a.begin(), a.end());
	a;
	a.sort();


	
	//sort(a.begin(), a.end());
	std::cout << a;

	system("pause");
	return 0;
}