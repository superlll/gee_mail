#include <stdio.h>
#include <gcrypt.h>
#include<iostream>
#include <cstdlib>
#include"sqlite3.h"
#include<string>
#include <functional>
using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
int main()
{
    sqlite3* db;
    int rc=sqlite3_open("mail.db",&db);
    if(rc!=SQLITE_OK)
    {
        cout<<"Cannot open database: "<<sqlite3_errmsg(db)<<endl;
        return 0;
    }
    else 
    {
        cout<<"Open database successfully"<<endl;
    }
    
    char*errmsg;
    //rc=sqlite3_exec(db,"create table mail(username varchar(100) primary key,password varchar(100));",NULL,NULL,&errmsg);
    //if (rc!=SQLITE_OK)
    //{
    //    sqlite3_close(db);
    //    cout<<errmsg;
    //    sqlite3_free(errmsg);
    //    return 0;
    //}
    
     std::string username;
     std::string password;
    
        cout<<"please enter your username: ";
      getline (std::cin,username);
        cout<<"please enter your password: ";
      getline (std::cin,password);
      //      cout << username << password<< endl;

      std::hash<std::string> str_hash;
        cout <<"hash of password: " <<str_hash(password)<< endl;
      
      // convert string to const char*
    	const char* const_username = username.c_str();
    	const char* conv_password = password.c_str();
    
    	//prepare the statement
    	sqlite3_stmt *stmt;
    	sqlite3_prepare_v2(db, "insert into mail (username, password) values (?1, ?2);", -1, &stmt, NULL);
    	sqlite3_bind_text(stmt, 1, const_username, -1, SQLITE_STATIC);
    	sqlite3_bind_text(stmt, 2, conv_password, -1, SQLITE_STATIC);
    	rc = sqlite3_step(stmt); //executing the statement
    	if (rc != SQLITE_DONE ) {
    		fprintf(stderr, "SQL error: %s\n", errmsg);
    		sqlite3_free(errmsg);
    	} else {
    		fprintf(stdout, "create user successfully\n");
    	}
    	sqlite3_finalize(stmt);  
    return 0;
}