#include<bits/stdc++.h>
#include"lexer.h"
#include<fstream>
#include<cctype>
#include"Parser.cpp"
#include"codeGenerator.cpp"


std::vector<lexer> tokenize(std::string& sourcecode){

    std::vector<lexer> tokens;
    int currentChar=0;
    std::string reservedKeyWord[]={"summonsoul","chant"};

    while(currentChar<sourcecode.length()){
        //if the current character is space or tab , skip it.
        if(sourcecode[currentChar]==' ' || sourcecode[currentChar]=='\t'){
            currentChar++;
            continue;
        }
        else if(std::isdigit(sourcecode[currentChar])){
            //if the current character is a digit
            std::string number="";
            while(std::isdigit(sourcecode[currentChar])){
                number+=sourcecode[currentChar];
                currentChar++;
            }
            tokens.push_back({TokenType::Identifier,number});
            continue;
        }
        else if(sourcecode[currentChar]=='='){
            tokens.push_back({TokenType::Assignment,"="});
            currentChar++;
            continue;
        }
        else if(sourcecode[currentChar]=='+'){
            tokens.push_back({TokenType::Plus,"+"});
            currentChar++;
            continue;
        }
        else if(sourcecode[currentChar]=='-'){
            tokens.push_back({TokenType::Minus,"-"});
            currentChar++;
            continue;
        }
        else if(sourcecode[currentChar]=='*'){
            tokens.push_back({TokenType::Multiply,"*"});
            currentChar++;
            continue;
        }
        else if(sourcecode[currentChar]=='/'){
            tokens.push_back({TokenType::Divide,"/"});
            currentChar++;
            continue;
        }
        else if(sourcecode[currentChar]=='('){
            tokens.push_back({TokenType::LParen,"("});
            currentChar++;
            continue;
        }
        else if(sourcecode[currentChar]==')'){
            tokens.push_back({TokenType::RParen,")"});
            currentChar++;
            continue;
        }
        else if(isalpha(sourcecode[currentChar])){
            //if the current character is a letter
            std::string identifier="";
            while(isalpha(sourcecode[currentChar]) || std::isdigit(sourcecode[currentChar])){
                identifier+=sourcecode[currentChar];
                currentChar++;
            }
            if(std::find(std::begin(reservedKeyWord),std::end(reservedKeyWord),identifier)!=std::end(reservedKeyWord)){
                tokens.push_back({TokenType::Keyword,identifier});
            }
            else{
                tokens.push_back({TokenType::Identifier,identifier});
            }
            continue;
        }
        else {
            if(sourcecode[currentChar]==';'){
                tokens.push_back({TokenType::Eol,";"});
                currentChar++;
                continue;
            }
        
        }
        



    }

    return tokens;



}




