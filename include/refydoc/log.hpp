#ifndef REFYDOC_LOG_HPP
#define REFYDOC_LOG_HPP

# include <elib/logging.hpp>

namespace refydoc 
{
    namespace detail { struct refydoc_log_tag {}; }
    
    /// A logging level enun containing:
    ///   debug, step, info, warn, err, fatal
    using elib::logging::level_e;
    
    /// A static log type that supports logging on log::debug, log::step, ect...
    using log = elib::logging::static_log<detail::refydoc_log_tag>;
}                                                           // namespace refydoc
#endif /* REFYDOC_LOG_HPP */