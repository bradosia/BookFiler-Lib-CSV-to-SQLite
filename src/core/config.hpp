/*
 * @name BookFiler Library - CSV to SQLite
 * @author Branden Lee
 * @version 1.00
 * @license MIT
 * @brief CSV to SQLite
 */

#ifndef BOOKFILER_LIBRARY_CSV_TO_SQLITE_CONFIG_H
#define BOOKFILER_LIBRARY_CSV_TO_SQLITE_CONFIG_H

#define BOOKFILER_LIBRARY_CSV_TO_SQLITE_DEBUG 1

// C++
#include <string>

/* boost 1.72.0
 * License: Boost Software License (similar to BSD and MIT)
 */
#define BOOST_ALLOW_DEPRECATED_HEADERS

/*
 * bookfiler - sqlite
 */
namespace bookfiler {
namespace sqlite {

static std::string moduleName = "BookFiler sqlite";
static std::string moduleCode = "bookfiler::sqlite";

} // namespace sqlite
} // namespace bookfiler

#endif // BOOKFILER_MODULE_SSH_CONFIG_H
