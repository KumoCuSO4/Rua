#include "rlex.cpp"

int main(int argc, char *argv[]) {
    system("chcp 65001");
    RLex *rlex = RLex::GetInstance();
    rlex->ReadFile("C:\\Users\\MOLGY\\Desktop\\Rua\\test.rua");

    return 0;
}