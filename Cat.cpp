#include "Cat.h"

Cat::Cat(std::string mName, std::string mColor, int mNumberOfLegs) {
  name = mName;
  color = mColor;
  numberOfLegs = mNumberOfLegs;
}

std::string Cat::getName() const {
  return name;
}

std::string Cat::getColor() const {
  return color;
}

int Cat::getNumberOfLegs() const {
  return numberOfLegs;
}

std::ostream& operator<<(std::ostream& stream, const Cat& cat) {
  stream << "Cate(name= " << cat.getName() << ", color= "
  << cat.getColor() << ", number of legs= "
  << cat.getNumberOfLegs() << ")";
  return stream;
}
