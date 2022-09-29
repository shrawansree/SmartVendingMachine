#ifndef CARDREADER_H
#define CARDREADER_H

#include "../mbed.h"

class CardReader{

public:

    //card reader function
    CardReader(PinName port);
    void init();
    float get_value();

private:

    AnalogIn port;
};

#endif