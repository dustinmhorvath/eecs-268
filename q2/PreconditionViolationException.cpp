/**
*	@file PreconditionViolationException.cpp
*	@author John Gibbons
*	@date 2014.04.09
*/

#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* message) : std::runtime_error(message)
{ }
