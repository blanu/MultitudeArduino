#include <stdlib.h>
#include "AudioStream.h"
#include "MutableMultitudeInt.hpp"

int MutableMultitudeInt::length()
{
  return this->size;
}

bool MutableMultitudeInt::getInt(int index, int *result)
{
    if ((index < 0) || (index >= this->length()))
    {
        return false;
    }

    *result = this->data[index];
    return true;
}

bool MutableMultitudeInt::becomeSetInt(int index, int newValue)
{
    if ((index < 0) || (index >= this->length()))
    {
        return false;
    }

    this->data[index] = newValue;
    return true;
}

void MutableMultitudeInt::becomeMultiply(MutableMultitudeInt *other)
{
    if (other->length() == 0)
    {
        return;
    }

    int otherIndex = 0;
    int a=0;
    int b=0;
    int result=0;
    for(int index = 0 ; index <= AUDIO_BLOCK_SAMPLES ; index++)
    {
        if (!this->getInt(index, &a))
        {
            return;
        }

        if (!other->getInt(otherIndex, &b))
        {
            return;
        }

        result = a * b;

        this->becomeSetInt(index, result);

        otherIndex++;
        if (otherIndex == other->length())
        {
            otherIndex = 0;
        }
    }
}

MutableMultitudeInt *MutableMultitudeInt::append(MutableMultitudeInt *other)
{
    int newLength = this->length() + other->length();
    MutableMultitudeInt *result = new MutableMultitudeInt(newLength);
    int value = 0;
    for(int index = 0 ; index < this->length() ; index ++)
    {
        if (!this->getInt(index, &value))
        {
            return result;
        }

        result->becomeSetInt(index, value);
    }

    for(int index = 0 ; index < other->length() ; index ++)
    {
        if (!other->getInt(index, &value))
        {
            return result;
        }

        result->becomeSetInt(this->length() + index, value);
    }

    return result;
}

MutableMultitudeInt *MutableMultitudeInt::replicate(MutableMultitudeInt *selector)
{
    int size = selector->sum();
    MutableMultitudeInt *result = new MutableMultitudeInt(size);
    int outputIndex = 0;
    int total = 0;
    int value = 0;
    for(int index = 0 ; index < selector->length() ; index++ )
    {
        if (!this->getInt(index, &value))
        {
            return result;
        }

        if (!selector->getInt(index, &total))
        {
            return result;
        }

        for(int count = 0; count < total; count++)
        {
            result->becomeSetInt(outputIndex, value);
            outputIndex++;
        }
    }

    return result;
}

int MutableMultitudeInt::sum()
{
    int result = 0;
    for(int index = 0 ; index < this->length(); index++ )
    {
        result += this->data[index];
    }

    return result;
}
