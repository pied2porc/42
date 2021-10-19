#include "ScavTrap.h"
#include <iostream>

inline void say(str_t const& name, str_t const& msg)
{
    std::cout << "<" << name << ">: " << msg << "\n";
}

/* Constructors & Destructors */
ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(str_t const& name) : _name{ name }
{
    say(_name, "Hey!");
}

ScavTrap::~ScavTrap()
{
    say(_name, "The robot is dead, long live the robot!");
}

ScavTrap::ScavTrap(ScavTrap const& src) : _name{ src._name + "_copy" }
{
    say(_name, "Shoot him... he's the real one...");
}

/* Operators Overload */
ScavTrap& ScavTrap::operator=(ScavTrap const& rhs)
{
    _hp = rhs._hp;
    _ep = rhs._ep;
    _lv = rhs._lv;
    _name = rhs._name;
    say(_name, "Humans and Robots are equals!");
    return *this;
}

/* Getters & Setters */
str_t const& ScavTrap::get_name() const { return _name; }

/* Member functions */
unsigned int ScavTrap::rangedAttack(str_t const& target)
{
    std::cout << "\tSC4V-TP " << _name << " attacks "
              << target << " at range, causing "
              << _rangedDmg << " points of damage !\n";
        return _rangedDmg;
}

unsigned int ScavTrap::meleeAttack(str_t const& target)
{
    std::cout << "\tSC4V-TP " << _name << " attacks "
              << target << " at melee range, causing "
              << _meleeDmg << " points of damage !\n";
    return _meleeDmg;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (_hp && amount > _armor) {
        amount -= _armor;
        _hp -= (amount > _hp ? _hp : amount);
        say(_name, "Why do I even feel pain?");
        std::cout << "\tSC4V-TP " << _name << " took "
                  << amount << " points of damage !\n";
    }
    else if (amount && amount < _armor) {
        say(_name, "Can't touch this!");
        std::cout << "\tSC4V-TP " << _name << " absorbed all damage !\n";
    }
    if (!_hp){
        say(_name, "For you...I commit...seddoku...");
        std::cout << "\tSC4V-TP " << _name << " will be remembered.\n";
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (_hp < _maxHP) {
        _hp = ((_hp + amount > _maxHP) ? _maxHP : _hp + amount) ;
        say(_name, "Sweet life juice!");
        std::cout << "\tSC4V-TP " << _name << " recovered "
                  << amount << " hit points !\n";
    }
    if (_hp == _maxHP) {
        say(_name, "Wheeeee!");
        std::cout << "\tSC4V-TP " << _name << "'s hit points are at MAX.\n";
    }
}

void ScavTrap::challengeNewcomer(str_t const& target)
{
    static unsigned int constexpr ep{ 25 };
    if (_ep < ep) {
        say(_name, "Now, I'm exhausted.");
        std::cout << "\tSC4V-TP " << _name << "'s energy points are low.\n";
        return;
    }
    _ep -= ep;
    say(_name, "Loading challenge package!");

    static str_t const challenges[]{
        " to take out the garbage!",
        " to go on a date with Kwame!",
        " to hold his breath for 42 secondes!",
        " to peel a banana with his feet!",
        " to eat his nose shit!"
    };
    static int max_atk{ sizeof(challenges) / sizeof(*challenges) };
    static double constexpr fraction{ 1.0 / (RAND_MAX + 1.0) };
    int rnb{ static_cast<int>(std::rand() * fraction * max_atk) };
    std::cout << "\tSC4V-TP " << _name << " challenges "
    << target << challenges[rnb] << "\n";
}