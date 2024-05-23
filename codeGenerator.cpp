// CodeGeneration.h
#ifndef CODEGENERATION_H
#define CODEGENERATION_H

#include "AST.cpp"
#include <vector>
#include <string>
#include<cctype>

//Basic code generator obviously in production we cannot do like that but it will work.
//It is what it is :(

std::string codeGeneration(const std::vector<std::shared_ptr<ASTNode>> &ast) {
    std::string code = "#include <iostream>\n\n";
    code += "int main() {\n";

    for (const auto& stmt : ast) {
        if (auto varDecl = std::dynamic_pointer_cast<ASTVarDecl>(stmt)) {
            if (varDecl->varName == "NULL") {
                code += "    std::cout << " + varDecl->expression + ";\n";
            } else {
                code += "    int " + varDecl->varName + " = " + varDecl->expression + "\n";
            }
        }
    }

    code += "    return 0;\n";
    code += "}\n";
    
    return code;
}

#endif // CODEGENERATION_H

