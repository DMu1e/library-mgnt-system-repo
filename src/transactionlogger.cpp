#include "../Include/TransactionLogger.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <ctime>//getting current time
#include <iomanip>//for put_time
#include <sstream>//for string stream
#include <chrono>//getting current time

using namespace std;

TransactionLogger::TransactionLogger(const string &path) : logfilePath(path)
{
    // Ensure directory exists before opening the file
    filesystem::create_directories("Logs");

    logfile.open(logfilePath, std::ios::app);
    if (!logfile.is_open())
    {
        throw std::runtime_error("Log file not open: " + logfilePath);
    }
}

TransactionLogger::~TransactionLogger()
{
    if (logfile.is_open())
    {
        logfile.close();
    }
}

void TransactionLogger::logTransaction(const std::string &memberID, const std::string &isbn, const std::string &action)
{
    if (logfile.is_open())
    {
        logfile << get_current_time() << " " << memberID << " " << action << " " << isbn << std::endl;
    }
}

void TransactionLogger::displayLogs()
{
    ifstream infile(logfilePath);
    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            cout << line << endl;
        }
        infile.close();
    }
    else
    {
        cerr << "Error opening log file for reading" << endl;
    }
}

string TransactionLogger::get_current_time()
{
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm local_tm = *localtime(&now_time);
    stringstream ss;
    ss << put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}
