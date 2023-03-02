#include "Employee.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

namespace sdds {
    // Overloaded Constructor that loads data in the object
    Employee::Employee(std::istream& is) {
        std::string data {};
        std::getline(is, data);

        size_t startIndex {0};
        size_t endIndex = data.find(',');

        std::string m_tag {};

        // Getting the tag
        m_tag = data.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = data.find(',', startIndex);
        m_tag.erase(0, m_tag.find_first_not_of(" \t\r\n"));
        m_tag.erase(m_tag.find_last_not_of(" \t\r\n") + 1);

        if (m_tag == "e" || m_tag == "E") {
            // Getting the name and storing it
            m_name = data.substr(startIndex, (endIndex - startIndex));
            startIndex = endIndex + 1;
            endIndex = data.find(',', startIndex);
            // Erasing trailing and leading white spaces
            m_name.erase(0, m_name.find_first_not_of(" \t\r\n"));
            m_name.erase(m_name.find_last_not_of(" \t\r\n") + 1);

            // Getting the age and storing it
            m_age = data.substr(startIndex, (endIndex - startIndex));
            startIndex = endIndex + 1;
            endIndex = data.find(',', startIndex);
            m_age.erase(0, m_age.find_first_not_of(" \t\r\n"));
            m_age.erase(m_age.find_last_not_of(" \t\r\n") + 1);
            // Validating the age
            size_t age {};
            try {
                age = std::stoi(m_age);
            } catch (const std::invalid_argument& e) {
                throw std::invalid_argument("++Invalid record!");
            }

            // Getting the id and storing it
            m_id = data.substr(startIndex, (endIndex - startIndex));
            m_id.erase(0, m_id.find_first_not_of(" \t\r\n"));
            m_id.erase(m_id.find_last_not_of(" \t\r\n") + 1);
            // Validating the employee id
            if (tolower(m_id[0]) != 'e') {
                throw std::invalid_argument("++Invalid record!");
            }
        }
    }

    // A query that returns the string Employee
    std::string Employee::status() const {
        return "Employee";
    }

    // A query that returns the name of the employee
    std::string Employee::name() const {
        return m_name;
    }

    // A query that returns the id of the employee
    std::string Employee::id() const {
        return m_id;
    }

    // A query that returns the age of the employee
    std::string Employee::age() const {
        return m_age;
    }

    // A query that inserts in the first parameter the content of the employee object in the format
    void Employee::display(std::ostream& out) const {
        out << std::left;
        out << "| " << std::setw(10) << "EMPLOYEE" << " | ";
        out << std::setw(10) << m_id << " | ";
        out << std::setw(20) << m_name << " | ";
        out << std::setw(3) << m_age << " |";
    }
}