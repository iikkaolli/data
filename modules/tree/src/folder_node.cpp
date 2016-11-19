#include "folder_node.hpp"
#include "empty_node.hpp"
#include "leaf_node.hpp"

namespace data
{
  
  folder_node::folder_node()
  {
    for(size_t ii = 0; ii < 256; ++ii) {
      set_node(ii, make_empty_node());
    }
  }
  
  folder_node::~folder_node() {}

  bool folder_node::add_data(std::unique_ptr<tree::tree_node>& node,
			     const guid& GUID,
			     int8_t depth,
			     const std::string& repo,
			     const std::string& data)
  {
    auto new_node = make_leaf_node(GUID, repo, data);
    //    set_node(GUID, depth, new_node);

    return true;
  }
  
  void folder_node::set_node(size_t index,
			     std::unique_ptr<tree::tree_node> node)
  {
    //m_nodes[index] = node;
  }
  
  void folder_node::add_node(const guid& GUID,
			     int8_t depth,
			     std::unique_ptr<tree::tree_node> node)
  {
    auto& position = get_folder_position(GUID, depth);
    position.swap(node);
  }
  
  std::unique_ptr<tree::tree_node>& folder_node::get_folder_position(const guid& GUID,
								     int8_t depth)
  {
    //return m_nodes[GUID[depth]];
    return m_nodes[0];
  } 
}
