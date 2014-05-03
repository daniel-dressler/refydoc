#include "refydoc/md/ast.hpp"


namespace elib { namespace enumeration
{
#if defined(__clang__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wglobal-constructors"
# pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

#define _(Name) { ::refydoc::md::ast::node_id::Name, #Name }
    const std::map< ::refydoc::md::ast::node_id, std::string>
    basic_enum_traits< ::refydoc::md::ast::node_id>::name_map =
        {
            _(raw_text)
          , _(escape)
          , _(line_break)
          , _(blank_line)
          , _(header)
          , _(link)
          , _(horizontal_rule)
          , _(emphasis_block)
          , _(emphasis_tag)
          , _(block)
          , _(quote_block)
          , _(code_block)
          , _(list)
          , _(list_item)
          , _(html_block)
          , _(html_tag)
          , _(html_comment)
          , _(html_contents)
        };
#undef _

#if defined(__clang__)
# pragma clang diagnostic pop
#endif
}}                                                          // namespace elib
namespace refydoc { namespace md { namespace ast
{
    
}}}                                                         // namespace refydoc