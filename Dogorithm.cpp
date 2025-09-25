#include "Dogorithm.h"

Dogorithm::Dogorithm() : ChatRoom() {
}
void Dogorithm::registerUser(Users* User){
    users.push_back(User);
}
void Dogorithm::sendMessage(ChatMessage message, Users* fromUser){

    bool found = false;
    for (Users* user : users){
        if (user->getName() == fromUser->getName()){
            found = true;
            break;
        }
    }
    if (found == false){
        cout << fromUser->getName() << " is not in Dogorithm chat room. Message not sent." << endl;
        return;
    }

    for (Users* user : users){
        if (user->getName() != fromUser->getName()){
            user->receive(message, fromUser, this);
        }
    }
    
}
void Dogorithm::saveMessage(string message, Users* fromUser){
    
    ChatMessage messagePack = ChatMessage();
    messagePack.message = message;
    messagePack.sender = fromUser;
    messagePack.timestamp = time(NULL);
    chatHistory.push_back(messagePack);
    // cout to say we saved, should be removed later cuase we will be saying
    // "saved" every message
    //cout << "Message saved to Dogorithm chat history." << endl;
}
void Dogorithm::removeUser(Users* user){
    std::vector<Users*> newList;
    for (Users* u : users) {
        if (u != user) newList.push_back(u);
    }
    users = std::move(newList);
    std::cout << user->getName() << " left Dogorithm" << std::endl;
}



