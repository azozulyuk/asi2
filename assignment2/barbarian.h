#pragma once

#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

#include <iostream>
#include "characterTpl.h"

namespace seneca {

    template <typename T, typename Ability_t, typename Weapon_t>
    class Barbarian : public CharacterTpl<T> {
        int m_baseDefense;
        int m_baseAttack;
        Ability_t m_ability;
        Weapon_t m_weapon[2];

    public:
        Barbarian(const char* name, int healthMax, int baseAttack,
            int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
            : CharacterTpl<T>(name, healthMax) {
            m_baseAttack = baseAttack;
            m_baseDefense = baseDefense;
            m_weapon[0] = primaryWeapon;
            m_weapon[1] = secondaryWeapon;
        }

        int getAttackAmnt() const override {
            return m_baseAttack +
                static_cast<double>(m_weapon[0]) / 2 +
                static_cast<double>(m_weapon[1]) / 2;
        }

        int getDefenseAmnt() const override {
            return m_baseDefense;
        }

        Character* clone() const override {
            return new Barbarian(*this);
        }

        void attack(Character* enemy) override {
            std::cout << this->getName() << " is attacking "
                << enemy->getName() << "." << std::endl;

            m_ability.useAbility(this);

            int damag = getAttackAmnt();

            m_ability.transformDamageDealt(damag);

            std::cout << "    Barbarian deals " << damag
                << " melee damage!" << std::endl;

            enemy->takeDamage(damag);
        }

        void takeDamage(int dmg) override {
            std::cout << this->getName() << " is attacked for "
                << dmg << " damage." << std::endl;

            std::cout << "    Barbarian has a defense of "
                << getDefenseAmnt()
                << ". Reducing damage received." << std::endl;

            dmg -= getDefenseAmnt();

            if (dmg < 0) {
                dmg = 0;
            }

            m_ability.transformDamageReceived(dmg);

            CharacterTpl<T>::takeDamage(dmg);
        }
    };
}

#endif
