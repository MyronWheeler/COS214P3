/**
 * @file Command.h
 * @brief Declares the Command abstract class for command pattern operations.
 * @author u24574547_u24579565
 * @date 2025-09-27
 */

#ifndef COMMAND_H
#define COMMAND_H
#include "ChatRoom.h"
#include <string>
class Users;
#include "Users.h"
using namespace std;

/**
 * @class Command
 * @brief Abstract base class for commands executed by users.
 */
class Command {

protected:
    ChatRoom::ChatMessage* message; ///< Message associated with the command.
    ChatRoom* room; ///< Chat room associated with the command.

public:
    /**
     * @brief Constructor.
     * @param room Pointer to the chat room.
     * @param message Pointer to the chat message.
     */
    Command(ChatRoom* room, ChatRoom::ChatMessage* message) {
        this->room = room;
        this->message = message;
    }

    /**
     * @brief Virtual destructor.
     */
    virtual ~Command();

    /**
     * @brief Execute the command.
     */
    virtual void execute() = 0;
};

#endif
