#include "SendMessageCommand.h"
#include <iostream>
using namespace std;
void SendMessageCommand::execute() {
    room->sendMessage(message, fromUser);
}