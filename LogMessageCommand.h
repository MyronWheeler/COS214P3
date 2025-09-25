#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H
#include "Command.h"

class LogMessageCommand : public Command {
public:
	LogMessageCommand(ChatRoom* room, ChatRoom::ChatMessage message, Users* fromUser):Command(room, message, fromUser) {}
	void execute();
};

#endif
