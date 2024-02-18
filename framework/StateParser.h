/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-17 11:21:40
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 15:17:45
 */

#include <vector>

#include "include/tinyxml/tinyxml.h"
#include "Node.h"

class StateParser
{
public:
  StateParser() {}
  ~StateParser() {}

  bool parseState(
      std::string file,
      std::string stateId,
      std::vector<Node *> *objects,
      std::vector<std::string> *textureIds);

private:
  void parseTextures(TiXmlElement *stateRoot, std::vector<std::string> *textureIds);
  void parseObjects(TiXmlElement *stateRoot, std::vector<Node *> *objects);
};
