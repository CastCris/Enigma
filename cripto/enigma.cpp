#include <iostream>
#include <map>
#include <vector>
// 
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
            std::string modo_1, horas;
            int tam=his_store.size()-1;
            // 
            char*horahora=std::strtok(std::ctime(&hora)," ");
            while(horahora!=NULL){
                horas+=horahora;
                horas+='_';
                horahora=std::strtok(NULL," ");
            }
            his_store[tam].push_back("Horario: "+horas);
            his_store[tam].push_back("Texto: "+letrinhas);
            his_store[tam].push_back("Rotor(es): "+rotores);
            his_store[tam].push_back("Plugin(s): "+alteracoes);
            (modo)?modo_1="1":modo_1="0";
            his_store[tam].push_back("Modo: "+modo_1);
        }
        ~history(){
            std::fstream his_file("historico.txt",std::ios::app);
            for(auto file_1:his_store){
                his_file<<"###############################"<<std::endl;
                for(int file_2=0;file_2<file_1.size();++file_2){
                    his_file<<file_1[file_2]<<std::endl;
                }
            }
        }
        void v(){
            std::fstream his_file("historico.txt",std::ios::in);
            std::string linha,outt;
            int e=0;
            while(std::getline(his_file,linha)){
                std::cout<<e+1<<" "<<linha<<std::endl;
                ++e;
            }
            for(auto store_1:his_store){
                for(int store_2=0;store_2<store_1.size();++store_2){
                    (store_2==0)?outt="Horario: ":(store_2==1)?outt="Texto: ":(store_2==2)?outt="Rotor(es): ":(store_2==3)?outt="Plugin(s)":(store_2==4)?outt="Modo: ":outt;
                    outt+=store_1[store_2];
                    std::cout<<e+1<<" "<<outt<<std::endl;
                    ++e;
                }
            }
        }
        int procurar(std::string inp){
            char*separar=std::strtok(&inp[0]," ");
            std::vector<std::string> elemtes;
            while(separar!=NULL){
                elemtes.push_back(separar);
                separar=std::strtok(NULL, " ");
            }
            delete separar;
            separar=NULL;
            separar=new char;
            std::ifstream his_file("historico.txt");
            std::vector<std::string> achei;
            std::string linha;
            while(std::getline(his_file,linha)){
                separar=std::strtok(&linha[0]," ");
                for(std::string proc:elemtes){
                    if(separar==proc+':'){
                        separar=std::strtok(NULL," ");
                        achei.push_back(separar);
                    }
                }
            }
            for(auto store_1:his_store){
                for(auto stotre_2:store_1){
                    separar=std::strtok(&stotre_2[0]," ");
                    for(auto proc:elemtes){
                        if(separar==proc+':'){
                            separar=std::strtok(NULL," ");
                            achei.push_back(separar);
                        }
                    }
                }
            }
            for(int recolocar=0;recolocar<achei.size();++recolocar){
                for(int recolocar_1=0;recolocar_1<achei[recolocar].length();++recolocar_1){
                    if(int(achei[recolocar][recolocar_1])==95){
                        std::cout<<" ";
                    } else{
                        std::cout<<achei[recolocar][recolocar_1];
                    }
                }
                std::cout<<std::endl;
            }
            return 0;
        }
        private:
        std::vector<std::vector<std::string>>his_store;
};
class enigma: public history{
    public:
        bool criptar;
        std::string word, plugin,mudan_str;
        std::string misterio(){
            std::string mudan_str_;
            redire = new std::map<char,char>;
            mudan_int= new std::vector<int>;
            entry=new std::string;
            // 
            plu();
            // 
            char*separar=std::strtok(&mudan_str[0]," ");
            while(separar!=NULL){
                mudan_int->push_back(atoi(separar));
                mudan_str_+=separar;
                mudan_str_+='_';
                separar=std::strtok(NULL," ");
            }
            // 
            for(char charecter:word){
                (int(charecter)<33|int(charecter)>122)?entry->push_back('_'):entry->push_back(charecter);
            } 
            armazenar(*entry,mudan_str_,plugin,criptar);
            // 
            auto retornar= cifra(*mudan_int,*entry,*redire);
            // 
            delete redire, mudan_int,entry;
            redire=NULL;
            mudan_int=NULL;
            entry=NULL;
            return retornar;
        }
    private:
        std::string *entry;
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
                (int(cara)<33|int(cara)>122)?output.push_back('!'):(int(cara)==95)?output.push_back(' '):output.push_back(cara);
            }
            delete r;
            r=NULL;
            return output;
        };
};