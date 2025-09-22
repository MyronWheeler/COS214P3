#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H
#include "Command.h"

class LogMessageCommand : public Command {


public:
	LogMessageCommand(ChatRoom* room, string message, Users* fromUser) {
		this->room = room;
		this->message = message;
		this->fromUser = fromUser;
	}
	void execute();
};

#endif
