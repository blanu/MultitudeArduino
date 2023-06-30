#include "AudioStream.h"
#include "MutableMultitudeAudioBlock.hpp"
#include "MutableMultitudeInt.hpp"

int MutableMultitudeAudioBlock::length()
{
  return AUDIO_BLOCK_SAMPLES;
}

bool MutableMultitudeAudioBlock::getInt(int index, int *result)
{
    if ((index < 0) || (index >= this->length()))
    {
        return false;
    }

    *result = (int)this->block->data[index];
    return true;
}

bool MutableMultitudeAudioBlock::becomeSetInt(int index, int newValue)
{
    if ((index < 0) || (index >= this->length()))
    {
        return false;
    }

    this->block->data[index] = (int16_t)newValue;
    return true;
}

void MutableMultitudeAudioBlock::becomeMultiply(MutableMultitude *other)
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
