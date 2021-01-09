#pragma once

//This header file contains some defenitions to be used all over the application
#include <string>
using namespace std;
typedef string Course_Code;


//Semesters
enum SEMESTER
{
	FALL,
	SPRING,
	SUMMER,
	SEM_CNT	//number of semesters 
};


//All possible actions
enum ActionType
{
	ADD_CRS,	//Add a course to study plan
	DEL_CRS,	//Delete a course from study plan
	CHNGE_CRS_CODE,

	ADD_NOTES,
	LOAD_CRS_CATALOG,

	LOAD_PRG_REQ,

	SAVE_plan,		//Save a study plan to file
	LOAD_plan,		//Load a study plan from a file

	//GPA,
	//Crs_Status,
	//Student_level,

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	EXIT,		//Exit the application

	STATUS_BAR,	//A click on the status bar
	MENU_BAR,	//A click on an empty place in the menu bar
	DRAW_AREA,	//A click in the drawing area

	CANCEL,		//ESC key is pressed

	//TODO: Add more action types

};


//to sotre data related to the last action
struct ActionData
{
	ActionType actType;
	int x, y;
	int year;
	SEMESTER sem;

	
};

