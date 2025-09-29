/**
 * @file Sender.h
 * @brief Declares the Sender decorator for users with message sending privileges.
 * @author u24574547_u24579565
 * @date 2025-09-27
 */

#ifndef COS214P3_SENDER_H
#define COS214P3_SENDER_H
#include "UserDecorator.h"

/**
 * @class Sender
 * @brief Decorator that allows a user to send messages.
 */
class Sender: public UserDecorator {
    public:
    /**
     * @brief Constructor.
     * @param user Pointer to the user being decorated.
     */
    Sender(Users* user): UserDecorator(user){};

    /**
     * @brief Destructor.
     */
    virtual ~Sender(){};

    /**
     * @brief Send a message to a chat room.
     * @param message The message content.
     * @param room Pointer to the chat room.
     */
    virtual void send(string message, ChatRoom* room) override;
};

#endif //COS214P3_SENDER_H