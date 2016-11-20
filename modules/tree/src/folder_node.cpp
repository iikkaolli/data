#include "folder_node.hpp"
#include "empty_node.hpp"
#include "leaf_node.hpp"

namespace data
{
  
  folder_node_s::folder_node_s(int8_t depth) : m_depth(depth)
  {
    for(size_t ii = 0; ii < 256; ++ii) {
      set_node(ii, make_empty_node());
    }
  }
  
  folder_node_s::~folder_node_s() {}
  
  bool folder_node_s::add_data(tree_node_p& node,
			       const guid& GUID,
			       int8_t depth,
			       const std::string& repo,
			       const std::string& data)
  {
    auto& position = get_folder_position(GUID);
    return position->add_data(node, GUID, depth, repo, data);
  }
  
  void folder_node_s::set_node(size_t index,
			       tree_node_p node)
  {
    //m_nodes[index] = node;
  }
  
  void folder_node_s::add_node(const guid& GUID,
			       int8_t depth,
			       tree_node_p node)
  {
    auto& position = get_folder_position(GUID);
    position.swap(node);
  }
  
  tree_node_p& folder_node_s::get_folder_position(const guid& GUID)
  {
    //return m_nodes[GUID[depth]];
    return m_nodes[0];
  }

  tree_node_p make_folder_node(int8_t depth)
  {
    return tree_node_p{ new folder_node_s{depth} };
  }
}
