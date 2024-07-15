#include <iostream>
#include <stdio.h>
#include <cstring>
// 
int main(){
    std::string inp, help,out;
    char *dividir;
    // 
    std::cout<<" ________            __                                   "<<std::endl;
    std::cout<<"/        |          /  |                                  "<<std::endl;
    std::cout<<"$$$$$$$$/  _______  $$/   ______   _____  ____    ______  "<<std::endl;
    std::cout<<"$$ |__    /       /_/  | /      /_ /   /_/   /_ /       /_"<<std::endl;
    std::cout<<"$$    |   $$$$$$$  |$$ |/$$$$$$  |$$$$$$ $$$$  | $$$$$$  |"<<std::endl;
    std::cout<<"$$$$$/    $$ |  $$ |$$ |$$ |  $$ |$$ | $$ | $$ | /    $$ |"<<std::endl;
    std::cout<<"$$ |_____ $$ |  $$ |$$ |$$ |__$$ |$$ | $$ | $$ |/$$$$$$$ |"<<std::endl;
    std::cout<<"$$       |$$ |  $$ |$$ |$$    $$ |$$ | $$ | $$ |$$    $$ |"<<std::endl;
    std::cout<<"$$$$$$$$/ $$/   $$/ $$/  $$$$$$$ |$$/  $$/  $$/  $$$$$$$/ "<<std::endl;
    std::cout<<"                        /  /__$$ |                        "<<std::endl;
    std::cout<<"                         $$    $$/                         "<<std::endl;
    std::cout<<"                         $$$$$$/                          "<<std::endl;
    std::cout<<"\nPara mais informações, digite info\nPara ascessar o manual, digite m\nPara iniciar a Enigma, digite e\nPara obter ajuda com os comandos, digite h seguido pelo comando\nPor fim, para finalizar o processo, digite p\n";
    while(true){
        std::cin>>inp;
        if(inp=="info"){
            std::cout<<"BOB";
        } else if(inp=="m"|inp=="M"){
            std::cout<<"-------Manual-------\nEscolha algum dos items:\n1-Manipulação do histórico\n2-Entrada de valores\n";
            inp.clear();
            std::cout<<"*-M ";
            std::cin>>inp;
            if(inp=="1"){
                std::cout<<"-------Manipulação do histórico-------\nDurante a execução do programa, o algoritimo salva os seus dados de forma que, após o termino do programa, estes possam ser salvos em um arquivo .txt. Para ascessar o histórico local, isto é, aquele que ainda não foi gravado, basta utilizar o comando: hl. Caso contrário, para ascessar o histórico global use hg\nCom o ascesso à algum dos históricos acima, é possível editá-los e/ou visualiza-lós através dos seguintes comandos:\nv->Visualiza o conteúdo do histórico\nex->Exclui uma ou mais linhas desejadas\ni->insere elementos no histórico\n\nNota: Caso o programa seja forçado a parar ou ocorra erros durante a sua execução, os dados salvos localmente serão perdidos\n";
            } else if(inp=="2"){
                std::cout<<"-------Entrada-------\nA primeira entrada é composta pela mensagem a ser criptograda/descriptograda. Os caracteres devem ter valores >32 e <123 da tabela ASCII exeto pelo espaço.\nA segunda entrada consiste nos plugins. Para cada caracter não pode haver um que se repita mais de 1 vez, obedecem à primeira regra de valores ASCII e devem se interligados à um outro caracter por um hífen\nA terceira entrada consiste nos rotores. Os valores dos rotores não podem ser <0 e >89, cada espaço entre os valores, será interpretado como um rotor distinto\nA última entrada consiste no modo(0/1). Para uma mensagem criptografada no modo 1, a mensagem deve ser descriptograda no modo 0 e vice-versa.\n";
            } else{
                std::cout<<"Inválido, tente novamente";
            }
        } else if(inp[0]=='h'|inp[0]=='H'){
            dividir=std::strtok(&inp[0],NULL);
            for(int i=0;dividir!=NULL;++i){
                (i>0)?help=std::to_string(*dividir):help;
            }
            if(help=="v"){
                out="v->Visualiza o histórico selecionado\nEX: *hl: v\n########################Sun Jul 14 22:59:59 2024\nTexto: CFI\nRotor: 1\nPlugin:(nada)\nModo: 0\n";
            } else if(help=="hl"){
                // A escrever
            } else if(help=="hg"){
                // A escrever
            } else if(help=="m"|help=="M"){
                // A escrever
            } else if(help=="ex"){
                // A escrever
            } else if(help=="i"){
                // A escreber
            } else if(help=="e"|help=="E"){
                // A escrever
            } else if(help=="i"|help=="I"){
                // A escrever
            } else{
                out="Tente novamente";
            }
            std::cout<<out<<std::endl;
            out.clear();
        }
    }
    inp.clear();
}