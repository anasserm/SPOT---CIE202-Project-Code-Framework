#include "ActionLoadCrsCatalog.h"
#include "..\CrsCatalog.h"
#include <fstream>
#include <vector>
#include <sstream>
#include "../Registrar.h"
#include <iostream>
#include <string>


ActionLoadCrsCatalog::ActionLoadCrsCatalog(Registrar*p) :Action(p)
{
}

bool ActionLoadCrsCatalog::Execute()
{
	GUI* pGUI = pReg->getGUI();
	
	CrsCatalog* Pcata = pReg->getCrsCatalog();
	ifstream finput("cata.txt");
	while (!finput.eof())
	{
		string title, name, crd, co, pre;
		char* pch;  char* ch;
		char* context = nullptr;
		const int size = 300;
		stringstream coreq(co);
		stringstream prereq(pre);
		char line[size];
		finput.getline(line, size);
		
		// get course code name 
		pch = strtok_s(line, ",", &context);
		cout << pch<<endl;
		name = pch;
		// get course title 
		pch = strtok_s(NULL, ",", &context); cout << pch << endl;
		title = pch;
		// get credits
		pch = strtok_s(NULL, ",", &context); cout << pch << endl;
		char* c[1];
		c[0] = pch;
		int cre;
		cre = stoi(c[0]);
		
		Course* pCrs = new Course(name, title, cre);
		vector<string >CoReq = pCrs->getCoReq();
		vector<string >PreReq = pCrs->getPreReq();

		pch = strtok_s(NULL, ":", &context); cout << pch << endl;
		
		if (pch[1] == 'P') // only prerequisit
		{

			ch = strtok_s(pch, "", &context);
			pre = ch;
			while (prereq.good()) {
				string sub;
				getline(prereq, sub, ',');
				PreReq.push_back(sub);
			}

		}
		else // coreq is found 
		{

			ch = strtok_s(NULL, ":", &context);         // string of co + ,req
			co = ch;
			while (coreq.good()) {
				string substr;
				getline(coreq, substr, ',');              //get first string delimited by comma
				CoReq.push_back(substr);
			}
			CoReq.pop_back();

			ch = strtok_s(NULL, ":", &context); // string of pre req
			pre = ch;
			while (prereq.good()) {
				string sub;
				getline(prereq, sub, ',');          //get first string delimited by comma
				PreReq.push_back(sub);
			}
		}
		
		Pcata->addCrs(pCrs);
		
	}

	
		return true;
}

ActionLoadCrsCatalog::~ActionLoadCrsCatalog()
{
}
