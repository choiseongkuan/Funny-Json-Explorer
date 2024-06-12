#include "FunnyJsonExplorer.h"


FunnyJsonExplorer::FunnyJsonExplorer(Component *root) {
    root->draw(jsonParserResult, childrenCounter);
}


TreeFactory::TreeFactory(Component *root) : FunnyJsonExplorer(root) {}

JsonTree *TreeFactory::show(string icon1 = "", string icon2 = "") const {
    return new TreeStyle(this->jsonParserResult, this->childrenCounter, icon1, icon2);
}


RectangleFactory::RectangleFactory(Component *root) : FunnyJsonExplorer(root) {}

JsonTree *RectangleFactory::show(string icon1 = "", string icon2 = "") const {
    return new RectangleStyle(this->jsonParserResult, this->childrenCounter, icon1, icon2);
}
