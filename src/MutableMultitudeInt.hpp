#ifndef _MUTABLE_MULTITUDE_INT_H_
#define _MUTABLE_MULTITUDE_INT_H_

#include <stdlib.h>
#include "MutableMultitude.hpp"

class MutableMultitudeInt: MutableMultitude
{
public:
    MutableMultitudeInt(int *data, int size) : data(data), size(size) {}
    MutableMultitudeInt(int size) : size(size)
    {
        data = (int *)calloc(size, sizeof(int));
    }

    ~MutableMultitudeInt()
    {
        free(data);
    }

    int length();
    bool getInt(int index, int *result);
    MutableMultitudeInt *append(MutableMultitudeInt *other);
    MutableMultitudeInt *replicate(MutableMultitudeInt *selector);
    MutableMultitudeInt *replicate(int repeats);
    int sum();

    bool becomeSetInt(int index, int newValue);
    void becomeMultiply(MutableMultitudeInt *other);

private:
    int *data;
    int size;
};

#endif
