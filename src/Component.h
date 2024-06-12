#ifndef COMPONENT_H
#define COMPONENT_H

#include "CommonLibrary.h"

using namespace std;

/*
 * 组合模式，用于描述JSON的树形结构
 */
class Component {
protected:
    Component *parent;
    string name;
public:
    void setParent(Component *);

    Component *getParent() const;

    virtual void add(Component *);

    virtual void draw(vector<pair<int, string>> &, vector<int> &) const = 0;
};

/*
 * 中间节点类，可以包含叶子节点及中间节点
 */
class Container : public Component {
protected:
    list<Component *> children;
    int level;
public:
    Container(int, string);

    void add(Component *) override;

    void draw(vector<pair<int, string>> &, vector<int> &) const override;
};

/*
 * 叶子节点类
 */
class Leaf : public Component {
public:
    Leaf(string);

    void draw(vector<pair<int, string>> &, vector<int> &) const override;
};

#endif
