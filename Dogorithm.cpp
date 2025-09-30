#include "Dogorithm.h"
#include "VectorCHIterator.h"

Dogorithm::Dogorithm() : ChatRoom() {
}
// Now cause we make a copy we need to implement the deconstructor
Dogorithm::~Dogorithm() {
    for (ChatMessage* msg : chatHistory) {
        delete msg; // Free each ChatMessage
    }
    chatHistory.clear(); // Clear the vector
}
void Dogorithm::registerUser(Users* User){
    // Check to see if they are already registered
    for (Users* u : users) {
        if (u->getId() == User->getId()) {
            cout << User->getName() << " is already registered in Dogorithm." << endl;
            return;
        }
    }
    users.push_back(User);
    // added functionality to also add chatroom to users list
    User->setChatRooms(this);
}
void Dogorithm::sendMessage(ChatMessage* message){

    bool found = false;
    for (Users* user : users){
        if (user->getId() == message->sender->getId()){
            found = true;
            break;
        }
    }
    if (found == false){
        cout << message->sender->getName() << " is not in Dogorithm chat room. Message not sent." << endl;
        return;
    }

    for (Users* user : users){
        if (user->getId() != message->sender->getId()){
            user->receive(message, this);
        }
    }
    
}
void Dogorithm::saveMessage(ChatMessage* message){
    bool found = false;
    for (Users* user : users){
        if (user->getId() == message->sender->getId()){
            found = true;
            break;
        }
    }
    if (found == false){
        cout << message->sender->getName() << " is not in Dogorithm chat room. Message not saved." << endl;
        return;
    }
    if (!message) return;
    // Make the chatroom own its own copy (deep copy)
    ChatMessage* copy = new ChatMessage(*message);
    chatHistory.push_back(copy);
}
void Dogorithm::removeUser(Users* user){
    std::vector<Users*> newList;
    for (Users* u : users) {
        if (u->getId() != user->getId()) newList.push_back(u);
    }
    users = std::move(newList);
    std::cout << user->getName() << " left Dogorithm" << std::endl;
}
CHIterator* Dogorithm::createIterator() {
    return new VectorCHIterator(chatHistory);
}



