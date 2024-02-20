// 词法分析

#include <map>
#include <fstream>
#include "utils/isingleton.cpp"
#include <vector>
#include <iostream>
using namespace std;

# define UCHAR_MAX (__SCHAR_MAX__ * 2 + 1)
# define FIRST_RESERVED	(UCHAR_MAX + 1)

class RLex : ISingleton<RLex> {
    // 保留字 从UCHAR_MAX后开始为了区别于所有单字符的关键字 （单字符如‘+’将直接对应他的ascii值）
    enum RESERVED {
        /* terminal symbols denoted by reserved words */
        TK_AND = FIRST_RESERVED, TK_BREAK,
        TK_DO, TK_ELSE, TK_ELSEIF, TK_END, TK_FALSE, TK_FOR, TK_FUNCTION,
        TK_GOTO, TK_IF, TK_IN, TK_LOCAL, TK_NIL, TK_NOT, TK_OR, TK_REPEAT,
        TK_RETURN, TK_THEN, TK_TRUE, TK_UNTIL, TK_WHILE, TK_CONTINUE,
        /* other terminal symbols */
        TK_IDIV, TK_CONCAT, TK_DOTS, TK_EQ, TK_GE, TK_LE, TK_NE,
        TK_SHL, TK_SHR,
        TK_DBCOLON, TK_EOS,
        TK_FLT, TK_INT, TK_NAME, TK_STRING
    };

    // 映射
    const map<const string, const int> tokens = {
        {"and", RESERVED::TK_AND},
        {"break", RESERVED::TK_BREAK},
        {"do", RESERVED::TK_DO},
        {"else", RESERVED::TK_ELSE},
        {"elseif", RESERVED::TK_ELSEIF},
        {"END", RESERVED::TK_END},
        {"false", RESERVED::TK_FALSE},
        {"for", RESERVED::TK_FOR},
        {"function", RESERVED::TK_FUNCTION},
        {"goto", RESERVED::TK_GOTO},
        {"if", RESERVED::TK_IF},
        {"in", RESERVED::TK_IN},
        {"local", RESERVED::TK_LOCAL},
        {"nil", RESERVED::TK_NIL},
        {"not", RESERVED::TK_NOT},
        {"or", RESERVED::TK_OR},
        {"repeat", RESERVED::TK_REPEAT},
        {"return", RESERVED::TK_RETURN},
        {"then", RESERVED::TK_THEN},
        {"true", RESERVED::TK_TRUE},
        {"until", RESERVED::TK_UNTIL},
        {"while", RESERVED::TK_WHILE},
        {"continue", RESERVED::TK_CONTINUE},
        
        {"//", RESERVED::TK_IDIV},
        {"..", RESERVED::TK_CONCAT},
        {"...", RESERVED::TK_DOTS},
        {"==", RESERVED::TK_EQ},
        {">=", RESERVED::TK_GE},
        {"<=", RESERVED::TK_LE},
        {"~=", RESERVED::TK_NE},
        {"!=", RESERVED::TK_NE},
        {"<<", RESERVED::TK_SHL},
        {">>", RESERVED::TK_SHR},
        {"::", RESERVED::TK_DBCOLON},
        {"<eof>", RESERVED::TK_EOS},
        {"<number>", RESERVED::TK_FLT},
        {"<integer>", RESERVED::TK_INT},
        {"<name>", RESERVED::TK_NAME},
        {"<string>", RESERVED::TK_STRING},
        //"def", "auto", "bool", "int", "float", "double", "string"
    };

    typedef int Token;

    vector<Token> ReadStr(string str) {
        vector<Token> tokens;
        return tokens;
    }

    vector<Token> ReadFile(string fileName) {
        ifstream file(fileName);
        if (file.is_open()) {
            string content;

            string line;
            while (getline(file, line)) {
                content += line + "\n";
            }

            file.close();

            cout << "文件内容：" << endl;
            cout << content << std::endl;
        }
        else {
            cout << "无法打开文件" << endl;
        }
        vector<Token> tokens;
        return tokens;
    }

};