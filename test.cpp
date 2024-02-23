#include "rlex.cpp"

int main(int argc, char *argv[]) {
    system("chcp 65001");
    RLex *rlex = RLex::GetInstance();
    vector<RLex::Token> tokens = rlex->ReadFile("C:\\Users\\MOLGY\\Desktop\\Rua\\test.rua");
    cout << "测试输出" << endl;
    for (int i = 0;i < tokens.size();i++) {
        if (tokens[i].tid < SCHAR_MAX) {
            cout << (char)tokens[i].tid << " " << tokens[i].tinfo << endl;
        }
        else {
            cout << tokens[i].tid << " " << tokens[i].tinfo << endl;
        }

    }
    return 0;
}