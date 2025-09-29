/**
 * @file CHIterator.h
 * @brief Declares the abstract iterator for chat history traversal.
 * @author u24574547_u24579565
 * @date 2025-09-27
 */

#ifndef CHITERATOR_H
#define CHITERATOR_H

#include <string>
#include "ChatRoom.h"

/**
 * @class CHIterator
 * @brief Abstract base class for iterating over chat history.
 */
class CHIterator {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~CHIterator() {}

    /**
     * @brief Check if there are more messages.
     * @return True if more messages exist, false otherwise.
     */
    virtual bool hasNext() = 0;

    /**
     * @brief Get the next chat message.
     * @return Pointer to the next ChatMessage.
     */
    virtual ChatRoom::ChatMessage* next() = 0;

    /**
     * @brief Reset the iterator to the beginning.
     */
    virtual void reset() = 0;
};

#endif