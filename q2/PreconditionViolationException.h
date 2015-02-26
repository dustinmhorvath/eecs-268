/**
*	@file PreconditionViolationException.h
*	@author John Gibbons
*	@date 2014.04.09
*/

#ifndef PRECONDITION_VIOLATION_EXCEPTION_H
#define PRECONDITION_VIOLATION_EXCEPTION_H

#include <stdexcept>

class PreconditionViolationException : public std::runtime_error
{
	public:
	PreconditionViolationException(const char* message);

};
#endif
