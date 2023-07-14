#ifndef _MUTABLE_MULTITUDE_AUDIO_BLOCK_H_
#define _MUTABLE_MULTITUDE_AUDIO_BLOCK_H_

#include <AudioStream.h>
#include "MutableMultitude.hpp"
#include "MutableMultitudeInt.hpp"

class MutableMultitudeAudioBlock: MutableMultitude
{
  public:
    MutableMultitudeAudioBlock(audio_block_t *block) : block(block) {}

    int length();
    bool getInt(int index, int *result);

    bool becomeSetInt(int index, int newValue);
    void becomeMultiply(MutableMultitudeInt *other);

private:
    audio_block_t *block;
};

#endif
