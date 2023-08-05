// Understanding the Canonical Form :
// Warlock()  -> makes a new Warlock toy(obj) from scratch
// Warlock(Warlock const &copy) -> We can make a new Warlock toy(obj) by copying an existing one using this
// Warlock &operator=(Warlock const &copy) -> lets you change one of your Warlock toys(objs) to be exactly like another one
//

#ifndef WARLOCK_H
# define WARLOCK_H

#include <iostream>


class Warlock
{
  private :
    std::string name;
    std::string title;

    Warlock();
    Warlock(Warlock const &copy);
    Warlock &operator=(Warlock const &copy);

  public:
    Warlock(std::string const &name, std::string const &title);
    ~Warlock();

    std::string const &getName() const;
    std::string const &getTitle() const;

    void setTitle(std::string const &title);
    void introduce() const;

};

#endif
