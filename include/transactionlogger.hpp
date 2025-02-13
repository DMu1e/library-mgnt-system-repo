#ifndef TRANSACTIONLOGGER_HPP
#define TRANSACTIONLOGGER_HPP

#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

class TransactionLogger
{
private:
    ofstream logfile;
    string logfilePath;
    string get_current_time();

public:
    TransactionLogger(const std::string &path = "Logs/TransactionLogs.txt");
    ~TransactionLogger();
    void logTransaction(const std::string &memberID, const std::string &isbn, const std::string &action);
    void displayLogs();
};

#endif

