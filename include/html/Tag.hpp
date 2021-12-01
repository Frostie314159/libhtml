#pragma once
#include "../pch.hpp"
#include "TagIdentifier.hpp"

#if __cplusplus < 201103L
#  error "The library requires C++11!"
#endif

#define HTML_VIRTUAL_CONST_NOEXCEPT_FUNCTION(returntype, name, ...) virtual returntype name(__VA_ARGS__) const HTML_NOEXCEPT;
#define HTML_VIRTUAL_CONST_FUNCTION(returntype, name, ...) virtual returntype name(__VA_ARGS__) const;
#define HTML_VIRTUAL_NOEXCEPT_FUNCTION(returntype, name, ...) virtual returntype name(__VA_ARGS__) HTML_NOEXCEPT;
#define HTML_VIRTUAL_FUNCTION(returntype, name, ...) virtual returntype name(__VA_ARGS__);

namespace html{
    using TagAttributes = std::map<html::detail::BaseTagIdentifer, std::string>;
    using TagAttribute = std::pair<html::detail::BaseTagIdentifer, std::string>;
    using ContainedTags = std::map<html::detail::BaseTagIdentifer, Tag>;
    class Tag{
        TagAttributes m_tagAttributes;
        ContainedTags m_containedTags;
    public:
        //constructors
        Tag() = default;
        virtual ~Tag();
        //operator=
        Tag& operator=(const Tag& t_other){
            this = &t_other;
        }
        Tag& operator=(const TagAttribute* t_other){}
        Tag& operator=(TagAttribute t_other){}
        Tag& operator=(std::initializer_list<TagAttribute> t_other){}
        Tag& operator=(Tag&& t_other) noexcept{}
        //get_allocator
        HTML_VIRTUAL_CONST_NOEXCEPT_FUNCTION(TagAttributes::allocator_type, get_allocator);

        //at
        HTML_VIRTUAL_FUNCTION               (Tag&, at, const TagAttribute::first_type& t_key);
        HTML_VIRTUAL_CONST_FUNCTION         (const Tag&, at, const TagAttribute::first_type& t_key);
        //operator[]
        HTML_VIRTUAL_FUNCTION               (Tag&, at, const TagAttribute::first_type& t_key);
        HTML_VIRTUAL_FUNCTION               (Tag&, at, TagAttribute::first_type&& t_key);

        //begin
        HTML_VIRTUAL_NOEXCEPT_FUNCTION      (TagAttributes::iterator, begin);
        //cbegin
        HTML_VIRTUAL_CONST_NOEXCEPT_FUNCTION(TagAttributes::const_iterator, cbegin);
        //end
        HTML_VIRTUAL_NOEXCEPT_FUNCTION      (TagAttributes::iterator, end);
        //cend
        HTML_VIRTUAL_CONST_NOEXCEPT_FUNCTION(TagAttributes::const_iterator, cend);
        //rbegin
        HTML_VIRTUAL_NOEXCEPT_FUNCTION      (TagAttributes::reverse_iterator, rbegin);
        //crbegin
        HTML_VIRTUAL_CONST_NOEXCEPT_FUNCTION(TagAttributes::const_reverse_iterator, crbegin);
        //rend
        HTML_VIRTUAL_NOEXCEPT_FUNCTION      (TagAttributes::reverse_iterator, rend);
        //crend
        HTML_VIRTUAL_CONST_NOEXCEPT_FUNCTION(TagAttributes::const_reverse_iterator, crend);

        //empty
        HTML_VIRTUAL_CONST_NOEXCEPT_FUNCTION(bool, empty);
        //size
        HTML_VIRTUAL_CONST_NOEXCEPT_FUNCTION(std::size_t, size);
        //max_size
        HTML_VIRTUAL_CONST_NOEXCEPT_FUNCTION(std::size_t, max_size);

        //clear
        HTML_VIRTUAL_NOEXCEPT_FUNCTION(void,clear);
        //insert
        HTML_VIRTUAL_FUNCTION(TagAttribute, insert, cons)

        //swap
        HTML_VIRTUAL_NOEXCEPT_FUNCTION      (void, swap, const Tag& t_other);
        HTML_VIRTUAL_NOEXCEPT_FUNCTION      (void, swap, Tag&& t_other);
        //reset
        HTML_VIRTUAL_NOEXCEPT_FUNCTION      (void, reset);

        HTML_VIRTUAL_NOEXCEPT_FUNCTION      (TagAttributes&, attributes);
        HTML_VIRTUAL_NOEXCEPT_FUNCTION      (ContainedTags&, containedTags);
    };
};