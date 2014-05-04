#include "refydoc/md/lexer.hpp"
#include "refydoc/md/token.hpp"

namespace refydoc { namespace md
{
    namespace 
    {
        using iterator = lexer::iterator;
        
        token create_token(token_id id, iterator first, iterator last)
        { return token(); }
        
        iterator parse_whitespace(iterator first, iterator last)
        { return first; }
        
        iterator parse_identifier(iterator first, iterator last)
        { return first; }
        
        iterator parse_escape(iterator first, iterator last)
        { return first; }
        
        iterator parse_control(iterator first, iterator last)
        { return first; }
    }                                                       // namespace 
    
    token lexer::peek() const
    {
        if (empty()) {
            return create_token(token_id::none, m_at, m_at);
        } 
        else if (*m_at == '\n') {
            return create_token(token_id::newline, m_at, m_at + 1);
        }
        else if (is_whitespace(*m_at)) {
            return create_token(token_id::whitespace, m_at, parse_whitespace(m_at, m_end));
        }
        else if (is_alpha_numeric(*m_at)) {
            return create_token(token_id::identifier, m_at, parse_identifier(m_at, m_end));
        }
         else if (*m_at == '\\') {
            return create_token(token_id::escape, m_at, parse_escape(m_at, m_end));
        }
        else if (is_control(*m_at)) {
            //TODO
            //return create_token(token_id::control, m_at, parse_control(m_at, m_end));
            return token();
        } else {
            return create_token(token_id::invalid, m_at, m_at + 1);
        }
    }
    
    ////////////////////////////////////////////////////////////////////////////
    token lexer::get()
    {
        auto tk = peek();
        set_position(tk.position());
        return tk;
    }
    
    
}}                                                          // namespace refydoc