#ifndef FUNNYJSONEXPLORER_H
#define FUNNYJSONEXPLORER_H

#include "CommonLibrary.h"
#include "Component.h"
#include "JsonTree.h"

using namespace std;

/*
 * 抽象工厂模式，用于提供不同类型的图标族
 */
class FunnyJsonExplorer {
protected:
    vector<pair<int, std::string>> jsonParserResult;
    vector<int> childrenCounter;
public:
    FunnyJsonExplorer(Component *);

    virtual JsonTree *show(string, string) const = 0;

};

/*
 * 树形工厂，对树形对象使用统一的图标族
 */
class TreeFactory : public FunnyJsonExplorer {
public:
    TreeFactory(Component *);

    JsonTree *show(string, string) const override;
};

/*
 * 矩形工厂，对矩形对象使用统一的图标族
 */
class RectangleFactory : public FunnyJsonExplorer {
public:
    RectangleFactory(Component *);

    JsonTree *show(string, string) const override;
};

#endif
