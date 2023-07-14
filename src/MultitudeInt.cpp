//
// Created by Dr. Brandon Wiley on 6/29/23.
//

#include <stdlib.h>
#include "AudioStream.h"
#include "MultitudeInt.hpp"

int MultitudeInt::length()
{
    return this->size;
}

bool MultitudeInt::getInt(int index, int *result)
{
    if ((index < 0) || (index >= this->length()))
    {
        return false;
    }

    *result = this->data[index];
    return true;
}

MultitudeInt *MultitudeInt::append(MultitudeInt *other)
{
    int newLength = this->length() + other->length();
    MultitudeInt *result = new MultitudeInt(newLength);
    int value = 0;
    for(int index = 0 ; index < this->length() ; index ++)
    {
        if (!this->getInt(index, &value))
        {
            return result;
        }

        result->data[index] = value;
    }

    for(int index = 0 ; index < other->length() ; index ++)
    {
        if (!other->getInt(index, &value))
        {
            return result;
        }

        result->data[this->length() + index] = value;
    }

    return result;
}

MultitudeInt *MultitudeInt::replicate(MultitudeInt *selector)
{
    int size = selector->sum();
    MultitudeInt *result = new MultitudeInt(size);
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
            result->data[outputIndex] = value;
            outputIndex++;
        }
    }

    return result;
}

MultitudeInt *MultitudeInt::replicate(int repeats)
{
    int size = this->length() * repeats;
    MultitudeInt *result = new MultitudeInt(size);
    int outputIndex = 0;
    int value = 0;
    for (int index = 0; index < this->length(); index++)
    {
        if (!this->getInt(index, &value))
        {
            return result;
        }

        for (int count = 0; count < repeats; count++)
        {
            result->data[outputIndex] = value;
            outputIndex++;
        }
    }

    return result;
}

int MultitudeInt::sum()
{
    int result = 0;
    for(int index = 0 ; index < this->length(); index++ )
    {
        result += this->data[index];
    }

    return result;
}
