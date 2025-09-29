/**
 * @file LogMessageCommand.h
 * @brief Declares the LogMessageCommand class for logging messages to chat history.
 * @author u24574547_u24579565
 * @date 2025-09-27
 */

#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H
#include "Command.h"

/**
 * @class LogMessageCommand
 * @brief Command to log a message to the chat history.
 */
class LogMessageCommand : public Command {
public:
    /**
     * @brief Constructor.
     * @param room Pointer to the chat room.
     * @param message Pointer to the chat message.
     */
    LogMessageCommand(ChatRoom* room, ChatRoom::ChatMessage* message):Command(room, message) {}

    /**
     * @brief Execute the log command.
     */
    void execute();
};

#endif
