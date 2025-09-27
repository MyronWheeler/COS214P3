#include "CtrlCat.h"
using namespace std;

CtrlCat::CtrlCat() : ChatRoom() {
    //users and chatHistory are initialized in ChatRoom constructor
    
}
void CtrlCat::registerUser(Users* User){
    users.push_back(User);
}
void CtrlCat::sendMessage(ChatMessage* message){
    //TODO: why add the check here but not in Dogorithm? I think this is unnecessary for a prac, no one is trying to hack it
    // My fault I forgot to add it in Dogorithm but I mean why not have it its not deep
    bool found = false;
    for (Users* user : users){
        if (user->getName() == message->sender->getName()){
            found = true;
            break;
        }
    }
    if (found == false){
        cout << message->sender->getName() << " is not in CtrlCat chat room. Message not sent." << endl;
        return;
    }
    // If they are, we send the message
    for (Users* user : users){
        if (user->getName() != message->sender->getName()){
            user->receive(message, this);
        }
    }
    // saveMessage(message, fromUser);
}
void CtrlCat::saveMessage(ChatMessage* message){
    //check to see if they are in the chatRoom
    //TODO: check also present here
    bool found = false;
    for (Users* user : users){
        if (user->getName() == message->sender->getName()){
            found = true;
            break;
        }
    }
    if (found == false){
        cout << message->sender->getName() << " is not in CtrlCat chat room. Message not saved." << endl;
        return;
    }
    // If they are, we save the message
    chatHistory.push_back(message);
    // cout to say we saved
    cout << "Message saved to CtrlCat chat history." << endl;
}
void CtrlCat::removeUser(Users* user){
    std::vector<Users*> newList;
    for (Users* u : users) {
        if (u != user) newList.push_back(u);
    }
    users = std::move(newList);
    std::cout << user->getName() << " left CtrlCat" << std::endl;
}



