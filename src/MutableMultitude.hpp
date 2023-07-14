#ifndef _MUTABLE_MULTITUDE_H_
#define _MUTABLE_MULTITUDE_H_

#include "Multitude.hpp"

class MutableMultitude: Multitude
{
  public:
    virtual bool becomeSetInt(int index, int newValue);
};

#endif
