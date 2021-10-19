#include "FragTrap.h"
#include <iostream>

inline void say(str_t const& name, str_t const& msg)
{
    std::cout << "<" << name << ">: " << msg << "\n";
}

/* Constructors & Destructors */
FragTrap::FragTrap() {}

FragTrap::FragTrap(str_t const& name) : _name{ name }
{
    say(_name, "Hello!");
}

FragTrap::~FragTrap()
{
    say(_name, "I'll die the way I lived: annoying!");
}

FragTrap::FragTrap(FragTrap const& src) : _name{ src._name + "_copy" }
{
    say(_name, "Shoot him... he's the real one...");
}

/* Operators Overload */
FragTrap& FragTrap::operator=(FragTrap const& rhs)
{
    _hp = rhs._hp;
    _ep = rhs._ep;
    _lv = rhs._lv;
    _name = rhs._name;
    say(_name, "Humans and Robots are equals!");
    return *this;
}

/* Getters & Setters */
str_t const& FragTrap::get_name() const { return _name; }

/* Member functions */
unsigned int FragTrap::rangedAttack(str_t const& target)
{
    std::cout << "\tFR4G-TP " << _name << " attacks "
              << target << " at range, causing "
              << _rangedDmg << " points of damage !\n";
    return _rangedDmg;
}

unsigned int FragTrap::meleeAttack(str_t const& target)
{
    std::cout << "\tFR4G-TP " << _name << " attacks "
              << target << " at melee range, causing "
              << _meleeDmg << " points of damage !\n";
    return _meleeDmg;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (_hp && amount > _armor) {
        amount -= _armor;
        _hp -= (amount > _hp ? _hp : amount);
        say(_name, "Why do I even feel pain?");
        std::cout << "\tFR4G-TP " << _name << " took "
                  << amount << " points of damage !\n";
    }
    else if (amount && amount < _armor) {
        say(_name, "Can't touch this!");
        std::cout << "\tFR4G-TP " << _name << " absorbed all damage !\n";
    }
    if (!_hp) {
        say(_name, "For you...I commit...seddoku...");
        std::cout << "\tFR4G-TP " << _name << " will be remembered.\n";
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (_hp < _maxHP) {
        _hp = ((_hp + amount > _maxHP) ? _maxHP : _hp + amount) ;
        say(_name, "Sweet life juice!");
        std::cout << "\tFR4G-TP " << _name << " recovered "
                  << amount << " hit points !\n";
    }
    if (_hp == _maxHP) {
        say(_name, "Wheeeee!");
        std::cout << "\tFR4G-TP " << _name << "'s hit points are at MAX.\n";
    }
}

/* Random attack */
unsigned int FragTrap::vaulthunter_dot_exe(str_t const& target)
{
    static unsigned int constexpr ep{ 25 };
    if (_ep < ep) {
        say(_name, "Now, I'm exhausted.");
        std::cout << "\tFR4G-TP " << _name << "'s energy points are low.\n";
        return 0;
    }
    _ep -= ep;
    say(_name, "Loading combat package!");

    using FragTrap_fn = unsigned int(FragTrap::*)(str_t const&);
    static FragTrap_fn const attacks[]{
        &FragTrap::clapInTheBox,
        &FragTrap::laserInferno,
        &FragTrap::minionTrap,
        &FragTrap::meatUnicycle,
        &FragTrap::funzerker
    };
    static int max_atk{ sizeof(attacks) / sizeof(*attacks) };
    static double constexpr fraction{ 1.0 / (RAND_MAX + 1.0) };
    int rnb{ static_cast<int>(std::rand() * fraction * max_atk) };
    return (this->*attacks[rnb])(target);
}

/* Attacks */
unsigned int FragTrap::clapInTheBox(str_t const& target)
{
    say(_name, "Oh darn, oh boy, oh crap, oh boy, oh darn.");
    return rangedAttack(target);
}

unsigned int FragTrap::laserInferno(str_t const& target)
{
    say(_name, "Everybody, dance time! "
               "Da-da-da-dun-daaa-da-da-da-dun-daaa!");
    return meleeAttack(target);
}

unsigned int FragTrap::minionTrap(str_t const& target)
{
    say(_name, "Ratattattattatta! Powpowpowpow! Powpowpowpow! "
               "Pew-pew, pew-pew-pewpew!");
    return rangedAttack(target);
}

unsigned int FragTrap::meatUnicycle(str_t const& target)
{
    say(_name, "It's the only way to stop the voices!");
    return meleeAttack(target);
}

unsigned int FragTrap::funzerker(str_t const& target)
{
    say(_name, "If I had veins, they'd be popping out right now!");
    return rangedAttack(target);
}