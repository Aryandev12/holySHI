#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "AST.cpp"
#include <vector>
#include <memory>
#include <stdexcept>
#include <stack> // Include <stack> header for using std::stack

class Parser {
    std::vector<lexer> tokens;
    std::stack<lexer> tokenStack;

public:
    Parser(std::vector<lexer> tokens) : tokens(tokens) {
        for (auto it = tokens.rbegin(); it != tokens.rend(); ++it) {
            tokenStack.push(*it); // Push tokens onto the stack in reverse order
        }
    }

    std::vector<std::shared_ptr<ASTNode>> parse() {
        std::vector<std::shared_ptr<ASTNode>> statements;

        while (!tokenStack.empty()) {
            statements.push_back(parseStatement());
        }

        return statements;
    }

private:
    std::shared_ptr<ASTNode> parseStatement() {
        while (!tokenStack.empty()) {
            auto token = tokenStack.top();
            tokenStack.pop();

            if (token.tokenType == TokenType::Keyword && token.tokenValue == "summonsoul") {
                if (tokenStack.empty()) {
                    throw std::runtime_error("Unexpected end of input after 'summonsoul'");
                }

                std::string varName = tokenStack.top().tokenValue;
                tokenStack.pop();

                if (tokenStack.empty() || tokenStack.top().tokenType != TokenType::Assignment) {
                    throw std::runtime_error("Expected '=' after variable name");
                }
                tokenStack.pop(); // Consume "="

                std::string expression = "";
                while (!tokenStack.empty() && tokenStack.top().tokenType != TokenType::Keyword) {
                    expression += tokenStack.top().tokenValue;
                    tokenStack.pop();
                }

                // if (tokenStack.empty() || tokenStack.top().tokenType != TokenType::Eol) {
                //     throw std::runtime_error("Expected ';' at the end of the statement");
                // }
                // tokenStack.pop(); // Consume ";"

                // std::cout << varName << " = " << expression << std::endl;
                return std::make_shared<ASTVarDecl>(varName, "Declaration", expression);
            }
            if(token.tokenType ==TokenType::Keyword && token.tokenValue == "chant"){
                
                if(tokenStack.top().tokenValue=="("){
                    std::string exp = "";
                    tokenStack.pop();
                    while(tokenStack.top().tokenValue!=")" && !tokenStack.empty()){
                        exp+=tokenStack.top().tokenValue;
                        tokenStack.pop();
                    }
                    tokenStack.pop();
                    // std::cout<<exp<<std::endl;

                    return std::make_shared<ASTVarDecl>("NULL","Print",exp);
  
                }

            }

        
        }

    }
};

#endif // PARSER_H
