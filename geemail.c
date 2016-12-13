#include <stdio.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
int insert_data(char *username, char *salt, char *password)
{
    if open_db()!=0
    {
        open_db;
    }
    sqlite3_stmt*stmt=NULL;
    // char *sql="insert into USERS(username, password)values(qxzhang, qwer1234)";
    
    // char *sql="insert into USERS(username, password)values( \'"+username+  "" + ""
    
    int re=sqlite3_prepare_v2(db,sql,strlen(sql), &stmt, NULL);
    if(rc!=SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        if(stmt)
        {
            sqlite3_finalize(stmt);
        }
        sqlite3_close(db);
        return 1;
    }
    
int main()
{
    sqlite3* db;
    char *zErrMsg = 0;
    int rc;
    
    rc = sqlite3_open("mail.db", &db);
    if( rc ){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    };
    
    char* sql = "CREATE TABLE USERS( ID INT PRIMARY KEY, NAME  TEXT );";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
      fprintf(stdout, "Table created successfully\n");
    }    
    sqlite3_close(db);
    return 0;
    insert_data();
    
};