#pragma once

#include <exception>
#include <string>

namespace AG {
class Exception : public std::exception {
public:
    enum class Severity {
        Warning,
        Error,
        Critical,
        Fatal,
    };

    Exception(Severity severity, const std::string &what)
        : m_severity{severity}, m_what{what}
    {
    }

    virtual const char *what() const _GLIBCXX_NOTHROW { return m_what.c_str(); }
    Severity severity() const _GLIBCXX_NOTHROW { return m_severity; }

protected:
    Severity m_severity = Severity::Error;
    std::string m_what;
};
} // namespace AG