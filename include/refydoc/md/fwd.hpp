#ifndef REFYDOC_MD_FWD_HPP
#define REFYDOC_MD_FWD_HPP

namespace refydoc { namespace md
{
    /// Top level class that stores the MD file
    class document;
    
    /// Store mappings from key -> URL for links
    class link_table;
    
    /// output of parser
    enum class token_id;
    class token;
    
    namespace ast
    {
        /// Base class
        class node;
        
        /// Stores raw texts
        class raw_text;
        
        /// Stores both types of headers
        class header;
        
        /// Node for a link
        class link;
        
        /// Node for an escaped sequence
        class escape;
        
        /// Node for a line break
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
    }                                                       // namespace ast
}}                                                          // namespace refydoc
#endif /* REFYDOC_MD_FWD_HPP */