#include <iostream>
#include <stdio.h>
#include <cstring>
#include "cripto/enigma.cpp"
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
    std::cout<<"                         / /__$$ |                        "<<std::endl;
    std::cout<<"                         $$    $$/                        "<<std::endl;
    std::cout<<"                         $$$$$$/                          "<<std::endl;
    std::cout<<"\nPara mais informações, digite info\nPara ascessar o manual, digite m\nPara iniciar a Enigma, digite e\nPara obter ajuda com os comandos, digite h seguido pelo comando\nPor fim, para finalizar o processo, digite p\n";
    while(true){
        std::cout<<"* ";
        std::getline(std::cin,inp);
        if(inp=="info"){
            std::cout<<"BOB"<<std::endl;
        } else if(inp=="m"|inp=="M"){
            std::cout<<"-------Manual-------\nEscolha algum dos items:\n1-Manipulação do histórico\n2-Entrada de valores\n";
            inp.clear();
            std::cout<<"*-M ";
            std::cin>>inp;
            if(inp=="1"){
                std::cout<<"-------Manipulação do histórico-------\nDurante a execução do programa, o algoritimo salva os seus dados de forma que, após o termino do programa, estes possam ser salvos em um arquivo .txt. Para visualizar o histórico, utilize o comando vi, caso quira procurar informações no histórico, utiliza o comando procurar seguido pelo item de busca(Horário, texto, rotor(es),plugin(s) e modo)\n"<<std::endl;
            } else if(inp=="2"){
                std::cout<<"-------Entrada-------\nA primeira entrada é composta pela mensagem a ser criptograda/descriptograda. Os caracteres devem ter valores >32 e <123 e !=95('_') da tabela ASCII exeto pelo espaço.\nA segunda entrada consiste nos plugins. Para cada caracter não pode haver um que se repita mais de 1 vez, obedecem à primeira regra de valores ASCII e devem se interligados à um outro caracter por um hífen\nA terceira entrada consiste nos rotores. Os valores dos rotores não podem ser <0 e >89, cada espaço entre os valores, será interpretado como um rotor distinto\nA última entrada consiste no modo(0/1). Para uma mensagem criptografada no modo 1, a mensagem deve ser descriptograda no modo 0 e vice-versa.\n"<<std::endl;
            } else{
                std::cout<<"Inválido, tente novamente"<<std::endl;
            }
        } else if(inp[0]=='h'|inp[0]=='H'){
            dividir=std::strtok(&inp[0]," ");
            dividir=std::strtok(NULL," ");
            std::cout<<dividir<<std::endl;
            help=dividir;
            if(help=="vi"){
                out="vi->Visualiza o históric\nEX: *: v\n########################Sun Jul 14 22:59:59 2024\nTexto: CFI\nRotor: 1\nPlugin:(nada)\nModo: 0\n";
            } else if(help=="proc"){
                out="proc->Após a sua inserção, digite um ous mais parâmetros a serem pesquisado no histório\nH|h->Horário\nT|t->Texto\nR|r->Rotor\nP|p->plugin\nM|m->modo";
            } else if(help=="e"){
                out="e|E->Inicia a Enigma até o input texto for igual à p.Após o seu termino, o histórico é automaticamente salvo em um arquivo .txt";
            } else if(help=="p"|help=="P"){
                out="p|P->Interrompe a operação da interação";
            }else{
                out="Inválido, tente novamente";
            }
            std::cout<<out<<std::endl;
            out.clear();
            help.clear();
        } else if(inp=="e"|inp=="E"){
            enigma* entrada;
            std::string entrada_1;
            bool ver=true;
            while(ver){
                entrada=new enigma;
                std::cout<<"E ";
                std::getline(std::cin,entrada_1);
                if(entrada_1=="p"|entrada_1=="P"){
                    ver=false;
                    break;
                }else if(entrada_1=="v"|entrada_1=="V"){
                    entrada->v();
                }else if(entrada_1=="proc"){
                    std::cout<<"P ";
                    std::getline(std::cin,entrada_1);
                    entrada->procurar(entrada_1);
                } else{
                    entrada->word=entrada_1;
                    for(int trem=1;trem<4;++trem){
                        if(trem==1){
                            std::cout<<"R ";
                        }else if(trem==2){
                            std::cout<<"P ";
                        }else if(trem==3){
                            std::cout<<"M ";
                        }
                        std::getline(std::cin,entrada_1);
                        (trem==1)?entrada->mudan_str=entrada_1:(trem==2)?  entrada->plugin=entrada_1:(trem==3)?entrada->vv=entrada_1:0;
                    }
                    std::cout<<"R "<<entrada->misterio()<<std::endl;
                }
                delete entrada;
                entrada=NULL;
            }
        }else if(inp=="p"|inp=="P"){
            break;
        } else{
            std::cout<<"Inválido, tente novamente"<<std::endl;
        }
    }
    inp.clear();
}