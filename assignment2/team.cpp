/* Citation and Sources
Student: Anastasiya Zozulyuk
Student number: 139,230,247
Email: azozulyuk@myseneca.ca
Date completed : fri, Oct 16th
-----------------------------------------------------------
I declare that this submission is the result of my own work
and I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
-------
*/
#include <iostream>
#include <utility>
#include "team.h"

namespace seneca {

    Team::Team() {
        m_names = "";
        m_mem = nullptr;
        m_count = 0;
    }

    Team::Team(const char* name) {
        m_names = name;
        m_mem = nullptr;
        m_count = 0;
    }

    Team::Team(const Team& other) : Team() {
        *this = other;
    }

    Team& Team::operator=(const Team& other) {
        if (this != &other) {
            for (size_t i = 0; i < m_count; i++) {
                delete m_mem[i];
            }
            delete[] m_mem;

            m_names = other.m_names;
            m_count = other.m_count;
            m_mem = nullptr;

            if (m_count > 0) {
                m_mem = new Character * [m_count];

                for (size_t i = 0; i < m_count; i++) {
                    m_mem[i] = other.m_mem[i]->clone();
                }
            }
        }
        return *this;
    }

    Team::Team(Team&& other) : Team() {
        *this = std::move(other);
    }

    Team& Team::operator=(Team&& other) {
        if (this != &other) {
            for (size_t i = 0; i < m_count; i++) {
                delete m_mem[i];
            }
            delete[] m_mem;

            m_names = std::move(other.m_names);
            m_mem = other.m_mem;
            m_count = other.m_count;

            other.m_mem = nullptr;
            other.m_count = 0;
            other.m_names = "";
        }
        return *this;
    }

    Team::~Team() {
        for (size_t i = 0; i < m_count; i++) {
            delete m_mem[i];
        }
        delete[] m_mem;
    }

    void Team::addMember(const Character* c) {
        for (size_t i = 0; i < m_count; i++) {
            if (m_mem[i]->getName() == c->getName()) {
                return;
            }
        }

        Character** temp = new Character * [m_count + 1];

        for (size_t i = 0; i < m_count; i++) {
            temp[i] = m_mem[i];
        }

        temp[m_count] = c->clone();

        delete[] m_mem;
        m_mem = temp;
        m_count++;
    }

    void Team::removeMember(const std::string& c) {
        for (size_t i = 0; i < m_count; i++) {
            if (m_mem[i]->getName() == c) {
                delete m_mem[i];

                for (size_t j = i; j < m_count - 1; j++) {
                    m_mem[j] = m_mem[j + 1];
                }

                m_count--;
                return;
            }
        }
    }

    Character* Team::operator[](size_t idx) const {
        if (idx >= m_count) {
            return nullptr;
        }
        return m_mem[idx];
    }

    void Team::showMembers() const {
        if (m_names.empty()) {
            std::cout << "No team." << std::endl;
            return;
        }

        std::cout << "[Team] " << m_names << std::endl;

        for (size_t i = 0; i < m_count; i++) {
            std::cout << "    " << i + 1 << ": "
                << *m_mem[i] << std::endl;
        }
    }

}
