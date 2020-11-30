#include "ActionLoadCrsCatalog.h"
#include "..\Registrar.h"

#include <fstream>
#include <vector>
#include <sstream>

#include <iostream>
#include <string>


ActionLoadCrsCatalog::ActionLoadCrsCatalog(Registrar*p) :Action(p)
{
}

bool ActionLoadCrsCatalog::Execute()
{
	GUI* pGUI = pReg->getGUI();
	
	
	ifstream finput("D:\\cata.txt");
	string title, name, crd, co, pre;
	char* pch;
	char* context = nullptr;
	const int size = 300;
	char line[size];
	finput.getline(line, size);

	// get course code name 
	pch = strtok_s(line, ",", &context);
	name = pch;
	
	// get course title 
	pch = strtok_s(NULL, ",", &context);
	title= pch;

	// get credits
	pch = strtok_s(NULL, ",", &context);
	char* c[1];
	c[0] = pch;
	int cre;
	cre = stoi(c[0]);
	delete[]c;

	Course* pCrs = new Course(name, title, cre);


	pch = strtok_s(NULL, ":", &context);
	pch = strtok_s(NULL, ":", &context);         // string of co + ,req
	co = pch;

	stringstream coreq(co);
	vector<string> result;
	list<string> coRe;                            //list of co requisite courses
	while (coreq.good()) {
		string substr;
		getline(coreq, substr, ',');              //get first string delimited by comma
		result.push_back(substr);
	}
	
	for (int i = 0; i < result.size() - 1; i++) 
	{    
		coRe.push_back(result[i]);
	}


	stringstream prereq(pre);
	vector<string> pr;
	list<string> preRe;                         //list of pre requisitecourses
	while (prereq.good()) {
		string substr;
		getline(prereq, substr, ',');          //get first string delimited by comma
		pr.push_back(substr);
	}
	for (int i = 0; i < pr.size(); i++)
	{    
		preRe.push_back(result[i]);

	}








	
	
	
	return true;
}

ActionLoadCrsCatalog::~ActionLoadCrsCatalog()
{
}
