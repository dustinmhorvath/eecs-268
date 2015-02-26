#include <stdexcept>

#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H

class MazeCreationException : public std::runtime_error{

public:
          /**
          * @post Creates an exception with the message
          */
          MazeCreationException(const char* message);

};

#endif
