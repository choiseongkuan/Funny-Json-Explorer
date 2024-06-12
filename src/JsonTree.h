#ifndef JSONTREE_H
#define JSONTREE_H

#include "CommonLibrary.h"

using namespace std;

/*
 * 工厂模式，用于提供不同风格的对象
 */
class JsonTree {
public:
    virtual void print(vector<pair<int, string >>, vector<int>, string, string) = 0;
};

/*
 * 树形风格
 */
class TreeStyle : public JsonTree {
public:
    TreeStyle(vector<pair<int, string >>, vector<int>, string, string);

    void print(vector<pair<int, string >>, vector<int>, string, string) override;
};

/*
 * 矩形风格
 */
class RectangleStyle : public JsonTree {
public:
    RectangleStyle(vector<pair<int, string >>, vector<int>, string, string);

    void supplement(string &, int);

    void print(vector<pair<int, std::string>>, vector<int>, string, string) override;
};

#endif
