#ifndef EMPTY_STRING_EXCEPTION
#define EMPTY_STRING_EXCEPTION
#include <exception>
class Empty_string_exception: public std::exception {
public:
    Empty_string_exception() = default;
    ~Empty_string_exception() = default;
    const char* what() const noexcept override {
        return "Exception thrown. Empty value.";
    }
};
#endif