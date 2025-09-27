#include "Dogorithm.h"

Dogorithm::Dogorithm() : ChatRoom() {
}
void Dogorithm::registerUser(Users* User){
    users.push_back(User);
}
void Dogorithm::sendMessage(ChatMessage* message){

    bool found = false;
    for (Users* user : users){
        if (user->getName() == message->sender->getName()){
            found = true;
            break;
        }
    }
    if (found == false){
        cout << message->sender->getName() << " is not in Dogorithm chat room. Message not sent." << endl;
        return;
    }

    for (Users* user : users){
        if (user->getName() != message->sender->getName()){
            user->receive(message, this);
        }
    }
    
}
void Dogorithm::saveMessage(ChatMessage* message){
    chatHistory.push_back(message);
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



