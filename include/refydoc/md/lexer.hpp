#ifndef REFYDOC_MD_LEXER_HPP
#define REFYDOC_MD_LEXER_HPP

# include "refydoc/md/fwd.hpp"
# include "refydoc/md/lexer_pos.hpp"
# include <string>

namespace refydoc { namespace md
{
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
        token peek();
        token get();
        token peek();
        void unput(lexer_pos); 
        
        bool good() const noexcept;
        bool empty() const noexcept;
        bool bad() const noexcept;
        explicit operator bool() const noexcept;
        
        const_iterator begin() const noexcept;
        const_iterator end() const noexcept;
        const_iterator at() const noexcept;
        
        lexer_pos position() const noexcept;
    
    private:
        iterator m_begin, m_end, m_at;
        lexer_pos m_pos;
    };
}}                                                          // namespace refydoc
#endif /* REFYDOC_MD_LEXER_HPP */