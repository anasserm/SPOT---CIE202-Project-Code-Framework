#pragma once
#include "Action.h"

class ActionStatus :public Action
{

	public:
		ActionStatus(Registrar* r);
		bool virtual Execute();
		virtual ~ActionStatus();
	



};
