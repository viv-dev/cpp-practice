#pragma once

#include <memory>
#include <string>

/**
 * Rule of 5 suggests that if we need to define our own implementation of
 * implicit class functions (e.g. constructor, deconstructor, copy/move
 * constructor + operators ), we should probably define all of them.
 */
class RuleOfFiveClass {
   public:
    // Standard Constructor
    RuleOfFiveClass(std::string initialValue)
        : value(std::make_unique<std::string>(new std::string(initialValue))) {}

    // Copy Constructor
    RuleOfFiveClass(const RuleOfFiveClass& rhs) { copyImpl(rhs); }

    // Move Constructor
    RuleOfFiveClass(RuleOfFiveClass&& rhs) { moveImpl(rhs); }

    // Copy Assignment Operator
    RuleOfFiveClass& operator=(const RuleOfFiveClass& rhs) {
        copyImpl(rhs);
        return *this;
    }

    // Move Assignment Operator
    RuleOfFiveClass& operator=(RuleOfFiveClass&& rhs) {
        moveImpl(rhs);
        return *this;
    }

    ~RuleOfFiveClass() {
        // Nothing to do because our pointer is smart
    }

   private:
    // Make unique so no one outside of this class can have a pointer to it...
    // It is my precious...
    std::unique_ptr<std::string> value;

    // Common copy implementation so logic isn't duplicated between copy
    // constructor and copy assignment operator
    void copyImpl(const RuleOfFiveClass& rhs) {
        // They have a unique_ptr... how do I steal it and make it mine?
        // ... In copy constructor/operators now we will have to live with
        // simply plagiarising
        value.reset(new std::string(
            *rhs.value));  // This becomes much more complex if the unique_ptr
                           // is a pointer to a complex object
    }

    void moveImpl(RuleOfFiveClass&& rhs) {
        // Here we can directly steal / gut this value from the reference class
        // Your sacrifice will not be in vain, my friend...
        value = std::move(rhs.value);
    }
};