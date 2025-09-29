/**
 * @file SendMessageCommand.h
 * @brief Declares the SendMessageCommand class for sending messages to chat rooms.
 * @author u24574547_u24579565
 * @date 2025-09-27
 */

#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H
#include "Command.h"

/**
 * @class SendMessageCommand
 * @brief Command to send a message to a chat room.
 */
class SendMessageCommand : public Command {
public:
    /**
     * @brief Constructor.
     * @param room Pointer to the chat room.
     * @param message Pointer to the chat message.
     */
    SendMessageCommand(ChatRoom* room, ChatRoom::ChatMessage* message):Command(room, message) {}

    /**
     * @brief Execute the send command.
     */
    void execute();
};

#endif
