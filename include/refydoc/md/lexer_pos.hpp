#ifndef REFYDOC_MD_LEXER_POS_HPP
#define REFYDOC_MD_LEXER_POS_HPP

# include "refydoc/md/fwd.hpp"

namespace refydoc { namespace md
{
    ////////////////////////////////////////////////////////////////////////////
    struct lexer_pos
    {
        lexer_pos()
          : index(0), line(0), col(0)
        {}
        
        explicit lexer_pos(unsigned xindex, unsigned xline = 0, unsigned xcol = 0)
          : index(xindex), line(xline), col(xcol)
        {}
        
        lexer_pos(lexer_pos const &) = default;
        lexer_pos & operator=(lexer_pos const &) = default;
        
        unsigned index;
        unsigned line;
        unsigned col;
    };
    
    ////////////////////////////////////////////////////////////////////////////
    constexpr bool operator==(lexer_pos const & lhs, lexer_pos const & rhs) noexcept
    {
        return lhs.index == rhs.index;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    constexpr bool operator!=(lexer_pos const & lhs, lexer_pos const & rhs) noexcept
    {
        return lhs.index != rhs.index;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    constexpr bool operator<(lexer_pos const & lhs, lexer_pos const & rhs) noexcept
    {
        return lhs.index < rhs.index;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    constexpr bool operator>(lexer_pos const & lhs, lexer_pos const & rhs) noexcept
    {
        return lhs.index > rhs.index;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    constexpr bool operator<=(lexer_pos const & lhs, lexer_pos const & rhs) noexcept
    {
        return lhs.index <= rhs.index;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    constexpr bool operator>=(lexer_pos const & lhs, lexer_pos const & rhs) noexcept
    {
        return lhs.index >= rhs.index;
    }
    
}}                                                          // namespace refydoc
#endif /* REFYDOC_MD_LEXER_POS_HPP */