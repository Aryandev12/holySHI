#include"lexer.cpp"

int main(int argc, char const *argv[]){

    //reading arguments from terminal.
    std::string sourcecode="";
    if(argc!=2){
        std::cerr<<"Error: Invalid number of arguments."<<std::endl;
        std::cerr<<"Usage: ./lexer <filename>"<<std::endl;
        return 1;
    }

    std::string filename=argv[1];
    //checking the extension of the file .
    if(filename.find(".hshi")==std::string::npos){
        std::cerr<<"Error: Invalid file extension. Please use .hshi extension."<<std::endl;
        return 1;
    }

    //opening the file
    std::fstream file;
    file.open(filename,std::ios::in);
    if(!file){
        std::cerr<<"Error: File not found."<<std::endl;
        return 1;
    }

    //reading the file
    std::string line;
    while(getline(file,line)){
        sourcecode+=line;
    }
    // std::cout<<sourcecode<<std::endl;
    //closing the file
    file.close();
     //now its time to tokenize the  source code.
    std::vector<lexer> tokens;
     tokens =tokenize(sourcecode);
    
    Parser parser(tokens);
    std::vector<std::shared_ptr<ASTNode>> ast = parser.parse();
    std::string executableCode = codeGeneration(ast);
    // std::cout<<executableCode<<std::endl;

       // Write the generated code to a file
    std::ofstream outFile("generated_code.cpp");
    if (outFile.is_open()) {
        outFile << executableCode;
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
        return 1;
    }

    // Compile the generated code
    if (system("g++ -o generated_code generated_code.cpp") != 0) {
        std::cerr << "Compilation failed.\n";
        return 1;
    }

    // Run the compiled code
    if (system("./generated_code") != 0) {
        std::cerr << "Execution failed.\n";
        return 1;
    }

    // Delete the generated code file
    if (remove("generated_code.cpp") != 0) {
        std::cerr << "Failed to delete generated code file.\n";
        return 1;
    }


    



   











    return 0;


}
