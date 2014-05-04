#include "refydoc/md/token.hpp"
#include <elib/fmt.hpp>

namespace elib { namespace enumeration
{
#if defined(__clang__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wglobal-constructors"
# pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

#define _(Name) { ::refydoc::md::token_id::Name, #Name }
    const std::map< ::refydoc::md::token_id, std::string>
    basic_enum_traits< ::refydoc::md::token_id>::name_map =
        {
            _(none)
          , _(whitespace)
          , _(newline)
          , _(lparen)
          , _(rparen)
          , _(lbrace)
          , _(rbrace)
          , _(lbracket)
          , _(rbracket)
          , _(langle)
          , _(rangle)
          , _(tick)
          , _(plus)
          , _(minus)
          , _(equal)
          , _(exclam)
          , _(amper)
          , _(underscore)
          , _(asterisk)
          , _(identifier)
          , _(escape)
          , _(invalid)
        };
#undef _

#if defined(__clang__)
# pragma clang diagnostic pop
#endif
}}                                                          // namespace elib
namespace refydoc { namespace md
{
    std::string to_string(token const & tk)
    {
        return elib::cat_str(tk.id(), ": \"", tk.raw(), "\" line: ", tk.line());
    }
}}                                                          // namespace refydoc