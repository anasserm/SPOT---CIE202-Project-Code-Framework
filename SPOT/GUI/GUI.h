#pragma once
#include <string>
using namespace std;

#include "..\DEFs.h"
#include "CMUgraphicsLib\CMUgraphics.h"

class Course;
class AcademicYear;
//user interface class
class GUI
{

	enum MENU_ITEM //The items of the menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in the menu
		//If you want to change the menu items order, just change the order here
		ITM_ADD,		//Add a new course

		ITM_DLT,			//del course

		ITM_DISP,          //display course info

		ITM_CHNG_CODE,          //change course code

		ITM_REORDER,              //drag and drop


		ITM_NOTE,                   //take note
		ITM_SAVE_PLAN,            // 
		ITM_LOAD_PLAN,
		ITM_LOAD_CRS_CATALOG,
		ITM_LOAD_REQ,

		ITM_EXIT,		//Exit item

		ITM_CNT			//no. of menu items ==> This should be the last line in this enum

	};

	//Some constants for GUI
	static const int	WindWidth = 1500, WindHeight = 740,	//Window width and height
		wx = 0, wy = 0,		//Window starting coordinates
		StatusBarHeight = 60,	//Status Bar Height
		MenuBarHeight = 80,		//Menu Bar Height (distance from top of window to bottom line of menu bar)
		CellWidth = 375,		// width of a single cell in the grid
		MenuItemWidth = 70;		//Width of each item in the menu

	static int nYears, CellHeight;

	color DrawColor = BLACK;		//Drawing color
	color FillColor = YELLOW;		//Filling color (for courses)
	color HiColor = RED;			//Highlighting color
	color ConnColor = GREEN;		//Connector color
	color MsgColor = BLUE;			//Messages color
	color BkGrndColor = LIGHTGRAY;	//Background color
	color StatusBarColor = DARKGRAY;//statusbar color
	string WindTitle = "Study-Plan Organizational Tool (SPOT)";

	window* pWind;
public:
	GUI();
	void CreateMenu() const;
	void ClearDrawingArea() const;
	void ClearStatusBar() const;	//Clears the status bar
	void DrawBackground() const;
	//output functions
	void PrintMsg(string msg) const;		//prints a message on status bar
	void get_nYears() const;

	//Drawing functions
	void DrawCourse(const Course* );
	void DrawAcademicYear(const AcademicYear*);
	void UpdateInterface() const;
	void close() const;
	
	//input functions
	ActionData GUI::GetUserAction(string msg = "") const;
	string GetSrting() const;
	SEMESTER xtosem(int x_cord) const;
	int ytoyear(int y_cord) const;



	
	

	~GUI();
};

