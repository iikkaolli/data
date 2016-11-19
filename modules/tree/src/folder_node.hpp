#pragma once

#include "tree_node.hpp"

namespace data
{
  struct folder_node : public tree::tree_node
  {
    std::array<std::unique_ptr<tree::tree_node>, 256> m_nodes;
    
  folder_node();
    //folder_node(const folder_node&);
    //folder_node& operator=(const folder_node&);
    //folder_node(folder_node&&);
    //folder_node& operator=(folder_node&&);
    ~folder_node();
    
    bool add_data(std::unique_ptr<tree::tree_node>&, 
		  const guid&,
		  int8_t,
		  const std::string&,
		  const std::string&) override;
    
    void set_node(size_t, std::unique_ptr<tree::tree_node>);
    void add_node(const guid&, int8_t, std::unique_ptr<tree::tree_node>);
    std::unique_ptr<tree::tree_node>& get_folder_position(const guid&,
							  int8_t);
    
  };
  
  std::unique_ptr<tree::tree_node> make_folder_node();
}
