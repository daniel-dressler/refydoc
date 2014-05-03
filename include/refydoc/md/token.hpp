#ifndef REFYDOC_MD_TOKEN_HPP
#define REFYDOC_MD_TOKEN_HPP

# include "refydoc/md/fwd.hpp"
# include <elib/aux/move.hpp>
# include <elib/enumeration.hpp>
# include <map>
# include <string>
# include <cstddef>

namespace refydoc { namespace md
{
    ////////////////////////////////////////////////////////////////////////////
    enum class token_id
    {
        invalid, 
        
        /// Whitespace
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
        
        identifier, 
        escape 
    };
    
    ////////////////////////////////////////////////////////////////////////////
    constexpr bool is_invalid(token_id id) noexcept
    {
        return token_id::invalid == id;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    constexpr bool is_whitespace(token_id id) noexcept
    {
        return token_id::whitespace == id 
            || token_id::newline == id; 
    }
    
    ////////////////////////////////////////////////////////////////////////////
    constexpr bool is_newline(token_id id) noexcept
    {
        return token_id::newline == id;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    constexpr bool is_control(token_id id) noexcept
    {
        return token_id::lparen <= id && token_id::amper >= id;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    constexpr bool is_identifier(token_id id) noexcept
    {
        return token_id::identifier == id;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    constexpr bool is_escape(token_id id) noexcept
    {
        return token_id::escape == id;
    }
}}                                                          // namespace refydoc
namespace elib { namespace enumeration
{
    template <>
    struct basic_enum_traits< ::refydoc::md::token_id>
    {
        static const std::map< ::refydoc::md::token_id, std::string> name_map;
    };
}}                                                          // namespace elib
namespace refydoc { namespace md
{
    ////////////////////////////////////////////////////////////////////////////
    inline std::string to_string(token_id id)
    {
        return elib::enumeration::enum_cast<std::string>(id);
    }
    
    ////////////////////////////////////////////////////////////////////////////
    class token
    {
    public:
        token()
          : m_id(token_id::invalid), m_raw(), m_line(unsigned(-1))
        {}
        
        token(token_id xid, std::string xraw, unsigned xline = unsigned(-1))
          : m_id(xid), m_raw(xraw), m_line(xline)
        {}
        
        token(token const &) = default;
        token(token &&) = default;
        token & operator=(token const &) = default;
        token & operator=(token &&) = default;
        
        operator token_id() const noexcept
        { return m_id; }
        
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
    
    ////////////////////////////////////////////////////////////////////////////
    std::string to_string(token const &);
}}                                                          // namespace refydoc
#endif /* REFYDOC_MD_TOKEN_HPP */