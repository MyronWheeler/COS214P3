#include "VectorCHIterator.h"

VectorCHIterator::VectorCHIterator(const std::vector<ChatRoom::ChatMessage>& history)
    : history(history), index(0) {}

bool VectorCHIterator::hasNext() {
    return index < history.size();
}

ChatRoom::ChatMessage VectorCHIterator::next() {
    if (hasNext() == true) {
        return history[index++];
    }
    // Return an empty message if out of bounds
    return ChatRoom::ChatMessage();
}

void VectorCHIterator::reset() {
    index = 0;
}