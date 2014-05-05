#ifndef REFYDOC_ERROR_HPP
#define REFYDOC_ERROR_HPP

# include <elib/exception.hpp>
# include <elib/aux/default_class.hpp>

namespace refydoc 
{
    class refydoc_error : public elib::exception
    {
        using elib::exception::exception;
        ELIB_DEFAULT_COPY_MOVE(refydoc_error);
    };
}                                                          // namespace refydoc
#endif /* REFYDOC_ERROR_HPP */