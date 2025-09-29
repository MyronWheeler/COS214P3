/**
 * @file VectorCHIterator.h
 * @brief Declares the VectorCHIterator class for traversing chat history stored in a vector.
 * @author u24574547_u24579565
 * @date 2025-09-27
 */

#ifndef VECTORCHITERATOR_H
#define VECTORCHITERATOR_H

#include "CHIterator.h"
#include <vector>
#include "ChatRoom.h"
using namespace std;

/**
 * @class VectorCHIterator
 * @brief Concrete iterator for chat history using vector.
 *
 * Iterates over a vector of ChatRoom::ChatMessage pointers.
 */
class VectorCHIterator : public CHIterator {
private:
    const vector<ChatRoom::ChatMessage*>& history; ///< Reference to chat history vector.
    size_t index; ///< Current position in the history.
public:
    /**
     * @brief Constructor.
     * @param history Reference to the vector of chat messages.
     */
    VectorCHIterator(const vector<ChatRoom::ChatMessage*>& history);

    /**
     * @brief Checks if there are more messages.
     * @return True if more messages exist, false otherwise.
     */
    bool hasNext() override;

    /**
     * @brief Returns the next chat message.
     * @return Pointer to the next ChatMessage.
     */
    ChatRoom::ChatMessage* next() override;

    /**
     * @brief Resets the iterator to the beginning.
     */
    void reset() override;
};

#endif