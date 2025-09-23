#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H
#include "Command.h"

class LogMessageCommand : public Command {


public:
	LogMessageCommand(ChatRoom* room, string message, Users* fromUser):Command(room, message, fromUser) {}
	void execute();
};

#endif
