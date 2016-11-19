#pragma once

#include "tree_node.hpp"

namespace data
{
  
  struct empty_node : public tree::tree_node
  {
    empty_node();
    //empty_node(const empty_node&);
    //empty_node& operator=(const empty_node&);
    //empty_node(empty_node&&);
    //empty_node& operator=(empty_node&&);
    ~empty_node();
    
    bool add_data(std::unique_ptr<tree_node> &pNode,
		  const guid& GUID,
		  int8_t depth,
		  const std::string& repo,
		  const std::string& data) override;
    
    //std::pair<bool, std::string> get_data(const guid&,
    //					  int8_t,
    //					  const std::string&) const override;
  };
  
  std::unique_ptr<tree::tree_node> make_empty_node();
}
