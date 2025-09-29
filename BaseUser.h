/**
 * @file BaseUser.h
 * @brief Declares the BaseUser class, a concrete implementation of Users.
 * @author u24574547_u24579565
 * @date 2025-09-27
 */

#ifndef COS214P3_NORMALUSER_H
#define COS214P3_NORMALUSER_H
#include "Users.h"
using namespace std;

/**
 * @class BaseUser
 * @brief Represents a basic user in the chat system.
 *
 * Stores user information, chat rooms, and command queue.
 */
class BaseUser: public Users {
    friend class UserDecorator;
protected:
    vector<ChatRoom*> chatRooms; ///< List of chat rooms the user belongs to.
    string name; ///< Users name.
    vector<Command*> commandQueue; ///< Queue of commands to execute.
    int id; ///< Users unique identifier.
public:
    /**
     * @brief Constructor.
     * @param name Users name.
     * @param id Users ID.
     */
    BaseUser(string name, int id);

    /**
     * @brief Destructor.
     */
    virtual ~BaseUser() override;

    /**
     * @brief Add a command to the users queue.
     * @param command Pointer to the command.
     */
    virtual void addCommand(Command* command) override;

    /**
     * @brief Get the users ID.
     * @return Users ID.
     */
    virtual int getId() override;

    /**
     * @brief Execute all commands in the queue.
     */
    virtual void executeAll() override;

    /**
     * @brief Add a chat room to the users list.
     * @param rooms Pointer to the chat room.
     */
    virtual void setChatRooms(ChatRoom* rooms) override;

    /**
     * @brief Get the users name.
     * @return Users name.
     */
    virtual string getName() override;

    /**
     * @brief Receive a message from a chat room.
     * @param message Pointer to the message.
     * @param room Pointer to the chat room.
     */
    virtual void receive(ChatRoom::ChatMessage* message, ChatRoom* room) override;
protected:
    /**
     * @brief Get the list of chat rooms.
     * @return Vector of chat room pointers.
     */
    virtual vector<ChatRoom*> getChatRooms();
    virtual void removeChatRoom(ChatRoom* room) override;
};

#endif //COS214P3_NORMALUSER_H