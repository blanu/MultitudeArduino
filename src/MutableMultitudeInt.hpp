#ifndef _MULTITUDE_AUDIO_BLOCK_H_
#define _MULTITUDE_AUDIO_BLOCK_H_

#include <AudioStream.h>
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
    bool becomeSetInt(int index, int newValue);
    void becomeMultiply(MutableMultitudeInt *other);
    MutableMultitudeInt *append(MutableMultitudeInt *other);
    MutableMultitudeInt *replicate(MutableMultitudeInt *selector);
    int sum();

private:
    int *data;
    int size;
};

#endif
