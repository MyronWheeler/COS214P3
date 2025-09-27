#ifndef CHITERATOR_H
#define CHITERATOR_H

#include <string>
#include "ChatRoom.h"

class CHIterator {
public:
    virtual ~CHIterator() {}
    virtual bool hasNext() = 0;
    virtual ChatRoom::ChatMessage* next() = 0;
    virtual void reset() = 0;
};

#endif