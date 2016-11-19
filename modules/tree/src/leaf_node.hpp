#include "tree_node.hpp"
#include <vector>
#include <map>

namespace data
{
  
  using leaf_storage_t = std::vector<std::string>;
  
  struct leaf_node_s : public tree::tree_node
  {
    guid m_GUID;
    std::map<std::string, leaf_storage_t> m_data;
    
    leaf_node_s(const guid& GUID,
		const std::string&,
		const std::string&);
    //leaf_node(const leaf_node&);
    //leaf_node& operator=(const leaf_node&);
    //leaf_node(leaf_node&&);
    //leaf_node& operator=(leaf_node&&);
    ~leaf_node_s();
    
    bool add_data(std::unique_ptr<tree_node>&,
		  const guid&,
		  int8_t,
		  const std::string&,
		  const std::string&) override;
    
    leaf_storage_t& get_leaf_data_storage(const std::string&);
    void set_leaf_data(const std::string&, const std::string&);
    
    const guid& get_guid() const;
  };
  
  std::unique_ptr<tree::tree_node> make_leaf_node(const guid&,
						  const std::string&,
						  const std::string&);
}
