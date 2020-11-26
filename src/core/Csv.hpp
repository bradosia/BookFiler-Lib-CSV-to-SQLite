/*
 * @name BookFiler Library - CSV to SQLite
 * @author Branden Lee
 * @version 1.00
 * @license MIT
 * @brief CSV to SQLite
 */

#ifndef BOOKFILER_LIBRARY_SORT_FILTER_TREE_WIDGET_TREE_H
#define BOOKFILER_LIBRARY_SORT_FILTER_TREE_WIDGET_TREE_H

// config
#include "config.hpp"

// C++17
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>

/* boost 1.72.0
 * License: Boost Software License (similar to BSD and MIT)
 */
#include <boost/system/error_code.hpp>

/* sqlite3 3.33.0
 * License: PublicDomain
 */
#include <sqlite3.h>

/*
 * bookfiler - sqlite
 */
namespace bookfiler {
namespace sqlite {

class Csv {
private:
  std::shared_ptr<sqlite3> database;
  std::string tableName;

public:
  Csv();
  ~Csv();

  /* Import and conversion function for the CSV file
   * @param filePath csv file path
   * @param ec boost error code
   * @return 0 on success, else error code
   */
  int import(std::string filePath, boost::system::error_code ec);

  /* Sets the database to use for the view widget.
   * @param database mysqlite3 database that will be imported into
   * @param tableName the new table to create and add the CSv into
   * @return 0 on success, else error code
   */
  int setDatabase(std::shared_ptr<sqlite3> database, std::string tableName);
};

} // namespace sqlite
} // namespace bookfiler

#endif
// end BOOKFILER_LIBRARY_SORT_FILTER_TREE_WIDGET_TREE_H
