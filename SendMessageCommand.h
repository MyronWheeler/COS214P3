#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H
#include "Command.h"

class SendMessageCommand : public Command {


public:
	SendMessageCommand(ChatRoom* room, string message, Users* fromUser):Command(room, message, fromUser) {}
	void execute();
};

#endif
