//
// Created by Dr. Brandon Wiley on 6/29/23.
//

#ifndef _MULTITUDE_H
#define _MULTITUDE_H

class Multitude {
public:
    virtual int length();
    virtual bool getInt(int index, int *result);
    virtual int sum();
};

#endif //MULTITUDEARDUINO_MULTITUDE_H
