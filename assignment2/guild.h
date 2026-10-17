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
#pragma once

#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H

#include <string>
#include "character.h"

namespace seneca {

    class Guild {
        std::string m_names;
        Character** m_mem;
        size_t m_count;

    public:
        Guild();
        Guild(const char* name);

        Guild(const Guild& other);
        Guild& operator=(const Guild& other);

        Guild(Guild&& other);
        Guild& operator=(Guild&& other);

        ~Guild();

        void addMember(Character* c);
        void removeMember(const std::string& c);
        Character* operator[](size_t idx) const;
        void showMembers() const;
    };

}

#endif
