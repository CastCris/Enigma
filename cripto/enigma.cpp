/*
Para cada caso de teste, não é permitido colocar um número maior que 88, senão ele será subtraido até dar um número menor que 89.
O limite do tamanho da mensagem é ilimitado, porém, algumas palavras podem vim erradas, mas não o suficiente para deixar o texto ilégivel
*/
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
// 
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
// 
#include <chrono>
#include <ctime>
// 
class history{
    public:
        inline void armazenar(std::string letrinhas, std::string rotores, std::string alteracoes,bool modo){
            std::time_t hora = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            his_store.push_back({});
            // 
            std::string modo_1;
            int tam=his_store.size()-1;
            (modo)?modo_1="1":modo_1="0";
            // 
            his_store[tam].push_back(std::ctime(&hora));
            his_store[tam].push_back(letrinhas);
            his_store[tam].push_back(rotores);
            his_store[tam].push_back(alteracoes);
            his_store[tam].push_back(modo_1);
        }
        inline ~history(){
            std::ofstream historico("historico.txt",std::ios::app);
            for(int tam=0;tam<int(his_store.size()/2);++tam){
                auto aux=his_store[tam];
                his_store[tam]=his_store[his_store.size()-tam-1];
                his_store[his_store.size()-tam-1]=aux;
            }
            for(auto ponte:his_store){
                historico<<"########################\n";
                for(int ponte1=0;ponte1<=ponte.size();++ponte1){
                    std::cout<<ponte[ponte1]<<std::endl;
                    if(ponte1==0){
                        historico<<ponte[ponte1];
                    }else if(ponte1==1){
                        historico<<"Texto: "<<ponte[ponte1]<<std::endl;;
                    } else if(ponte1==2){
                        historico<<"Rotor: "<<ponte[ponte1]<<std::endl;
                    } else if(ponte1==3){
                        historico<<"Plugin: "<<ponte[ponte1]<<std::endl;
                    } else if(ponte1==4){
                        historico<<"Modo: "<<ponte[ponte1]<<std::endl;
                    }
                }
            }
            historico.close();
        }
    private:
        std::vector<std::vector<std::string>> his_store;
        inline bool exist(){
            std::string nome="historico";
            struct stat analisar;
            return (stat (nome.c_str(),&analisar)==0);
        }
};
class enigma: public history{
    public:
        bool criptar;
        std::string word, plugin,mudan_str;
        std::string misterio(){
            redire = new std::map<char,char>;
            mudan_int= new std::vector<int>;
            // 
            plu();
            armazenar(word,mudan_str,plugin,criptar);
            // 
            char*separar=std::strtok(&mudan_str[0]," ");
            while(separar!=NULL){
                mudan_int->push_back(atoi(separar));
                separar=std::strtok(NULL," ");
            }
            // 
            auto retornar= cifra(*mudan_int,word,*redire);
            // 
            delete redire, mudan_int;
            redire=NULL;
            mudan_int=NULL;
            return retornar;
        }
    private:
        std::vector<std::map<char, char>>*r;
        std::vector<int> *mudan_int;
        std::map<char, char>* redire;
        // 
        void rotor(std::vector<int> giragira,int max){
            int splep=0, v1=0,v2=0;
            for(int index=0;index<max;index++){
                r->operator[](index).clear();
                r->insert(r->begin()+index,{});
                for(int letra=0;letra<90;++letra){
                    splep=giragira[index]+33+letra;
                    (splep>122)?splep-=90*int(splep/122):splep;
                    if(criptar){
                        v1=letra+33;
                        v2=splep;
                    } else{
                        v1=splep;
                        v2=letra+33;
                    }
                    r->operator[](index).insert(std::pair<char,char>(v1,v2));
                }
            }
        }
        int plu(){
            std::string temp;
            char *dividir=std::strtok(&plugin[0]," ");
            while(dividir!=NULL){
                temp=dividir;
                if(temp.length()==3){
                    redire->operator[](temp[0])=temp[2];
                }
                dividir=std::strtok(NULL," ");
            }
            return 0;
        }
        std::string cifra(std::vector<int> girar, std::string letter, std::map<char,char> gin){
            r=new std::vector<std::map<char,char>>(girar.size());
            std::string output="";
            char cara;
            int quant=girar.size();
            for(char ll:letter){
                cara=ll;
                rotor(girar,quant);
                ++girar[0];
                if(girar[0]>88){
                    quant=0;
                    for(int contro=0;girar[contro]>88;++contro){
                        girar[contro]-=88*int(girar[contro]/88);
                        (contro+1<girar.size())?++girar[contro+1]:girar[contro];
                        if(contro>=girar.size()){
                            break;
                        }
                        ++quant;
                    }
                    std::cout<<std::endl;
                } else{
                    quant=1;
                }
                for(int emb=0;emb<r->size();++emb){
                    if(!criptar){
                        if(gin.find(cara)!=gin.end()){
                            cara=gin[cara];
                        } else{
                            for(auto andar:gin){
                                if(andar.second==cara){
                                    cara=andar.first;
                                    break;
                                }
                            }
                        }
                    }
                    cara=r->operator[](emb)[cara];
                    if(criptar){
                        if(gin.find(cara)!=gin.end()){
                            cara=gin[cara];
                        } else{
                            for(auto andar:gin){
                                if(andar.second==cara){
                                    cara=andar.first;
                                    break;
                                }
                            }
                        }
                    }
                }
                for(int emb=r->size()-1;emb>-1;--emb){
                    if(!criptar){
                        if(gin.find(cara)!=gin.end()){
                            cara=gin[cara];
                        } else{
                            for(auto andar:gin){
                                if(andar.second==cara){
                                    cara=andar.first;
                                    break;
                                }
                            }
                        }
                    }
                    cara=r->operator[](emb)[cara];
                    if(criptar){
                        if(gin.find(cara)!=gin.end()){
                            cara=gin[cara];
                        } else{
                            for(auto andar:gin){
                                if(andar.second==cara){
                                    cara=andar.first;
                                    break;
                                }
                            }
                        }
                    }
                }
                (int(cara)<33|int(cara)>122)?output.push_back('!'):output.push_back(cara);
            }
            delete r;
            r=NULL;
            return output;
        };
};
// Caso de teste
int main(){
    enigma trem;
    std::string coiso;
    int bo;
    while(true){
        std::cin>>trem.word;
        if(trem.word=="p"){
            break;
        }
        // 
        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');
        // 
        std::getline(std::cin,coiso);
        trem.mudan_str=coiso;
        std::cout<<"-----------"<<std::endl;
        std::getline(std::cin,trem.plugin);
        std::cout<<"-----------"<<std::endl;
        std::cin>>bo;
        (bo==1)?trem.criptar=true:trem.criptar=false;
        std::cout<<trem.misterio()<<std::endl;
        trem.mudan_str.clear();
        trem.word.clear();
    }
    return 0;
}