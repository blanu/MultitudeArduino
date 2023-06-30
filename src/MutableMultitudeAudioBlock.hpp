#ifndef _MULTITUDE_AUDIO_BLOCK_H_
#define _MULTITUDE_AUDIO_BLOCK_H_

#include <AudioStream.h>
#include "MutableMultitude.hpp"

class MutableMultitudeAudioBlock: MutableMultitude
{
  public:
    MutableMultitudeAudioBlock(audio_block_t *block) : block(block) {}

    int length();
    bool getInt(int index, int *result);
    bool becomeSetInt(int index, int newValue);
    void becomeMultiply(MutableMultitude *other);

private:
    audio_block_t *block;
};

#endif
