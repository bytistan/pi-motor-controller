#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include "table.h"
#include "sqlite3.h"
#include <iostream>

using namespace std;

struct DatabaseManager
{
    
    const char* path = "./resources/database.db";
    sqlite3 *db;
    char *errMsg = 0;

    DatabaseManager() 
    {
        if ( sqlite3_open(path, &db) )
        {
            cerr << "[-] Can't open database:" << sqlite3_errmsg(db) << endl;
            return;
        } 
        else 
        {
            cout << "[+] Database opened successfully." << endl;
        }
        
        if (create_table("robot",ROBOT_TABLE_SQL) && 
            create_table("mission",MISSION_TABLE_SQL) && 
            create_table("status",STATUS_TABLE_SQL) && 
            create_table("mission_info",MISSION_INFO_TABLE_SQL))
        {
            cout << "[+] Tables created successfully." << endl;
        }
        else
        {
            cerr << "[-] Failed to create tables." << endl;
        }
    }
    
    bool create_table(const char* table_name, const char* sql_query);
    int create_record(const char* table, const char* columns,const char* values);
    int read_records(const char* table, char*** results);
    int update_record(const char* table, const char* set_coluns_values, const char* where_clause);
    int delete_record(const char* table, const char* where_clause); 
    int close_database();
};

#endif
