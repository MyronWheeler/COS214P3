#include "Dogorithm.h"
#include <iostream>
#include <string>
using namespace std;

Dogorithm::Dogorithm(){
    // Constructor is empty i guess
}
void Dogorithm::registerUser(Users* User){
    users.push_back(User);
}
void Dogorithm::sendMessage(std::string message, Users* fromUser){
    for (Users* user : users){
        if (user->getName() != fromUser->getName()){
            user->receive(message, fromUser, this);
        }
    }
    saveMessage(message, fromUser);
}
void Dogorithm::saveMessage(string message, Users* fromUser){
    string fullMessage = fromUser->getName() + ": " + message;
    chatHistory.push_back(fullMessage);
    // cout to say we saved, should be removed later cuase we will be saying
    // "saved" every message
    cout << "Message saved to Dogorithm chat history." << endl;
}
void Dogorithm::removeUser(Users* user){
    std::vector<Users*> newList;
    for (Users* u : users) {
        if (u != user) newList.push_back(u);
    }
    users = std::move(newList);
    std::cout << user->getName() << " left Dogorithm" << std::endl;
}



