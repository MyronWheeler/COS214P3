#include <iostream>
#include <ctime>
#include "Dogorithm.h"
#include "CtrlCat.h"
#include "Users.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include "VectorCHIterator.h"
#include "Administrator.h"
#include "Sender.h"
#include "UserDecorator.h"
#include "BaseUser.h"

using namespace std;

// Helper to create a ChatMessage
ChatRoom::ChatMessage makeMessage(const std::string& text, Users* sender) {
    ChatRoom::ChatMessage msg;
    msg.message = text;
    msg.sender = sender;
    msg.timestamp = time(nullptr);
    return msg;
}

// Test creating users and chat rooms
void testUserAndRoom() {
    cout << " testUserAndRoom " << endl;
    Users* alice = new BaseUser("Alice",0);
    Users* bob = new BaseUser("Bob",1);
    Dogorithm* dogRoom = new Dogorithm();
    CtrlCat* catRoom = new CtrlCat();

    dogRoom->registerUser(alice);
    dogRoom->registerUser(bob);
    catRoom->registerUser(alice);


    cout << "Created users and registered them to rooms." << endl;

    delete alice;
    delete bob;
    delete dogRoom;
    delete catRoom;
}

// Test sending and receiving messages
void testSendReceive() {
    cout << " testSendReceive " << endl;
    UserDecorator* alice = new Sender(new BaseUser("Alice",0));
    UserDecorator* bob = new Sender(new BaseUser("Bob",1));
    Dogorithm* dogRoom = new Dogorithm();

    dogRoom->registerUser(alice);
    dogRoom->registerUser(bob);
    cout << "Users registered to Dogorithm." << endl;

    alice->send("Hello Bob!", dogRoom);
    bob->send("Hi Alice!", dogRoom);
    alice->executeAll();
    bob->executeAll();

    delete alice;
    delete bob;
    delete dogRoom;
}

// Test if user is not in room and tries to send
void testInvalidSend() {
    cout << " testInvalidSend " << endl;
    UserDecorator* alice = new Sender(new BaseUser("Alice",0));
    UserDecorator* bob = new Sender(new BaseUser("Bob",1));
    Dogorithm* dogRoom = new Dogorithm();   
    dogRoom->registerUser(alice);
    cout << "Alice registered to Dogorithm." << endl;
    bob->send("Hi Alice!", dogRoom);
    bob->executeAll();
    delete alice;
    delete bob;
    delete dogRoom;
}

// Test command queue and execution
void testCommandQueue() {
    cout << " testCommandQueue " << endl;
    UserDecorator* alice = new Sender(new BaseUser("Alice",0));
    UserDecorator* bob = new Sender(new BaseUser("Bob",1));
    Dogorithm* dogRoom = new Dogorithm();

    dogRoom->registerUser(alice);
    dogRoom->registerUser(bob);

    alice->send("Hello Bob!", dogRoom);
    bob->send("Hi Alice!", dogRoom);
    // alice->addCommand(new SendMessageCommand(dogRoom, new ChatRoom::ChatMessage(makeMessage("How are you?", alice))));
    alice->executeAll();
    delete alice;
    delete bob;
    delete dogRoom;
}

// Test chat history iterator
void testIterator() {
    cout << " testIterator " << endl;
    UserDecorator* alice = new Sender(new BaseUser("Alice",0));
    UserDecorator* bob = new Sender(new BaseUser("Bob",1));
    Dogorithm* dogRoom = new Dogorithm();

    dogRoom->registerUser(alice);
    dogRoom->registerUser(bob);

    alice->send("Hello Bob!", dogRoom);
    bob->send("Hi Alice!", dogRoom);
    alice->send("How are you?", dogRoom);
    bob->send("Doing well, thanks!", dogRoom);
    alice->executeAll();
    bob->executeAll();

    CHIterator* it = dogRoom->createIterator();// Should return a VectorCHIterator
    int i = 1;
    while (it->hasNext()) {
        ChatRoom::ChatMessage* msg = it->next();
        cout << "History " << i << ": [" << msg->timestamp << "] "
             << msg->sender->getName() << ": " << msg->message << endl;
        i++;
    }
    delete it;
    delete alice;
    delete bob;
    delete dogRoom;
    
}

// Test removing users
void testSelfRemoveUser() {
    cout << " testRemoveUser " << endl;
    UserDecorator* alice = new Sender(new BaseUser("Alice",0));
    UserDecorator* bob = new Sender(new BaseUser("Bob",1));
    Dogorithm* dogRoom = new Dogorithm();

    dogRoom->registerUser(alice);
    dogRoom->registerUser(bob);

    bob->removeChatRoom(dogRoom);
    alice->send("Are you still there, Bob?", dogRoom);

    delete alice;
    delete bob;
    delete dogRoom;
}
//testing administrator functions
void testAdminFunctions() {
    cout << " testAdminFunctions " << endl;
    Users* charlie = new BaseUser("Charlie",2);
    UserDecorator* admin = new Administrator(new BaseUser("Admin",99));
    Dogorithm* dogRoom = new Dogorithm();

    dogRoom->registerUser(admin);
    dogRoom->registerUser(charlie);

    admin->send("Welcome Charlie!", dogRoom);
    // admin->banUserAccount(charlie, "Violation of rules"); // This is giving issues
    admin->send("Charlie has been banned.", dogRoom);

    delete admin;
    delete charlie;
    delete dogRoom;
}

int main() {
    // testUserAndRoom();
    // testSendReceive();
    // testInvalidSend();
    // testCommandQueue();
    // testIterator();
    testSelfRemoveUser();
    // testAdminFunctions();
    cout << " All tests complete " << endl;
    return 0;
}