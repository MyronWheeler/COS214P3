/**
 * @file UserDecorator.h
 * @brief Declares the UserDecorator class for extending user functionality.
 * @author u24574547_u24579565
 * @date 2025-09-27
 */

#ifndef COS214P3_USERDECORATOR_H
#define COS214P3_USERDECORATOR_H
#include "Users.h"

/**
 * @class UserDecorator
 * @brief Abstract decorator for Users, allowing extension of user functionality.
 */
class UserDecorator: public Users {
protected:
    Users* user; ///< Pointer to the decorated user.
public:
    /**
     * @brief Constructor.
     * @param user Pointer to the user being decorated.
     */
    UserDecorator(Users* user);

    /**
     * @brief Destructor.
     */
    virtual ~UserDecorator() override;

    /**
     * @brief Receive a message from a chat room.
     * @param message Pointer to the message.
     * @param room Pointer to the chat room.
     */
    virtual void receive(ChatRoom::ChatMessage* message, ChatRoom* room)override;

    /**
     * @brief Add a command to the user's queue.
     * @param command Pointer to the command.
     */
    virtual void addCommand(Command* command) override;

    /**
     * @brief Execute all commands in the queue.
     */
    virtual void executeAll() override;

    /**
     * @brief Add a chat room to the user's list.
     * @param rooms Pointer to the chat room.
     */
    virtual void setChatRooms(ChatRoom* rooms) override;

    /**
     * @brief Get the user's name.
     * @return User's name.
     */
    virtual string getName() override;

    /**
     * @brief Send a message to a chat room.
     * @param message The message content.
     * @param room Pointer to the chat room.
     */
    virtual void send(string message, ChatRoom* room);

    /**
     * @brief Get the user's ID.
     * @return User's ID.
     */
    virtual int getId()override;

    /**
     * @brief Get the list of chat rooms.
     * @return Vector of chat room pointers.
     */
    virtual vector<ChatRoom*> getChatRooms();
    virtual void removeChatRoom(ChatRoom* room) override;

    friend class Administrator; ///< Allows Administrator to access getChatRooms securely.
};

#endif //COS214P3_USERDECORATOR_H