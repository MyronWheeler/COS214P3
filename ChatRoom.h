/**
 * @file ChatRoom.h
 * @brief Declares the ChatRoom abstract class for chat room functionality.
 * @author u24574547_u24579565
 * @date 2025-09-27
 */

#ifndef CHATROOM_H
#define CHATROOM_H
#include <string>
#include <vector>
using namespace std;
class Users;
class VectorCHIterator;
class CHIterator;

/**
 * @class ChatRoom
 * @brief Abstract base class representing a chat room.
 *
 * Stores users and chat history, and provides interfaces for messaging.
 */
class ChatRoom {
    public:
        /**
         * @struct ChatMessage
         * @brief Represents a message in the chat room.
         */
        struct ChatMessage {
            long timestamp; ///< Time the message was sent.
            string message; ///< Message content.
            Users* sender;  ///< Pointer to the sender.
        };

        /**
         * @brief Constructor.
         */
        ChatRoom();

        /**
         * @brief Destructor.
         */
        virtual ~ChatRoom();

        /**
         * @brief Register a user to the chat room.
         * @param User Pointer to the user.
         */
        virtual void registerUser(Users* User) = 0;

        /**
         * @brief Send a message to the chat room.
         * @param message Pointer to the message.
         */
        virtual void sendMessage(ChatMessage* message) = 0;

        /**
         * @brief Save a message to the chat history.
         * @param message Pointer to the message.
         */
        virtual void saveMessage(ChatMessage*) = 0;

        /**
         * @brief Remove a user from the chat room.
         * @param user Pointer to the user.
         */
        virtual void removeUser(Users* user) = 0;

        /**
         * @brief Create an iterator for the chat history.
         * @return Pointer to a CHIterator.
         */
        virtual CHIterator* createIterator() = 0;

protected:
    vector<Users*> users; ///< List of users in the chat room.
    vector<ChatMessage*> chatHistory; ///< Chat history.
};

#endif
