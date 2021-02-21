#pragma once

#include <string>

class RuleofThreeClass {
   public:
    RuleofThreeClass(std::string initialValue)
        : value(new std::string(initialValue)) {}

    ~RuleofThreeClass() { delete value; }

   private:
    std::string& value;
}