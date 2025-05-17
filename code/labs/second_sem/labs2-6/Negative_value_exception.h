#ifndef NEGATIVE_VALUE_EXCEPTION
#define NEGATIVE_VALUE_EXCEPTION
#include <exception>
class Negative_value_exception : public std::exception {
public:
    Negative_value_exception() = default;
    ~Negative_value_exception() = default;
    const char* what() const noexcept override {
        return "Exception thrown. Negative value.";
    }
};
#endif