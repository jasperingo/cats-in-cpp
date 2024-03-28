#ifndef CAT_H
#define CAT_H

#include <string>
#include <iostream>

class Cat {
  private:
    std::string name;
    std::string color;
    int numberOfLegs;

  public:
    Cat(std::string name, std::string color, int numberOfLegs);

    std::string getName() const;

    std::string getColor() const;

    int getNumberOfLegs() const;
};

std::ostream& operator<<(std::ostream& stream, const Cat& cat);

#endif
