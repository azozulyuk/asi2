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
#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H

#include <iostream>
#include "character.h"


namespace seneca {

    template <typename T>
          class CharacterTpl : public Character {
           int m_healthMax;
             T m_health;


    public:
        CharacterTpl(const char* name, int healthMax)
            : Character(name) {
            m_healthMax = healthMax;
            m_health = healthMax;
        }


        void takeDamage(int dmg) override {
            m_health -= dmg;

            if (getHealth() <= 0) {
                m_health = 0;
                std::cout << getName() << " has been defeated!" << std::endl;
            }
            else {
                std::cout << getName() << " took " << dmg
                    << " damage, " << getHealth()
                    << " health remaining." << std::endl;
            }
        }
             int getHealth() const override {
            return static_cast<int>(m_health);
        }

            int getHealthMax() const override {
            return m_healthMax;
        }

        void setHealth(int health) override {
            m_health = health;
        }

               void setHealthMax(int health) override {
            m_healthMax = health;
            m_health = health;
        }
    };

}

#endif
