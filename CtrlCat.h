/**
 * @file CtrlCat.h
 * @brief Declares the CtrlCat chat room class, a concrete ChatRoom implementation.
 * @author u24574547_u24579565
 * @date 2025-09-27
 */

#ifndef CTRLCAT_H
#define CTRLCAT_H
#include "ChatRoom.h"
#include "Users.h"
#include <iostream>
#include <string>

/**
 * @class CtrlCat
 * @brief Concrete chat room for CtrlCat.
 */
class CtrlCat : public ChatRoom {
public:
const string roomName = "CtrlCat";
    /**
     * @brief Constructor.
     */
    CtrlCat();
    /**
     * @brief Destructor.
     */
    virtual ~CtrlCat() override;

    /**
     * @brief Register a user to the chat room.
     * @param User Pointer to the user.
     */
    void registerUser(Users* User) override;

    /**
     * @brief Send a message to the chat room.
     * @param message Pointer to the message.
     */
    void sendMessage(ChatMessage* message) override;

    /**
     * @brief Save a message to the chat history.
     * @param message Pointer to the message.
     */
    void saveMessage(ChatMessage* message) override;

    /**
     * @brief Remove a user from the chat room.
     * @param user Pointer to the user.
     */
    void removeUser(Users* user) override;

    /**
     * @brief Create an iterator for the chat history.
     * @return Pointer to a CHIterator.
     */
    CHIterator* createIterator() override;
    /**
     * @brief Get the room name.
     * @return The name of the chat room.
     */
    string getRoomName() override { return roomName; }
};

#endif
