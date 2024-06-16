#include "database_manager.h"

int DatabaseManager::close_database() {
    int rc = sqlite3_close(db);

    if (rc == SQLITE_OK) {
    cout << "[+] Database connection closed." << endl;
    } else {
    cout << "[-] Failed to close database connection." << endl;
    }

    return rc;
}

int DatabaseManager::create_record(const char* table, const char* columns, const char* values) {
    char* sql = sqlite3_mprintf("INSERT INTO %s (%s) VALUES (%s)", table, columns, values);
    int rc = sqlite3_exec(db, sql, nullptr, 0, nullptr);
    sqlite3_free(sql);
    return rc;
}

int DatabaseManager::update_record(const char* table, const char* set_columns_values, const char* where_clause) {
    char* sql = sqlite3_mprintf("UPDATE %s SET %s WHERE %s", table, set_columns_values, where_clause);
    int rc = sqlite3_exec(db, sql, nullptr, 0, nullptr);
    sqlite3_free(sql);
    return rc;
}

int DatabaseManager::read_records(const char* table, char*** results) {
    char* sql = sqlite3_mprintf("SELECT * FROM %s", table);
    int rc = sqlite3_get_table(db, sql, results, nullptr, nullptr, nullptr);
    sqlite3_free(sql);
    return rc;
}

int DatabaseManager::delete_record(const char* table, const char* where_clause) {
    char* sql = sqlite3_mprintf("DELETE FROM %s WHERE %s", table, where_clause);
    int rc = sqlite3_exec(db, sql, nullptr, 0, nullptr);
    sqlite3_free(sql);
    return rc;
}


bool DatabaseManager::create_table(const char* table_name, const char* sql_query) {
    // Creates a table in a SQLite database.

    // Args:
    //  db: The connection object to the SQLite database.
    //  table_name: The name of the table to create.
    //  sql_query: The SQL CREATE TABLE query string.

    // Returns:
    //  True if the table is created successfully, False otherwise.

    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql_query, nullptr, 0, &errMsg);

    if (rc != SQLITE_OK) {
    cerr << "[-] SQL error creating table " << table_name << ": " << errMsg << endl;
    sqlite3_free(errMsg);
    return false;
    }

    cout << "[+] [" << table_name << "] table created successfully." << endl;
    return true;
}
