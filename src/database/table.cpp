#include "table.h"

const char *ROBOT_TABLE_SQL = "CREATE TABLE IF NOT EXISTS [robot] ("
                              "[id] INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "[product_number] TEXT NOT NULL,"
                              "[mac_address] TEXT NOT NULL,"
                              "[active] INTEGER NOT NULL,"
                              "[ip] TEXT NOT NULL,"
                              "[updated_date] DATETIME,"
                              "[created_date] DATETIME NOT NULL);";
 
const char *MISSION_TABLE_SQL = "CREATE TABLE IF NOT EXISTS [mission] ("
                                "[id] INTEGER PRIMARY KEY AUTOINCREMENT,"
                                "[robot_id] INTEGER NOT NULL,"
                                "[user_code] TEXT NOT NULL,"
                                "[path] TEXT NOT NULL,"
                                "[on] INTEGER NOT NULL,"
                                "[completed] INTEGER NOT NULL,"
                                "[created_date] DATETIME NOT NULL,"
                                "FOREIGN KEY(robot_id) REFERENCES [robot](id));";

const char *STATUS_TABLE_SQL = "CREATE TABLE IF NOT EXISTS [status] ("
                               "[id] INTEGER PRIMARY KEY AUTOINCREMENT,"
                               "[robot_id] INTEGER NOT NULL,"
                               "[load_weight] DECIMAL NOT NULL,"
                               "[speed] INTEGER NOT NULL,"
                               "[tempature] DECIMAL NOT NULL,"
                               "[battery] INTEGER NOT NULL,"
                               "[created_date] DATETIME NOT NULL,"
                                "FOREIGN KEY(robot_id) REFERENCES [robot](id));";

const char *MISSION_INFO_TABLE_SQL = "CREATE TABLE IF NOT EXISTS [mission_info] ("
                                     "[id] INTEGER PRIMARY KEY AUTOINCREMENT,"
                                     "[mission_id] INTEGER NOT NULL,"
                                     "[status_id] INTEGER NOT NULL,"
                                     "[x] INTEGER NOT NULL,"
                                     "[y] INTEGER NOT NULL,"
                                     "[load] INTEGER NOT NULL,"
                                     "[area_code] TEXT NOT NULL,"
                                     "[event] INTEGER NOT NULL,"
                                     "[distance_travaled] DECIMAL NOT NULL,"
                                     "[created_date] DATETIME NOT NULL,"
                                     "FOREIGN KEY(status_id) REFERENCES [status](id),"
                                     "FOREIGN KEY(mission_id) REFERENCES [mission](id));";
