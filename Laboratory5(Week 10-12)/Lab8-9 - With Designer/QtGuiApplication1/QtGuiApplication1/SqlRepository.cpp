//#include "SqlRepository.h"
//#include <fstream>
//#include <stdlib.h>
////#include "mysql_connection.h"
////#include <cppconn/driver.h>
////#include <cppconn/exception.h>
////#include <cppconn/resultset.h>
////#include <cppconn/statement.h>
//#include "Utils.h"
//#include <sstream>
//#include <string>
//
//static char *opt_host_name = "host"; /* HOST */
//static char *opt_user_name = "root"; /* USERNAME */
//static char *opt_password = "pass"; /* PASSWORD */
//static unsigned int opt_port_num = 3306; /* PORT */
//static char *opt_socket_name = NULL; /* SOCKET NAME, DO NOT CHANGE */
//static char *opt_db_name = "lab8"; /* DATABASE NAME */
//static unsigned int opt_flags = 0; /* CONNECTION FLAGS, DO NOT CHANGE */
//
//
//void connecToMysql() {
//	/*sql::Driver *driver;
//	sql::Connection *con;
//	sql::Statement *stmt;
//	sql::ResultSet *res;
//	driver = get_driver_instance();*/
//	//con = driver->connect("tcp://127.0.0.1:3306", "root", "Babybuffrooz@%)$2016");
//	//con->setSchema("lab8");
//	//stmt = con->createStatement();
//	//res = stmt->executeQuery("SELECT * FROM tables");
//	//delete res;
//	//delete stmt;
//	//delete con;
//}
//
//
//
//void SqlRepository::repoFromFile()
//{
//	sql::Driver *driver;
//	sql::Connection *con;
//	sql::Statement *stmt;
//	sql::ResultSet  *res;
//	/* Create a connection */
//	driver = get_driver_instance();
//	con = driver->connect("tcp://127.0.0.1:3306", "root", "Babybuffrooz@%)$2016");
//
//	/* Connect to the MySQL so_test database */
//	con->setSchema("lab8");
//	stmt = con->createStatement();
//
//	// Select all columns/rows from example_table
//	res = stmt->executeQuery("SELECT * FROM tutorials");
//
//	//get result set metadata
//	sql::ResultSetMetaData *res_meta = res->getMetaData();
//	int columns = res_meta->getColumnCount();
//
//	//Loop for each row
//	std::string s = "";
//	while (res->next()) {
//		s = "";
//		/* Access column data by index, 1-indexed*/
//		for (int i = 2; i <= columns-1; i++) {
//			s += res->getString(i) + ",";
//		}
//		s += res->getString(columns);
//		std::vector<std::string> tokens = tokenize(s, ',');
//		Tutorial t = TutorialFactory::MakeTutorial(trim(tokens[1]), trim(tokens[0]), trim(tokens[5]), trim(tokens[6]), trim(tokens[2]), trim(tokens[4]), trim(tokens[3]));
//		tutorials->push_back(t);
//	}
//	delete res;
//	delete stmt;
//	delete con;
//}
//
////CSVRepository::~CSVRepository()
////{
////	std::cout << "1";
////	this->repoToFile();
////}
//
//void SqlRepository::repoToFile()
//{
//	sql::Driver *driver;
//	sql::Connection *con;
//	sql::Statement *stmt;
//	sql::Statement *stmt2;
//	sql::ResultSet  *res;
//	/* Create a connection */
//	driver = get_driver_instance();
//	con = driver->connect("tcp://127.0.0.1:3306", "root", "Babybuffrooz@%)$2016");
//	try {
//
//	/* Connect to the MySQL so_test database */
//	con->setSchema("lab8");
//	stmt = con->createStatement();
//	stmt->execute("TRUNCATE TABLE lab8.tutorials;");
//	for (int i = 0; i < tutorials->size(); i++) {
//		std::ostringstream stream;
//		stream << "INSERT INTO `lab8`.`tutorials` (`ID`, `Presenter`, `Title`, `No. likes`, `No. views`, `Source`, `Minutes`, `Seconds`) VALUES ( '" << i << "', '" << (*tutorials)[i].getPresenter() << "', '" << (*tutorials)[i].getTitle() << "', '" << (*tutorials)[i].getNoLikes() << "', '" << (*tutorials)[i].getNoViews() << "', '" << (*tutorials)[i].getSource() << "', '" << (*tutorials)[i].getDuration().getMinutes() << "', '" << (*tutorials)[i].getDuration().getSeconds() << "');";
//		//	std::cout << stream.str();
//		stmt2 = con->createStatement();
//		stmt->execute(stream.str());
//	}
//	}
//	catch (sql::SQLException& e) {
//		std::cout << "# ERR: " << e.what();
//		std::cout << " (MySQL error code: " << e.getErrorCode();
//		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
//	}
//
//}
//
//SqlRepository::SqlRepository(const std::string & source) : IFileRepository(source) {
//	this->repoFromFile();
//}
//
//SqlRepository::~SqlRepository()
//{
//	this->repoToFile();
//}
//
//void SqlRepository::display()
//{
//	
//}
//
