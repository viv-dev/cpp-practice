#pragma once

#include <memory>
#include <string>

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

    void copyImpl(const RuleOfFiveClass& rhs) {
        // They have a unique_ptr... how do I steal it and make it mine?
        // ... For now we will have to live with simply plagiarising
        // But when we return in the rule of 5, we shall see how we can be
        // theives
        // We can... access private member variables in copy constructor?
        value.reset(new std::string(
            *rhs.value));  // This becomes much more complex if the unique_ptr
                           // is a pointer to a complex object
    }

    void moveImpl(RuleOfFiveClass&& rhs) { value = std::move(rhs.value); }
};