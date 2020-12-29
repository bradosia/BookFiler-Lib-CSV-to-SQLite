/*
 * @name BookFiler Library - Sort Filter Tree Widget
 * @author Branden Lee
 * @version 1.00
 * @license MIT
 * @brief Super fast tree sorting and filtering tree widget.
 */

// C++
#include <ctime>
#include <fstream>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>

/* sqlite3 3.33.0
 * License: PublicDomain
 */
#include <sqlite3.h>

// Bookfiler Libraries
#include <BookFiler-Lib-CSV-to-SQLite/Interface.hpp>

std::string gen_random(const int len);
std::string createCsvFile();

std::string testName = "Sort Filter Tree Widget Example";

int main(int argc, char *argv[]) {
  char *zErrMsg = 0;

  std::cout << testName << " BEGIN" << std::endl;

  // create importer
  std::shared_ptr<bookfiler::sqlite::Csv> csvImporter =
      std::make_shared<bookfiler::sqlite::Csv>();

  // create a test database
  sqlite3 *dbPtr = nullptr;
  int rc = sqlite3_open("test.sqlite", &dbPtr);
  if (rc) {
    std::cout << "sqlite3_open ERROR:\n" << sqlite3_errmsg(dbPtr) << std::endl;
    return -1;
  }

  std::shared_ptr<sqlite3> database(nullptr);
  database.reset(dbPtr, sqlite3_close);
  csvImporter->setDatabase(database, "testTable");

  std::string CsvFileName = createCsvFile();
  boost::system::error_code ec;
  csvImporter->import(CsvFileName, ec);
  if (ec) {
    std::cout << ec.message() << std::endl;
    return -2;
  }

  std::cout << testName << " END" << std::endl;
  return 0;
}

std::string gen_random(const int len) {
  std::string tmp_s;
  static const char alphanum[] = "0123456789"
                                 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "abcdefghijklmnopqrstuvwxyz";
  tmp_s.reserve(len);
  for (int i = 0; i < len; ++i)
    tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
  return tmp_s;
}

std::string createCsvFile() {
  std::ofstream myfile;
  std::string fileName = "example.csv";
  myfile.open(fileName);
  for (int i = 0; i < 2000000; i++) {
    for (int j = 0; j < 14; j++) {
      myfile << gen_random(32);
      if (j < 9) {
        myfile << ", ";
      }
    }
    myfile << "\n";
  }
  myfile.close();
  return fileName;
}
