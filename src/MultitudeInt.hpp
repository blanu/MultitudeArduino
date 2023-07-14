//
// Created by Dr. Brandon Wiley on 6/29/23.
//

#ifndef _MULTITUDE_INT_H
#define _MULTITUDE_INT_H

#include <stdio.h>
#include "Multitude.hpp"

class MultitudeInt: Multitude {
public:
    static MultitudeInt *replicate(int x, int y)
    {
        MultitudeInt *result = new MultitudeInt(y);
        memset(result->data, x, y * sizeof(int));
        return result;
    }

    static MultitudeInt *replicate(int x, MultitudeInt *y)
    {
        int size = y->sum();
        MultitudeInt *result = new MultitudeInt(size);
        memset(result->data, x, size*sizeof(int));
        return result;
    }

    MultitudeInt(int *data, int size) : data(data), size(size) {}
    MultitudeInt(int size) : size(size)
    {
        data = (int *)calloc(size, sizeof(int));
    }

    ~MultitudeInt()
    {
        free(data);
    }

    int length();
    bool getInt(int index, int *result);
    MultitudeInt *append(MultitudeInt *other);
    MultitudeInt *replicate(MultitudeInt *selector);
    MultitudeInt *replicate(int repeats);
    int sum();

private:
    int *data;
    int size;

};


#endif //MULTITUDEARDUINO_MULTITUDEINT_H
