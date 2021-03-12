

#ifndef SESSION_H
#define SESSION_H

using namespace std;

class Session{
	
	string id;
	string time;
	string vanue;
	string lecturer;
	
	public:
	
	/**
	constructs a new session without assigning data
	*/
	Session();
	
	/**
    constructs a new session with assigning values 

		@param data that describes new session
	*/
	Session(string id, string time, string vanue, string lecturer);
	
	/**
    returns session's ID to be used in other operations

		@return returns session's ID
	*/
	string getId();
	
	/**
    returns session's time to be used in other operations

		@return returns session's time
	*/
	string getTime();
	
	/**
    returns session's vanue to be used in other operations

		@return returns session's vanue
	*/
	string getVanue();
	
	/**
    sets new session's ID or edits current session's ID

		@param the new session's ID
	*/
	void setId(string id);
	
	/**
    sets new session's time or edits current session's time

		@param the new session's time
	*/
	void setTime(string time);
	
	/**
    sets new session's vanue or edits current session's vanue

		@param the new session's vanue
	*/
	void setVanue(string vanue);
	
	/**
    returns academician who teaches this session to be used in other operations

		@return returns academician ID
	*/
	string getLecturer();
};

#include "Session.cpp"
#endif