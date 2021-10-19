#include "Human.h"
#include <iostream>

void Human::meleeAttack(std::string const& target)
{
    std::cout << "You punched " << target << "\n";
}

void Human::rangedAttack(std::string const& target)
{
    std::cout << "You threw poo at " << target << "\n";
}

void Human::intimidatingShout(std::string const& target)
{
    std::cout << "You shouted at " << target << "\n";
}

void Human::action(std::string const& action_name, std::string const& target)
{
    using Human_mfn = void(Human::*)(std::string const&);
    typedef struct s_action {
        std::string const& name;
        Human_mfn          mfn_p;
    }              t_action;
    
    static t_action actions[]{
        {"melee", &Human::meleeAttack},
        {"ranged", &Human::rangedAttack},
        {"shout", &Human::intimidatingShout}
    };
    for (auto action : actions) {
        if (action.name == action_name) {
            (this->*action.mfn_p)(target);
            //((*this).*action.mfn_p)(target);
            //CALL_MBR_FN(*this, action.mfn_p)(target);
            break;
        }
    }
}