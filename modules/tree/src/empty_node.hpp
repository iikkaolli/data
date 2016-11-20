#pragma once

#include "tree_node.hpp"

namespace data
{
  
  struct empty_node_s : public tree_s::tree_node_s
  {
    empty_node_s();
    //empty_node(const empty_node&);
    //empty_node& operator=(const empty_node&);
    //empty_node(empty_node&&);
    //empty_node& operator=(empty_node&&);
    ~empty_node_s();
    
    bool add_data(tree_node_p&,
		  const guid&,
		  int8_t,
		  const std::string&,
		  const std::string&) override;
    
    //std::pair<bool, std::string> get_data(const guid&,
    //					  int8_t,
    //					  const std::string&) const override;
  };
  
  tree_node_p make_empty_node();
}
