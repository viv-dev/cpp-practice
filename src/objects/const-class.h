#pragma once

#include <string>
#include <vector>

/*
  This is a class the defines the correct overload behaviours
  for acheiving 'conceptual' constness when an object is
  declared 'const'
*/
class StringWithConst {
   public:
    StringWithConst() : m_string() {}
    ~StringWithConst() {}

    // Will be called when object is declared without const keyword
    char& operator[](const std::size_t position) {
        // Calls the const version of the operator to avoid duplication
        return const_cast<char&>(  // Removes const on the return value
            static_cast<const StringWithConst&>(
                *this)[position]  // Casts 'this' as const so we can call the
                                  // const version of the overloaded operator
                                  // and avoid an infinite loop of non-const
                                  // calls to this function
        );
    }

    // Will be called on an object declared const
    const char& operator[](const std::size_t position) const {
        return m_string[position];
    }

   private:
    std::string m_string;
};