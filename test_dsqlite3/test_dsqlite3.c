#include "test_dsqlite3.h"
#include "sqlite3.h"
#include "stdio.h"
#include "log.h"

int
main()
{
  int result;
  sqlite3* db = NULL;
  result = sqlite3_open("test.db", &db);
  if(SQLITE_OK != result)
  {
      log_error("Create/Open database error!\n");
  }
  log_info("Create/Open test.db success!! \n");
  const char* sqlStr1 = "create table table1(sid integer primary key not null,age string);";

  result = sqlite3_exec(db, sqlStr1, 0, 0, 0);
  if(SQLITE_OK != result)
  {
      log_error("create table table1 error! \n");
      return 0;
  }
  log_info("create table table1 success! \n");
  const char* sqlStr2 = "insert into table1() values(1,'name1');";
  result = sqlite3_exec(db, sqlStr2, 0, 0, 0);
  if(SQLITE_OK != result)
  {
      log_error("insert table table1 error! \n");
      return 0;
  }
  log_info("insert table table1 success! \n");
  sqlite3_close(db);
  return 0;
}