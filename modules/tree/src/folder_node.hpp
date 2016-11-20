#pragma once

#include "tree_node.hpp"

namespace data
{
  struct folder_node_s : public tree_s::tree_node_s
  {
    std::array<tree_node_p, 256> m_nodes;
    int8_t m_depth;
    
    folder_node_s(int8_t);
    //folder_node_s(const folder_node_s&);
    //folder_node_s& operator=(const folder_node_s&);
    //folder_node_s(folder_node_s&&);
    //folder_node_s& operator=(folder_node_s&&);
    ~folder_node_s();
    
    bool add_data(tree_node_p&, 
		  const guid&,
		  int8_t,
		  const std::string&,
		  const std::string&) override;
    
    void set_node(size_t, tree_node_p);
    void add_node(const guid&, int8_t, tree_node_p);
    tree_node_p& get_folder_position(const guid&);
  };
  
  tree_node_p make_folder_node(int8_t);
}
