#ifndef ERRORTYPE_H

#define ERRORTYPE_H



enum class ErrorType
{
    Success 			= 0, // nie wystapil zaden problem
    WrongType			= -1,
    InvalidValue		= -2
};

#endif // ERRORTYPE_H
