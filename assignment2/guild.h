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
