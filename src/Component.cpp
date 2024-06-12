#include "Component.h"


void Component::setParent(Component *parent) {
    this->parent = parent;
}

Component *Component::getParent() const {
    return this->parent;
}

void Component::add(Component *component) {};

Container::Container(int level, string name) {
    this->level = level;
    this->name = name;
}

void Container::add(Component *component) {
    children.push_back(component);
    component->setParent(this);
}

void Container::draw(vector<pair<int, string>> &result, vector<int> &counter) const {
    result.push_back(make_pair(this->level, this->name));
    counter.push_back(this->children.size());
    for (const Component *c: children) {
        c->draw(result, counter);
    }
    return;
}

Leaf::Leaf(string name) {
    this->name = name;
}

void Leaf::draw(vector<pair<int, string>> &result, vector<int> &counter) const {
    result.push_back(make_pair(-1, this->name));
    return;
}
