#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H
#include "Command.h"

class SendMessageCommand : public Command {


public:
	SendMessageCommand(ChatRoom* room, string message, Users* fromUser) {
		this->room = room;
		this->message = message;
		this->fromUser = fromUser;
	}
	void execute();
};

#endif
