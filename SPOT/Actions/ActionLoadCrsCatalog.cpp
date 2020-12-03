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

	list<string >CoReq = pCrs->getCoReq();
	list<string >PreReq = pCrs->getPreReq();
	stringstream coreq(co);
	                           
	while (coreq.good()) {
		string substr;
		getline(coreq, substr, ',');              //get first string delimited by comma
		CoReq.push_back(substr);
	}
	CoReq.pop_back();

	stringstream prereq(pre);
	                       
	while (prereq.good()) {
		string substr;
		getline(prereq, substr, ',');          //get first string delimited by comma
		PreReq.push_back(substr);
	}
	
	








	
	
	
	return true;
}

ActionLoadCrsCatalog::~ActionLoadCrsCatalog()
{
}
