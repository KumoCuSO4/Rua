// 词法分析

#include <fstream>
#include "isingleton.hpp"
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

// # define UCHAR_MAX (__SCHAR_MAX__ * 2 + 1)
# define FIRST_RESERVED	(UCHAR_MAX + 1)
# define DEBUG_LEX
typedef void (*FunctionPtr)();

class RLex : public ISingleton<RLex> {

public:
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
    const unordered_map<string, int> tokensMap = {
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

    unordered_set<char> whiteSpace = { ' ', '\t', '\f', '\v' };
    unordered_set<char> newLine = { '\r', '\n' };

    struct Token {
        int tid;
        string tinfo;
    };

    Token GetToken(string str) {
        auto it = tokensMap.find(str);
        if (it != tokensMap.end()) {
            return { it->second, "" };
        }
        return { RESERVED::TK_NAME, str };
    }

private:
    struct IOStatus {
        int lineNum;
        int inLinePos;
    };

    void inline AddToken(IOStatus* iostatus, Token token, vector<Token> &tokens) {
        tokens.push_back(token);
#ifdef DEBUG_LEX
        
        if (token.tid < SCHAR_MAX) {
            cout << iostatus->lineNum << " " << iostatus->inLinePos << " " << (char)token.tid << " " << token.tinfo << endl;
        }
        else {
            cout << iostatus->lineNum << " " << iostatus->inLinePos << " " << token.tid << " " << token.tinfo << endl;
        }
#endif
    }

    void inline StrToToken(IOStatus *iostatus, string &str, vector<Token> &tokens) {
        if (str.length() > 0) {
            AddToken(iostatus, GetToken(str), tokens);
            str = "";
        }
    }

public:
    
    vector<Token> ReadStr(string str) {
        vector<Token> tokens;
        return tokens;
    }

    
    vector<Token> ReadFile(string fileName) {
        ifstream file(fileName);
        vector<Token> tokens;

        if (file.is_open()) {
            char c;
            IOStatus *iostatus = new IOStatus();
            memset(iostatus, 0, sizeof(IOStatus));
            while (file.get(c)) {
                iostatus->inLinePos++;
                //cout << c << " " << isalpha(c) << endl;
                if (newLine.count(c) > 0) { //换行
                    iostatus->lineNum++;
                    iostatus->inLinePos = 0;
#ifdef DEBUG_LEX
                    cout << "new line" << endl;
#endif
                }
                else if (whiteSpace.count(c) > 0) {
#ifdef DEBUG_LEX
                    cout << iostatus->lineNum << " " << iostatus->inLinePos << " " << "ws" << endl;
#endif
                }
                else {
                    if (c == '-') {  // 判断是负号'-' 还是注释'--'
                        char nextc = file.peek();
                        if (nextc != '-') {
                            AddToken(iostatus, { (int)c, "" }, tokens);
                        }
                        else {
                            file.get();
                            nextc = file.peek();
                            if (nextc == '[') {  // 长注释
                                // read long comment
                            }
                            else { // 注释
                                while (file.get(nextc)) {
                                    if (newLine.count(nextc) > 0) { //换行
                                        iostatus->lineNum++;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else if (c == '[') {

                    }
                    else if (c == '=') {

                    }
                    else if (c == '<') {

                    }
                    else if (c == '>') {

                    }
                    else if (c == '/') {

                    }
                    else if (c == '~') {

                    }
                    else if (c == ':') {

                    }
                    else if (c == '"' || c == '\'') {  // string

                    }
                    else if (c == '.') {  // '.' '..' '...'

                    }
                    else if (isalnum(c)) {  // 数字

                    }
                    else if (isalpha(c) || c=='_') {  // name或多字符关键字
                        string str = "";
                        str = str + c;
                        while (file.get(c)) {
                            if (isalpha(c) || c == '_' || isalnum(c)) {
                                str = str + c;
                                file.get();
                            }
                            else {
                                file.seekg(-1, std::ios_base::cur);
                                break;
                            }
                        }
                        cout << str << endl;
                        StrToToken(iostatus, str, tokens);
                    }
                    else {  // 单字符关键字
                        AddToken(iostatus, { (int)c, "" }, tokens);
                    }
                }
            }
            file.close();
            delete iostatus;
        }
        else {
            cout << "无法打开文件"+fileName << endl;
        }
        
        return tokens;
    }

};