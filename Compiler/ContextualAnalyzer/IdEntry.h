#ifndef _IDENTRY
#define _IDENTRY

#include "./AST/Declaration.h"
#include <string>

using namespace std;

class IdEntry {

public:
  string id;
  Declaration* attr;
  int level;
  bool visible;
  Declaration *package;
  IdEntry* previous;

  IdEntry (string id, Declaration* attr, int level, IdEntry* previous) {
    this->id = id;
    this->attr = attr;
    this->level = level;
    this->previous = previous;
    this->visible = true;
  }
  IdEntry (string id, Declaration* attr, int level, IdEntry* previous, bool vis, Declaration *package) {
    this->id = id;
    this->attr = attr;
    this->level = level;
    this->previous = previous;
    this->visible = vis;
    this->package = package;
  }
};

#endif
