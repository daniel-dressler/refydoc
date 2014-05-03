#ifndef REFYDOC_MD_AST_HPP
#define REFYDOC_MD_AST_HPP

# include "refydoc/md/fwd.hpp"
# include <elib/enumeration.hpp>
# include <string>

namespace refydoc { namespace md { namespace ast
{
    enum class node_id
    {
        raw_text, 
        escape, 
        line_break, 
        blank_line,
        header, 
        link, 
        horizontal_rule, 
        emphasis_block, 
        emphasis_tag, 
        block, 
        quote_block, 
        code_block, 
        list, 
        list_item, 
        html_block, 
        html_tag, 
        html_comment, 
        html_contents
    };
}}}                                                         // namespace refydoc
namespace elib { namespace enumeration
{
    template <>
    struct basic_enum_traits< ::refydoc::md::ast::node_id>
    {
        static const std::map< ::refydoc::md::ast::node_id, std::string> name_map;
    };
}}                                                          // namespace elib
namespace refydoc { namespace md { namespace ast
{
    ////////////////////////////////////////////////////////////////////////////
    inline std::string to_string(node_id id) noexcept
    {
        return elib::enumeration::enum_cast<std::string>(id);
    }
    
    /// Base class
    class node
    {
        
    };
        
    /// Stores raw texts
    class raw_text;
        
    /// Stores both types of headers
    class header;
        
    /// Node for a link
    class link;
        
    /// Node for an escaped sequence
    class escape;
        
    /// Node for a line breakEnu
    class line_break;
    
    /// Node for a blank line
    class blank_line;
        
    /// Node for a horizontal_rule
    class horizontal_rule;
        
    /// A block surrounded by emphasis tags
    class emphasis_block;
    class emphasis_tag;
        
        /// Blocks store multiple nested nodes
    class block;
    class paragraph;
    class quote_block;
    class code_block;
    class list;
    class list_item;
        
    /// Nodes for represeting HTML. All HTML nodes should be within an
    /// HTML block
    class html_block;
    class html_tag;
    class html_comment;
    class html_contents;
}}}                                                         // namespace refydoc
#endif /* REFYDOC_MD_AST_HPP */