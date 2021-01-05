#include "Actions\ActionLoadCrsOffering.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "CrsOffering.h"
#include"Registrar.h"
using namespace std;

ActionLoadCrsOffering::ActionLoadCrsOffering(Registrar*r): Action(r)
{
}

bool ActionLoadCrsOffering::Execute()
{

	CrsOffering* pCO = pReg->getCrsOffering();
	ifstream finput("cie.txt");

	string year = pCO->getYear();
	string sem = pCO->getSem();
	vector<string> crs = pCO->getCourses();

	char* pch;
	char* context = nullptr;
	const int size = 300;
	char line[size];

	while (!finput.eof())
	{
		finput.getline(line, size);

		//reading year
		pch = strtok_s(line, ",", &context);
		year = pch;

		//reading semester
		pch = strtok_s(NULL, ",", &context);
		sem = pch;

		//reading list of courses
		stringstream courses(pch);
		while (courses.good()) {
			string substr;
			getline(courses, substr, ',');              //get first string delimited by comma
			crs.push_back(substr);
		}

	}

	return true;
}

ActionLoadCrsOffering::~ActionLoadCrsOffering()
{
}
