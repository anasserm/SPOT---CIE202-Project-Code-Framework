#include "GUI.h"
#include "../Courses/Course.h"
#include "../StudyPlan/AcademicYear.h"
#include "../Registrar.h"
#include <sstream>
#include <iostream>

int GUI::nYears = 0;
int GUI::CellHeight = 0;

GUI::GUI()
{ 
	pWind = new window(WindWidth, WindHeight,wx,wy);
	pWind->ChangeTitle(WindTitle);
	ClearDrawingArea();
	ClearStatusBar();
	CreateMenu();
	
}


//Clears the status bar
void GUI::ClearDrawingArea() const
{
	pWind->SetBrush(BkGrndColor);
	pWind->SetPen(BkGrndColor);
	DrawBackground();

}

void GUI::ClearStatusBar() const
{
	pWind->SetBrush(StatusBarColor);
	pWind->SetPen(StatusBarColor);
	pWind->DrawRectangle(0, WindHeight - StatusBarHeight, WindWidth, WindHeight);
}

void GUI::CreateMenu() const
{
	pWind->SetBrush(StatusBarColor);
	pWind->SetPen(StatusBarColor);
	pWind->DrawRectangle(0, 0, WindWidth, MenuBarHeight);

	//You can draw the menu icons any way you want.

	//First prepare List of images paths for menu item
	string MenuItemImages[ITM_CNT];
	MenuItemImages[ITM_ADD] = "GUI\\Images\\Menu\\plus.jpg";
	MenuItemImages[ITM_DLT] = "GUI\\Images\\Menu\\remove.jpg";
	MenuItemImages[ITM_DISP] = "GUI\\Images\\Menu\\disp.jpg";
	MenuItemImages[ITM_CHNG_CODE] = "GUI\\Images\\Menu\\code.jpg";
	MenuItemImages[ITM_REORDER] = "GUI\\Images\\Menu\\rearrange.jpg";
	MenuItemImages[ITM_NOTE] = "GUI\\Images\\Menu\\note.jpg";
	MenuItemImages[ITM_SAVE_PLAN] = "GUI\\Images\\Menu\\save.jpg";
	MenuItemImages[ITM_LOAD_PLAN] = "GUI\\Images\\Menu\\import.jpg";
	MenuItemImages[ITM_LOAD_CRS_CATALOG] = "GUI\\Images\\Menu\\catalog.jpg";
	MenuItemImages[ITM_LOAD_REQ] = "GUI\\Images\\Menu\\req.jpg";
	MenuItemImages[ITM_GPA] = "GUI\\Images\\Menu\\gpa.jpg";
	MenuItemImages[ITM_S_LEVEL] = "GUI\\Images\\Menu\\level.jpg";
	MenuItemImages[ITM_OFFERING] = "GUI\\Images\\Menu\\offer.jpg";
	MenuItemImages[ITM_STATUS] = "GUI\\Images\\Menu\\status.jpg";


	MenuItemImages[ITM_EXIT] = "GUI\\Images\\Menu\\exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu items one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * MenuItemWidth, 0, MenuItemWidth, MenuBarHeight);



}


void GUI::get_nYears() const{
	if (Registrar::user_type.compare("Sci") == 0)
		GUI::nYears = 4;

	if (Registrar::user_type.compare("Eng") == 0)
		GUI::nYears = 5;
	

}

void GUI::DrawBackground() const
{
	get_nYears();
	pWind->SetBrush(StatusBarColor);
	pWind->SetPen(StatusBarColor);
	int width = WindWidth;
	int height = WindHeight - (MenuBarHeight + StatusBarHeight);
	string path;

	if (GUI::nYears == 4){
		path = "GUI\\Images\\Background\\four_years.jpg";
		pWind->DrawImage(path, 0, MenuBarHeight, width, height);
	}
	if(GUI::nYears == 5)
	{
		path = "GUI\\Images\\Background\\five_years.jpg";
		pWind->DrawImage(path, 0, MenuBarHeight, width, height);
	}
}

////////////////////////    Output functions    ///////////////////

//Prints a message on the status bar
void GUI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
						// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");
	pWind->SetPen(MsgColor);
	pWind->DrawString(MsgX, WindHeight - MsgY, msg);
}

//////////////////////////////////////////////////////////////////////////
void GUI::UpdateInterface() const
{
	
	pWind->SetBuffering(true);
	//Redraw everything
	CreateMenu();
	ClearStatusBar();
	ClearDrawingArea();
	DrawBackground();
	pWind->UpdateBuffer();
	pWind->SetBuffering(false);

}


void GUI::close() const
{
	pWind->SetPen(WHITE, 0);
	pWind->SetBrush(WHITE);

	// Draw a rectangle that covers the entire window
	pWind->DrawRectangle(0, 0, pWind->GetWidth(), pWind->GetHeight());

}

////////////////////////    Drawing functions    ///////////////////
void GUI::DrawCourse(const Course* pCrs)
{
	if (pCrs->isSelected())
		pWind->SetPen(HiColor, 2);
	else
	pWind->SetPen(DrawColor, 2);

	pWind->SetBrush(FillColor);
	graphicsInfo gInfo = pCrs->getGfxInfo();
	pWind->DrawRectangle(gInfo.x, gInfo.y, gInfo.x + CRS_WIDTH, gInfo.y + CRS_HEIGHT);
	pWind->DrawLine(gInfo.x, gInfo.y + CRS_HEIGHT / 2, gInfo.x + CRS_WIDTH, gInfo.y + CRS_HEIGHT / 2);
	
	//Write the course code and credit hours.
	int Code_x = gInfo.x + CRS_WIDTH * 0.15;
	int Code_y = gInfo.y + CRS_HEIGHT * 0.05;
	pWind->SetFont(CRS_HEIGHT * 0.4, BOLD , BY_NAME, "Gramound");
	pWind->SetPen(MsgColor);

	ostringstream crd;
	crd<< "crd:" << pCrs->getCredits();
	pWind->DrawString(Code_x, Code_y, pCrs->getCode());
	pWind->DrawString(Code_x, Code_y + CRS_HEIGHT/2, crd.str());
}

void GUI::DrawAcademicYear(const AcademicYear* pY) 
{
	graphicsInfo gInfo = pY->getGfxInfo();

	///TODO: compelete this function to:
	//		1- Draw a rectangle for the academic year 
	//		2- Draw a sub-rectangle for each semester
	//Then each course should be drawn inside rect of its year/sem
	
}


////////////////////////    Input functions    ///////////////////
//This function reads the position where the user clicks to determine the desired action
//If action is done by mouse, actData will be the filled by mouse position
ActionData GUI::GetUserAction(string msg) const
{
	keytype ktInput;
	clicktype ctInput;
	char cKeyData;

	
	// Flush out the input queues before beginning
	pWind->FlushMouseQueue();
	pWind->FlushKeyQueue();
	
	PrintMsg(msg);

	while (true)
	{
		int x, y;
		ctInput = pWind->GetMouseClick(x, y);	//Get the coordinates of the user click
		ktInput = pWind->GetKeyPress(cKeyData);

		if (ktInput == ESCAPE)	//if ESC is pressed,return CANCEL action
		{
			return ActionData{ CANCEL };
		}

		
		if (ctInput == LEFT_CLICK)	//mouse left click
		{
			//[1] If user clicks on the Menu bar
			if (y >= 0 && y < MenuBarHeight)
			{
				//Check whick Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_ADD: return ActionData{ ADD_CRS };	//Add course
				case ITM_DLT: return ActionData{ DEL_CRS };
				case ITM_DISP: return ActionData{ EXIT };
				case ITM_CHNG_CODE: return ActionData{ CHNGE_CRS_CODE };
				case ITM_REORDER: return ActionData{ EXIT };
				case ITM_NOTE: return ActionData{ ADD_NOTES };
				case ITM_SAVE_PLAN: return ActionData{ SAVE_plan };
				case ITM_LOAD_PLAN: return ActionData{ LOAD_plan };
				case ITM_LOAD_CRS_CATALOG: return ActionData{ LOAD_CRS_CATALOG };
				case ITM_LOAD_REQ: return ActionData{ LOAD_PRG_REQ };
				case ITM_EXIT: return ActionData{ EXIT };		//Exit
				case ITM_GPA: return ActionData{ GPA };
				case ITM_STATUS: return ActionData{ CRS_STATUS };
				case ITM_S_LEVEL: return ActionData{ S_LEVEL };
				case ITM_OFFERING: return ActionData{ CRS_OFFERING };

				default: return ActionData{ MENU_BAR };	//A click on empty place in menu bar
				}
			}

			//[2] User clicks on the drawing area
			if (y >= MenuBarHeight && y < WindHeight - StatusBarHeight && x > CellWidth)
			{
				SEMESTER sem = xtosem(x); 
				int yr = ytoyear(y);
				return ActionData{ DRAW_AREA, x, y, yr, sem };	//user want clicks inside drawing area
			}

			//[3] User clicks on the status bar
			return ActionData{ STATUS_BAR };
		}
	}//end while

}

SEMESTER GUI::xtosem(int x_cord) const
{
	int x = (x_cord / GUI::CellWidth) - 1;

	switch (x)
	{
	case 0:
		return FALL;
		break;
	case 1:
		return SPRING;
		break;
	case 2:
		return SUMMER;
		break;
	}

}


int GUI::ytoyear(int y_cord) const
{
	CellHeight = (WindHeight - (MenuBarHeight + StatusBarHeight)) / (nYears + 1);
	return ((y_cord - (CellHeight + MenuBarHeight)) / CellHeight) + 1;
}

int GUI::getCellHeight() const
{
	return CellHeight;
}

int GUI::getMenuBarHgight() const
{
	return MenuBarHeight;
}

int GUI::getCellWidth() const
{
	return CellWidth;
}

string GUI::GetSrting() const
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar

	

	string userInput;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);

		switch (Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input

		case 13:		//ENTER key is pressed
			return userInput;

		case 8:		//BackSpace is pressed
			if (userInput.size() > 0)
				userInput.resize(userInput.size() - 1);
			break;

		default:
			userInput += Key;
		};

		PrintMsg(userInput);
	}

}








GUI::~GUI()
{
	delete pWind;
}
