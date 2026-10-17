/* Citation and Sources
Student: Anastasiya Zozulyuk
Student number: 139,230,247
Email: azozulyuk@myseneca.ca
Date completed : Thur, Oct 15th
-----------------------------------------------------------
I declare that this submission is the result of my own work
and I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
-------
*/
#include <iostream>
#include <utility>
#include "guild.h"

namespace seneca {

    Guild::Guild() {
        m_names = "";
        m_mem = nullptr;
        m_count = 0;
    }

    Guild::Guild(const char* name) {
        m_names = name;
        m_mem = nullptr;
        m_count = 0;
    }

    Guild::Guild(const Guild& other) : Guild() {
        *this = other;
    }

    Guild& Guild::operator=(const Guild& other) {
        if (this != &other) {
            delete[] m_mem;

            m_names = other.m_names;
            m_count = other.m_count;
            m_mem = nullptr;

            if (m_count > 0) {
                m_mem = new Character * [m_count];

                for (size_t i = 0; i < m_count; i++) {
                    m_mem[i] = other.m_mem[i];
                }
            }
        }
        return *this;
    }

    Guild::Guild(Guild&& other) : Guild() {
        *this = std::move(other);
    }

    Guild& Guild::operator=(Guild&& other) {
        if (this != &other) {
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

    Guild::~Guild() {
        delete[] m_mem;
    }

    void Guild::addMember(Character* c) {
        for (size_t i = 0; i < m_count; i++) {
            if (m_mem[i] == c) {
                return;
            }
        }

        Character** temp = new Character * [m_count + 1];

        for (size_t i = 0; i < m_count; i++) {
            temp[i] = m_mem[i];
        }

        temp[m_count] = c;

        delete[] m_mem;
        m_mem = temp;
        m_count++;

        c->setHealthMax(c->getHealthMax() + 300);
    }

    void Guild::removeMember(const std::string& c) {
        for (size_t i = 0; i < m_count; i++) {
            if (m_mem[i]->getName() == c) {
                m_mem[i]->setHealthMax(m_mem[i]->getHealthMax() - 300);

                for (size_t j = i; j < m_count - 1; j++) {
                    m_mem[j] = m_mem[j + 1];
                }

                m_count--;
                return;
            }
        }
    }

    Character* Guild::operator[](size_t idx) const {
        if (idx >= m_count) {
            return nullptr;
        }

        return m_mem[idx];
    }


    void Guild::showMembers() const {
        if (m_names.empty()) {
            std::cout << "No guild." << std::endl;
            return;
        }

        std::cout << "[Guild] " << m_names << std::endl;

        for (size_t i = 0; i < m_count; i++) {
            std::cout << "    " << i + 1 << ": "
                << *m_mem[i] << std::endl;
        }
    }


}
