#include <stdio.h>
#include <gcrypt.h>
#include<iostream>
#include <cstdlib>
#include"sqlite3.h"
#include<string>
#include <functional>
using namespace std;
bool b;

static int callback(void *data, int argc, char **argv, char **azColName){       // put the select record
   int i;
   int a=0;
   fprintf(stderr, "%s: ", (const char*)data);
   if (argc==0){
       b=false;
   }
   for(i=0;i<argc; i++){
       printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
       size_t queryLength = strlen(argv[i]) ;
       char * queryBuffer = (char*) malloc(queryLength+1);
       strncpy(queryBuffer, argv[i], queryLength);
       char * check;

      
       check = (char *)data;
       for (int index = 0; index<64; index++){
             printf("%c",check[index]);
             
             if(check[index]==queryBuffer[index]){
                 a++;
             }
       if(a==64){
       b=true;
       }else{
       b=false;
       }
       }
       printf("\n");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[])
{
   
/*    if(rc!=SQLITE_OK)
    {
        cout<<"Cannot open database: "<<sqlite3_errmsg(db)<<endl;
        return 0;
    }
    else 
    {
        cout<<"Open database successfully"<<endl;
    }
  */  
    
     string username;
     string password;
        cout<<"please enter your username: ";
      getline (cin,username);
        cout<<"please enter your password: ";
      getline (cin,password);

      hash<string> str_hash;
        cout <<"hash of password: " <<str_hash(password)<< endl;
      // convert string to const char*
   // 	const char* const_username = username.c_str();
    //	const char* conv_password = password.c_str();
    	const char* data = password.c_str();
    	 sqlite3* db;
    int rc=sqlite3_open("mail.db",&db);
    char *errmsg=(char*)malloc(sizeof(char)) ;
        if( rc ){
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
            exit(0);
            }
            else{
            fprintf(stderr, "Opened database successfully\n");
        }

   /* Create SQL statement */                                                    //write query
        string sqlstr="";
        sqlstr += "select passwd from user where username='";
        sqlstr +=argv[1];
        sqlstr += "'";
    	char *sql = const_cast<char*>(sqlstr.c_str());
        rc = sqlite3_exec(db, sql, callback, (void*)data,&errmsg); 
     if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", errmsg);
      sqlite3_free(errmsg);
    }else{
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);
    	      printf(b ? "true" : "false");
   if (b==1){
       return true;
   }else{
       return false;
   }
}