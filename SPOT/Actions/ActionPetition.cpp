#include "ActionPetition.h"

ActionPetition::ActionPetition(Registrar* r): Action (r)
{
}

bool ActionPetition::Execute()
{
	return false;
}

ActionPetition::~ActionPetition()
{
}
