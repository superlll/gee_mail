# geemail
here are some instuctions about the geemail.
this is a secure asynchronous message platform. 
Here is what is do: When loaded prompt the user to sign-in or register.
When a user registers get their username and password.
When a user logs in ask for username and validate password. 
If login fails, it would response the unsuccess 
Once logged in, it can tell you the number of messages you have, 
list the users that have sent them a message. 

myregister.cpp have the function that it can register username and password.

mylogin.cpp can log in the user you just register



how to compile the code:
 g++ -std=c++11 myregister.cpp -lsqlite3 -lgcrypt
 g++ -std=c++11 mylogin.cpp -lsqlite3 -lgcrypt
 ./a.out

## Support & Documentation
