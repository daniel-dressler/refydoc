#ifndef REFYDOC_LOG_HPP
#define REFYDOC_LOG_HPP

# include <elib/logging.hpp>

namespace refydoc 
{
    namespace detail { struct refydoc_log_tag {}; }
    
    using elib::logging::level_e;
    using log = elib::logging::static_log<detail::refydoc_log_tag>;
}                                                           // namespace refydoc
#endif /* REFYDOC_LOG_HPP */