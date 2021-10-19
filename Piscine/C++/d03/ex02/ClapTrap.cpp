#include "ClapTrap.h"
#include <iostream>

/* Constructors & Destructors */
ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(str_t const& name) : _name{ name }
{
    say("Wub wub! I'm model " + _model);
}

ClapTrap::~ClapTrap()
{
    say("Blip!");
}

/* Copy & Assignment */
ClapTrap::ClapTrap(ClapTrap const& src)
{
    *this = src;
    _name = src._name + "_copy";
    say("Shoot him... he's the real one...");
}

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs)
{
    if (this == &rhs) return *this;
    _maxHP = rhs._maxHP;
    _maxEP = rhs._maxEP;
    _hp = rhs._hp;
    _ep = rhs._ep;
    _lv = rhs._lv;
    _model = rhs._model;
    _name = rhs._name;
    _meleeDmg = rhs._meleeDmg;
    _rangedDmg = rhs._rangedDmg;
    _armor = rhs._armor;
    say("Humans and Robots are equals!");
    return *this;
}

/* Getters & Setters */
str_t const& ClapTrap::get_name() const { return _name; }
str_t const& ClapTrap::get_model() const { return _model; }

/* Member functions */
unsigned int ClapTrap::rangedAttack(str_t const& target)
{
    std::cout << "\t" << _model << " " << _name << " attacks "
              << target << " at range, causing "
              << _rangedDmg << " points of damage !\n";
    return _rangedDmg;
}

unsigned int ClapTrap::meleeAttack(str_t const& target)
{
    std::cout << "\t" << _model << " " << _name << " attacks "
              << target << " at melee range, causing "
              << _meleeDmg << " points of damage !\n";
    return _meleeDmg;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hp && amount > _armor) {
        amount -= _armor;
        _hp -= (amount > _hp ? _hp : amount);
        std::cout << "\t" << _model << " " << _name << " took "
                  << amount << " points of damage !\n";
        say("No fair! I wasn't ready.");
    }
    else if (amount && amount < _armor) {
        say("Can't touch this!");
        std::cout << "\t" << _model << " " << _name
                  << " absorbed all damage !\n";
    }
    if (!_hp){
        say("Argh arghargh death gurgle gurglegurgle urgh... death.");
        std::cout << "\t" << _model << " " << _name
                  << " will be remembered.\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hp < _maxHP) {
        _hp = ((_hp + amount > _maxHP) ? _maxHP : _hp + amount) ;
        say("Sweet life juice!");
        std::cout << "\t" << _model << " " << _name << " recovered "
                  << amount << " hit points !\n";
    }
    if (_hp == _maxHP) {
        say("Wheeeee!");
        std::cout << "\t" << _model << " " << _name
                  << "'s hit points are at MAX.\n";
    }
}

void ClapTrap::reduceEnergy(unsigned int amount)
{
    if (_ep < amount) {
        say("Now, I'm exhausted.");
        std::cout << "\t" << _model << " " << _name
                  << "'s energy points are low.\n";
    }
    else
        _ep -= amount;
}

void ClapTrap::say(str_t const& msg)
{
    std::cout << "<" << _name << ">: " << msg << "\n";
}

void ClapTrap::status()
{
    std::cout << "\tLv." << _lv << " "
              << "HP: " << _hp << "(" << _maxHP << ") "
              << "EP: " << _ep << "(" << _maxEP << ") "
              << "mATK: " << _meleeDmg << " "
              << "rATK: " << _rangedDmg << " "
              << "DEF: " << _armor << "\n";
}