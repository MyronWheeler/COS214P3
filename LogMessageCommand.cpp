#include "LogMessageCommand.h"
#include <iostream>
using namespace std;
void LogMessageCommand::execute() {
    room->saveMessage(message, fromUser);
}