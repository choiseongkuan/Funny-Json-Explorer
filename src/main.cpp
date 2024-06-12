#include "CommonLibrary.h"
#include "Component.h"
#include "JsonTree.h"
#include "FunnyJsonExplorer.h"
#include "Builder.h"

using namespace std;

/*
 * 清除字符串中的引号
 */
string trim(string input) {
    string output;
    for (auto i: input) {
        if (i != 34) {
            output += i;
        }
    }
    output = output.substr(1, output.size() - 2);
    return output;
}

/*
 * 清除字符串前后的空格
 */
void strip(string &input) {
    if (input.empty()) {
        return;
    }
    int i = 0;
    while (input[i] == 32) {
        i++;
    }
    int j = input.size() - 1;
    while (input[j] == 32) {
        j--;
    }
    input = input.substr(i, j - i + 1);
}

/*
 * 用于读取Json文件
 */
string readFile(string filename) {
    string output;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            strip(line);
            output.append(line);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    return output;

}


int main(int argc, char *argv[]) {
    // 读取参数
    string filepath = argv[2];
    string style = argv[4];
    string icon1 = "", icon2 = "";
    if (argc == 8) {
        icon1 = argv[6];
        icon2 = argv[7];
    }
    // 客户代码
    string getfile = readFile(filepath);  // 读取Json文件
    string jsonStr = trim(getfile);  // 规格化Json字符串
    Builder *jsonComponent = new ComponentBuilder();  // 初始化Builder
    jsonComponent->buildComponent(jsonStr);  // 使用Builder构建Json文件的组合模式树形结构
    FunnyJsonExplorer *fje;
    // 根据参数指定的风格确定要打印的风格
    if (style == "tree") {
        fje = new TreeFactory(jsonComponent->getJson()->componentRoot);
    } else if (style == "rectangle") {
        fje = new RectangleFactory(jsonComponent->getJson()->componentRoot);
    } else {
        cout << "undefined style" << endl;
        return 0;
    }
    // 指定图标族
    fje->show(icon1, icon2);
    return 0;
}
