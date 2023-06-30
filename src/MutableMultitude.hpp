#ifndef _MULTITUDE_H_
#define _MULTITUDE_H_

class MutableMultitude
{
  public:
    virtual int length();
    virtual bool getInt(int index, int *result);
    virtual bool becomeSetInt(int index, int newValue);
//    virtual void becomeMultiply(MutableMultitude other);
//    virtual MutableMultitude append(MutableMultitude other);
//    virtual MutableMultitude replicate(MutableMultitude selector);
    virtual int sum();
};

#endif
