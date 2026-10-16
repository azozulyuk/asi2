#pragma once

#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include <iostream>
#include <string>
#include "character.h"

namespace seneca {

    class Team {
        std::string m_names;
        Character** m_mem;
        size_t m_count;

    public:
        Team();
        Team(const char* name);

        Team(const Team& other);
        Team& operator=(const Team& other);

        Team(Team&& other);
        Team& operator=(Team&& other);

        ~Team();

        void addMember(const Character* c);
        void removeMember(const std::string& c);
        Character* operator[](size_t idx) const;
        void showMembers() const;
    };

}

#endif
