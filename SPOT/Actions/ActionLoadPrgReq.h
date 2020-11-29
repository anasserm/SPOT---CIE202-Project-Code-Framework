#pragma once
#include "Action.h"


class ActionLoadPrgReq
	:
	public Action
{
public:
	ActionLoadPrgReq(Registrar*);
	bool virtual Execute();
	virtual ~ActionLoadPrgReq();
};

