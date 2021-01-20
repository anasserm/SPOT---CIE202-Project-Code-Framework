#pragma once
#include "Action.h"

class ActionCheckReq : public Action
{
public:
	ActionCheckReq(Registrar* r);
	bool virtual Execute();
	virtual ~ActionCheckReq();

};