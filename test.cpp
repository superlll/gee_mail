#include<iostream>
#include <cstdlib>
using namespace std;
#include"sqlite3.h"
#include<string>

int static callback(void *NotUsed,int argc,char**argv,char**azColName);
int main()
{
    sqlite3* db;
    int nResult=sqlite3_open("mail.db",&db);
    if(nResult!=SQLITE_OK)
    {
        cout<<"Cannot open database: "<<sqlite3_errmsg(db)<<endl;
        return 0;
    }
    else 
    {
        cout<<"Open database successfully"<<endl;
    }
    
    char*errmsg=0;
    nResult=sqlite3_exec(db,"create table mail(username varchar(100) primary key,password varchar(100));",NULL,NULL,&errmsg);
    if (nResult!=SQLITE_OK)
    {
        sqlite3_close(db);
        cout<<errmsg;
        sqlite3_free(errmsg);
        return 0;
    }
    cout<<"If you have username, please enter Y to sign in.\n If not, press N to register\n";
    char ch;
    cin>>ch;
    if (ch=='N')
    {
        sqlite3_exec(db, "BEGIN;", 0, 0, 0);
        const char* sql = "insert into testinfo values(?,?,?,?)";
        sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, 0);
            sqlite3_reset(stmt);
            sqlite3_bind_int(stmt, 1, i);
            sqlite3_bind_int(stmt, 2, j);
            sqlite3_bind_text(stmt, 3, tmpstr, -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 4, buf, -1, SQLITE_STATIC);
            const char* sql=sqlite3_sql(smt);
            rc=sqlite3_step(stmt);
            if (rc!=SQLITE_DONE)
            {
                fprintf(stderr,"SQLerror: %s\n",errmsg);
                sqlite_free(zErrMsg);
            }
            else
            {
                fprintf(stdout,"open database successfully\n");
        sqlite3_finalize(stmt);
    }
    else
    {
        char *sText1=NULL;
        char *sText2=NULL;
        cout<<"please enter your username: "; 
        cin>>*sText1;
        cout<<"please enter your username: ";
        cin>>*sText2;
        char *strSql=sqlite3_mprintf("select username from mail;",sText1,sText2);
        nResult=sqlite3_exec(db,strSql,NULL,NULL,&errmsg);
        if (nResult != SQLITE_OK)
        {
            sqlite3_close(db);
            cout<<errmsg<<endl;
            sqlite3_free(errmsg);
            return 0;
        }
        sqlite3_close(db);
        return 0;
    }
}
int static callback(void *NotUsed,int argc,char**argv,char**azColName)
{
            string s;
            for(int i=0;i<argc;i++)
            {
                s+=azColName[i];
                s+=":";
                s+=argv[i];
                s+="\n";
                
            }
            cout<<s<<endl;
            return 0;
    
}