// 词法分析
class RLex {
    static constexpr char *const tokens[] = {
        "and", "break", "do", "else", "elseif",
        "end", "false", "for", "function", "goto", "if",
        "in", "local", "nil", "not", "or", "repeat",
        "return", "then", "true", "until", "while", "continue",
        "//", "..", "...", "==", ">=", "<=", "~=", "!=",
        "<<", ">>", "::", "<eof>",
        "<number>", "<integer>", "<name>", "<string>",
        "def", "auto", "bool", "int", "float", "double", "string"
    };
};
