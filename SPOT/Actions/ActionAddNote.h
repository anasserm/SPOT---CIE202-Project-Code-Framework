#pragma once
#include "Action.h"

class ActionAddNote : public Action
{
	public:
		ActionAddNote(Registrar*);
		bool virtual Execute();
		virtual ~ActionAddNote();

};

