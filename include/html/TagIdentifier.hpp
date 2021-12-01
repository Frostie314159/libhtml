#pragma once
#include "../pch.hpp"

namespace html{
    namespace detail{
        struct BaseTagIdentifer{
            std::string name;
        };
    };
    struct ID : public detail::BaseTagIdentifer{};
    struct Class : public detail::BaseTagIdentifer{};
    struct TagName : public detail::BaseTagIdentifer{};
}
html::ID operator""id(const char* t_id){
    return html::ID{t_id};
}
html::Class operator""class(const char* t_class){
    return html::Class{t_class};
}
html::TagName operator""tagname(const char* t_tagName){
    return html::TagName{t_tagName};
}