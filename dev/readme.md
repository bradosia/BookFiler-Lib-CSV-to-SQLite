# Development Summary

I need a small C++ library created for a Windows desktop application. The Libraries used are Boost and sqlite3. I need a converter from any arbitrary .csv file to a `sqlite3` database table.

I already wrote the header file for how the library should be used [/src/core/Csv.hpp](https://github.com/bradosia/BookFiler-Lib-CSV-to-SQLite/blob/master/src/core/Csv.hpp). You must finish implementing the widget using the source files provided in this repository. The example program is used to test the widget. [/src_example/example00/main.cpp](https://github.com/bradosia/BookFiler-Lib-CSV-to-SQLite/blob/master/src_example/example00/main.cpp).

To begin development, you should fork this repository and begin implementing the source files [/src/core/](https://github.com/bradosia/BookFiler-Lib-CSV-to-SQLite/tree/master/src/core). Make a pull request or zip up your forked repository and send it to me when delivering work.

## Compiler and compatability

Program must compile on Windows and Linux. For Windows, use MinGW for compiling. For Linux use GCC. Use cmake as the build scipt. Personally, the IDE I use is QT Creator, but any should work as long as you can build with cmake.

# Usage Instructions

Connect to your database:
```cpp
sqlite3 *dbPtr = nullptr;
sqlite3_open("myDatabase.db", &dbPtr);
// Using shared pointers when possible
std::shared_ptr<sqlite3> database(nullptr);
database.reset(dbPtr, sqlite3_close);
```

Create the importer, set the database, then run the import on a csv file
```cpp
std::shared_ptr<bookfiler::sqlite::Csv> csvImporter =
      std::make_shared<bookfiler::sqlite::Csv>();
csvImporter->setDatabase(database, "testTable");
boost::system::error_code ec;
csvImporter->import(CsvFileName, ec);
```

## Requirements
* Use as little memory as possible. Don't load the whole file into memory, then start parsing. You should stream the csv data and parse.
* **Low memory consuption** - C++ iostreams are used to avoid memory warnings since datasets may be fairly large
* **Multiple line endings support** - both Windows ( CR LF ) and Unix (LF ) line endings are processed correctly
* **SQL schema validation** - CSV column names are parsed and user specified types are assigned to columns. In case of column count or name mismatch an error is produced
* **Time performance optimizations** - file IO (FS bound) and parsing operations (CPU bound) are performed on multiple threads and use the **producer-consumer** model.
* **Non standard comments** - the CSV content may be preceeded by some.
* Create a monitor object that is readable by another thread to monitor the bytes read, total bytes, lines inserted, and total lines.

## References

Here is an example of a csv to sqlite importer:

https://github.com/sqlitebrowser/sqlitebrowser/blob/master/src/ImportCsvDialog.cpp

This code may help you get started.

## Coding Standards
Always use the standard library when possible. Use `std::shared_ptr` and `std::unique_ptr` instead of raw pointers whenever possible. use `boost` if some method does not exist in standard library.

* Use camel case
* Use C++17 best coding practices
* Use the standard library when possible

## Deliverables

* Clean and commented code that follows the general design already provided and discussed here.
* Reuse the interface and document changes to the interface if needed.
* Make the example here work. You shouldn't need to make modifications. [/src_example/example00/main.cpp](https://github.com/bradosia/BookFiler-Lib-CSV-to-SQLite/blob/master/src_example/example00/main.cpp).
* Must be able to handle large 1gb csv files

