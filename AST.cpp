#ifndef AST_H
#define AST_H

#include <string>
#include <memory>

class ASTNode {

public:
    std::vector<std::shared_ptr<ASTNode>> body;
    virtual ~ASTNode() = default;
    
};

class ASTVarDecl : public ASTNode {
public:
    std::string varName;
    std::string type;
    std::string expression;

    ASTVarDecl(const std::string &name, std::string type, const std::string &expr)
        : varName(name), type(type), expression(expr) {}
    

};

#endif // AST_H
