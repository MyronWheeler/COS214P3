#ifndef CHATROOM_H
#define CHATROOM_H
#include <string>
#include <vector>
using namespace std;
class Users;
class VectorCHIterator;
class ChatRoom {
	public:
		struct ChatMessage {
			long timestamp;
			string message;
			Users* sender;
		};
		ChatRoom();
		virtual ~ChatRoom();

		virtual void registerUser(Users* User) = 0;

		virtual void sendMessage(ChatMessage message, Users* fromUser) = 0;

		virtual void saveMessage(string message, Users* fromUser) = 0;

		virtual void removeUser(Users* user) = 0;
		VectorCHIterator* createIterator() ;

protected:
	
	vector<Users*> users;
	vector<ChatMessage> chatHistory;


};

#endif
