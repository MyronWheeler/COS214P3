#include "CtrlCat.h"
#include <iostream>
#include <string>
using namespace std;

CtrlCat::CtrlCat(){
    // Constructor is empty i guess
}
void CtrlCat::registerUser(Users* User){
    users.push_back(User);
}
void CtrlCat::sendMessage(std::string message, Users* fromUser){
    // I'm gonna add a check to see if the user is in the chat room
    // If they arent, we dont send the message
    //TODO: why add the check here but not in Dogorithm? I think this is unnecessary for a prac, no one is trying to hack it
    bool found = false;
    for (Users* user : users){
        if (user->getName() == fromUser->getName()){
            found = true;
            break;
        }
    }
    if (found == false){
        cout << fromUser->getName() << " is not in CtrlCat chat room. Message not sent." << endl;
        return;
    }
    // If they are, we send the message
    for (Users* user : users){
        if (user->getName() != fromUser->getName()){
            user->receive(message, fromUser, this);
        }
    }
    // saveMessage(message, fromUser);
}
void CtrlCat::saveMessage(string message, Users* fromUser){
    //check to see if they are in the chatRoom
    //TODO: check also present here
    bool found = false;
    for (Users* user : users){
        if (user->getName() == fromUser->getName()){
            found = true;
            break;
        }
    }
    if (found == false){
        cout << fromUser->getName() << " is not in CtrlCat chat room. Message not saved." << endl;
        return;
    }
    // If they are, we save the message
    ChatMessage messagePack = ChatMessage();
    messagePack.message = message;
    messagePack.sender = fromUser;
    messagePack.timestamp = time(NULL);
    chatHistory.push_back(messagePack);
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



