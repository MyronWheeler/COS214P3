#include "NormalUser.h"

void NormalUser::send(string message, ChatRoom* room){
    ChatRoom::ChatMessage* msg = new ChatRoom::ChatMessage();
    msg->message = message;
    msg->sender = this;
    msg->timestamp = time(NULL);

    room->sendMessage(msg);
}
void NormalUser::receive(ChatRoom::ChatMessage* message, ChatRoom* room){
    cout << "[" << room << "] " << message->sender->getName() << ": " << message->message << endl;
}