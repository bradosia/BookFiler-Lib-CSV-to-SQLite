/*
 * @name BookFiler Library - CSV to SQLite
 * @author Branden Lee
 * @version 1.00
 * @license MIT
 * @brief CSV to SQLite
 */

/*
 * piwebapi-ucdavis 1.0
 */
#include "Csv.hpp"

/*
 * bookfiler - sqlite
 */
namespace bookfiler {
namespace sqlite {

Csv::Csv(){};
Csv::~Csv(){};

int Csv::import(std::string filePath, boost::system::error_code ec) {
  // TODO
  return 0;
}

int Csv::setDatabase(std::shared_ptr<sqlite3> database_,
                     std::string tableName_) {
  database = database_;
  tableName = tableName_;
  return 0;
}

int Csv::headers(bool hasHeaders_) {
  hasHeaders = hasHeaders_;
  return 0;
}

int setHeaders(std::vector<std::string> headerList) { return 0; }

} // namespace sqlite
} // namespace bookfiler
