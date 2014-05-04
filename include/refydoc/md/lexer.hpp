#ifndef REFYDOC_MD_LEXER_HPP
#define REFYDOC_MD_LEXER_HPP

# include "refydoc/md/fwd.hpp"
# include "refydoc/md/lexer_pos.hpp"
# include <elib/ranges/algorithm.hpp>
# include <array>
# include <string>
# include <utility>

namespace refydoc { namespace md
{
    
    constexpr std::array<char, 17> control_characters = 
        {{ 
            '(', ')', '{', '}', '[', ']', '<', '>'
          , '`', '*', '_', '+', '-', '=', '!', '&',  '#'
        }};
        
    constexpr std::array<char, 14> escape_characters = 
        {{
            '(', ')', '{', '}', '[', ']'
          , '`', '*', '_', '+', '-', '#', '.', '!'
        }};
    
    inline bool is_whitespace(char ch) noexcept
    {
        return std::isspace(ch);
    }
    
    inline bool is_newline(char ch) noexcept
    {
        return '\n' == ch;
    }
    
    inline bool is_alpha_numeric(char ch) noexcept
    {
        return std::isalnum(ch);
    }
    
    inline bool is_control(char ch) noexcept
    {
        return elib::ranges::count(control_characters, ch);
    }
    
    inline bool is_escape(char ch) noexcept
    {
        return elib::ranges::count(escape_characters, ch);
    }
    
    class lexer
    {
    public:
        using iterator = std::string::const_iterator;
        using const_iterator = std::string::const_iterator;
        
    public:
        lexer() = default;
        
        lexer(iterator xbegin, iterator xend)
          : m_begin(xbegin), m_end(xend), m_pos()
        {}
        
        lexer(lexer const &) = default;
        lexer(lexer &&) = default;
        lexer & operator=(lexer const &) = default;
        lexer & operator=(lexer &&) = default;
        
    public:
        token peek() const;
        token get();
        
        void unput(lexer_pos p)
        {
            set_position(p);
        }
        
        bool empty() const noexcept
        {
            return m_begin == m_end;
        }
        
        explicit operator bool() const noexcept
        {
            return !empty();
        }
        
        const_iterator begin() const noexcept
        {
            return m_begin;
        }
        
        const_iterator end() const noexcept
        {
            return m_end;
        }
        
        const_iterator at() const noexcept
        {
            return m_at;
        }
        
        lexer_pos position() const noexcept
        {
            return m_pos;
        }
        
        void set_position(lexer_pos const & pos)
        {
            m_at = m_begin + pos.index;
            m_pos = pos;
        }
        
        void reset()
        {
            m_at = m_begin;
            m_pos = lexer_pos();
        }
        
    private:
        iterator m_begin, m_end, m_at;
        lexer_pos m_pos;
    };
}}                                                          // namespace refydoc
#endif /* REFYDOC_MD_LEXER_HPP */