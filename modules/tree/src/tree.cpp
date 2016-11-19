#include "tree.hpp"
#include "empty_node.hpp"

namespace data
{

  tree::tree() : m_node(make_empty_node()) {}
  tree::~tree() {}
  
  bool tree::add_data(const guid& GUID,
		      const std::string& repo,
		      const std::string& data)
  {
    return m_node->add_data(m_node, GUID, 0, repo, data);
  }
  
  //  std::pair<bool, std::string> tree::get_data(const guid &GUID,
  //					      const std::string &repo)
  //{
  //  return m_node->get_data(GUID, repo);
  //}
}
