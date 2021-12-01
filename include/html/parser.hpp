#pragma once
#include "TagBase.hpp"

namespace html::detail::Parser{
    const std::vector<TagBase> parse(const std::string& t_source){
        html::TagBase m_currentTag;
        for(auto t_iterator = t_source.begin(); t_iterator != t_source.end(); ++t_iterator){
            
        }
    }
}