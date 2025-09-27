#ifndef VECTORCHITERATOR_H
#define VECTORCHITERATOR_H

#include "CHIterator.h"
#include <vector>
#include "ChatRoom.h"

class VectorCHIterator : public CHIterator {
private:
    const std::vector<ChatRoom::ChatMessage*>& history;
    size_t index;
public:
    VectorCHIterator(const std::vector<ChatRoom::ChatMessage*>& history);
    bool hasNext() override;
    ChatRoom::ChatMessage* next() override;
    void reset() override;
};

#endif