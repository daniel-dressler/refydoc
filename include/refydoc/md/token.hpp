#ifndef REFYDOC_MD_TOKEN_HPP
#define REFYDOC_MD_TOKEN_HPP

# include "refydoc/md/fwd.hpp"
# include <elib/aux/move.hpp>
# include <string>
# include <cstddef>

namespace refydoc { namespace md
{
    enum class token_id
    {
        none,
        /// 
        whitespace, 
        newline,
        
        /// Control characters
        lparen, 
        rparen, 
        lbrace, 
        rbrace,
        lbracket,
        rbracket,
        langle, 
        rangle, 
        tick, 
        hyphen, 
        equal, 
        exclam, 
        amper, 
        
        id, 
        
        invalid_char, 
    };
    
    std::string to_string(token_id);
    
    class token
    {
    public:
        token()
          : m_id(token_id::none), m_raw(), m_line(unsigned(-1))
        {}
        
        token(token_id xid, std::string xraw, unsigned xline = unsigned(-1))
          : m_id(xid), m_raw(xraw), m_line(xline)
        {}
        
        token(token const &) = default;
        token(token &&) = default;
        token & operator=(token const &) = default;
        token & operator=(token &&) = default;
        
        token_id id() const noexcept
        { return m_id; }
        
        void id(token_id xid) noexcept
        { m_id = xid; }
        
        std::string const & raw() const noexcept
        { return m_raw; }
        
        void raw(std::string xraw)
        { m_raw = elib::move(xraw); }
        
        std::size_t size() const noexcept
        { return m_raw.size(); }
        
        unsigned line() const noexcept
        { return m_line; }
        
        void line(unsigned xline) noexcept
        { m_line = xline; }
        
    private:
        token_id m_id;
        std::string m_raw;
        unsigned m_line;
    };
    
    std::string to_string(token);
}}                                                          // namespace refydoc
#endif /* REFYDOC_MD_TOKEN_HPP */