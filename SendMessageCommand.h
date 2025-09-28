#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H
#include "Command.h"

class SendMessageCommand : public Command {
public:
	SendMessageCommand(ChatRoom* room, ChatRoom::ChatMessage* message):Command(room, message) {}
	void execute();
};

#endif
