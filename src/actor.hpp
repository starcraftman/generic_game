#ifndef _ACTOR_HPP_
#define _ACTOR_HPP_

/********************* Header Files ***********************/
#include <exception>
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <random>

/******************* Constants/Macros *********************/


/******************* Type Definitions *********************/


/************** Class & Func Declarations *****************/
class Actor {
 public:
    Actor(const std::string &name_, int health_, int damage_) :
        name(name_), health(health_), damage(damage_) {};
    Actor() :
        name("Default"), health(20), damage(5) {};
    Actor(const Actor &other) = default;
    // virtual ~Actor ();

    std::string & called() { return this->name; }
    int life_remains() { return this->health; }
    void attack(Actor &other);
 private:
    std::string name;
    int health;
    int damage;
};

void Actor::attack(Actor &other) {
    other.health -= this->damage;
}

#endif /* _ACTOR_HPP_ */
