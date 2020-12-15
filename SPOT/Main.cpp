#include "Registrar.h"
#include <iostream>
#include <list>
#include "Courses/Course.h"


using namespace std;



int main()
{	
	Registrar Reg;
	Reg.Run();
	return 0;
	
	/*
	Course* c1 = new Course("Abdo", "Nasser", 1);
	Course* c2 = new Course("Ahmed", "Youssif", 2);
	Course* c3 = new Course("Mostafa", "Maged", 3);

	list<Course*> l;
	l.push_back(c1);
	l.push_back(c2);
	l.push_back(c3);

	for (list<Course*>::iterator iter = l.begin(); iter != l.end(); ++iter)
	{
		cout << (*iter)->getCredits() << " ";
	}

	int idx = 0;
	for (list<Course*>::iterator iter = l.begin(); iter != l.end(); ++iter)
	{
		if ((*iter)->getCode() == "Ahmed")
			break;
		idx++;
	}
	list<Course*>::iterator iter = l.begin();
	advance(iter, idx);
	cout << (*iter)->getCode() << endl;
	int x;
	cin >> x;
	/*l.erase(iter);
	cout << endl;

	for (list<Course*>::iterator iter = l.begin(); iter != l.end(); ++iter)
	{
		cout << (*iter)->getCredits() << " ";
	}
	
	*/
	
	
}