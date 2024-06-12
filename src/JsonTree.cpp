#include "JsonTree.h"


TreeStyle::TreeStyle(vector<pair<int, string >> jsonParserResult, vector<int> childrenCounter, string icon1 = "",
                     string icon2 = "") {
    print(jsonParserResult, childrenCounter, icon1, icon2);
}

void TreeStyle::print(vector<pair<int, string >> jsonParserResult, vector<int> childrenCounter, string icon1 = "",
                      string icon2 = "") {
    int trunk = childrenCounter[0];
    string out;
    for (int i = 1; i < jsonParserResult.size(); i++) {
        string name = jsonParserResult[i].second;
        if (jsonParserResult[i].first == -1) {
            out.pop_back();
            if (name != "null") {
                out.append(": ");
                out.append(name);
            }
            out += '\n';
            continue;
        }
        if (jsonParserResult[i].first == 1) {
            --trunk;
        }
        if (trunk > 0 && jsonParserResult[i].first != 1) {
            out.append("│");
        }
        for (int j = 1; j < jsonParserResult[i].first; j++) {
            out.append("  ");
        }
        if (childrenCounter[i - 1] > 1) {
            out.append("├─");
            out.append(jsonParserResult[i + 1].first != -1 ? icon1 : icon2);
            out.append(name);
            out += '\n';
        } else {
            out.append("└─");
            out.append(jsonParserResult[i + 1].first != -1 ? icon1 : icon2);
            out.append(name);
            out += '\n';
        }
        --childrenCounter[i - 1];

    }
    cout << out;
}


RectangleStyle::RectangleStyle(vector<pair<int, string >> jsonParserResult, vector<int> childrenCounter,
                               string icon1 = "", string icon2 = "") {
    print(jsonParserResult, childrenCounter, icon1, icon2);
}

void RectangleStyle::supplement(string &input, int n) {
    for (int i = 0; i < n; i++) {
        input.append("─");
    }
}

void
RectangleStyle::print(vector<pair<int, std::string>> jsonParserResult, vector<int> childrenCounter, string icon1 = "",
                      string icon2 = "") {
    int remainder = 42;
    string out;
    out.append("┌─");
    out.append(icon1);
    remainder -= 3;
    out.append(jsonParserResult[1].second);
    remainder -= jsonParserResult[1].second.size();
    supplement(out, remainder);
    out.append("─┐");
    out += '\n';
    int lastContainer = 0;
    int i = jsonParserResult.size() - 1;
    while (i > 0) {
        if (jsonParserResult[i].first != -1) {
            lastContainer = i;
            break;
        }
        --i;
    }
    for (i = 2; i < lastContainer; i++) {
        string name = jsonParserResult[i].second;
        if (jsonParserResult[i].first == -1) {
            if (name != "null") {
                out.append(": ");
                remainder -= 2;
                out.append(name);
                remainder -= jsonParserResult[i].second.size();
            }
            supplement(out, remainder);
            out.append("─┤");
            out += '\n';
            continue;
        }
        remainder = 42;
        for (int j = 1; j < jsonParserResult[i].first; j++) {
            out.append("│ ");
            remainder -= 2;
        }
        out.append("├─");
        out.append(jsonParserResult[i + 1].first != -1 ? icon1 : icon2);
        remainder -= 3;
        out.append(name);
        remainder -= name.size();
        if (jsonParserResult[i + 1].first != -1) {
            supplement(out, remainder);
            out.append("─┤");
            out += '\n';
        }
    }
    for (i; i < jsonParserResult.size(); i++) {
        string name = jsonParserResult[i].second;
        if (jsonParserResult[i].first == -1) {
            if (name != "null") {
                out.append(": ");
                remainder -= 2;
                out.append(name);
                remainder -= jsonParserResult[i].second.size();
            }
            supplement(out, remainder);
            out.append("─┘");
            out += '\n';
            continue;
        }
        remainder = 42;
        for (int j = 1; j < jsonParserResult[i].first; j++) {
            out.append("└─");
            remainder -= 2;
        }
        out.append("└─");
        out.append(jsonParserResult[i + 1].first != -1 ? icon1 : icon2);
        remainder -= 3;
        out.append(jsonParserResult[i].second);
        remainder -= jsonParserResult[i].second.size();
        if (jsonParserResult[i + 1].first != -1) {
            supplement(out, remainder);
            out.append("─┘");
        }
    }
    cout << out;
}