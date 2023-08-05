//
// Here , & -> Reference Variable -> Returning a reference is more efficient(a pointer to obj)
// getName(), getTitle() -> ref to str object
//

#include "Warlock.hpp"


Warlock::Warlock(const std::string &name, const std::string &title)
{
  this->name = name;
  this->title = title;
  std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {std::cout << this->name << ": My job here is done!\n"};

std::string const &Warlock::getName() const { return (this->name);}
std::string const &Warlock::getTitle() const {return (this->title);}

void Warlock::setTitle(std::string const &title) {this->title = title;}
void Warlock::introduce() const {std::cout << this->name << ": I am " << this->title << "!\n";}
