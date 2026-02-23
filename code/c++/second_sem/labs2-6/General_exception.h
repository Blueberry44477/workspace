// #ifndef GENERAL_EXCEPTION_H
// #define GENERAL_EXCEPTION_H
// #include <string>
// class General_exception: public std::exception {
// private:
//     std::string m_exception;
// public:
//     General_exception(const std::string &exception = "General exception") :m_exception{exception} {}
//     ~General_exception() = default;
//     const char *what() const noexcept override {
//         return "General exception.";
//     }
// };
// #endif