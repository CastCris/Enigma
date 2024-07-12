/*
Para cada caso de teste, não é permitido colocar um número maior que 88, senão ele será subtraido até dar um número menor que 80.
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
class enigma{
    public:
        bool criptar;
        std::string word, plugin;
        std::vector<int> mudan;
        std::string misterio(){
            plu();
            auto retornar= cifra(mudan,word,*redire);
            delete redire;
            redire=NULL;
            redire = new std::map<char,char>;
            return retornar;
        }
    private:
        std::vector<std::map<char, char>> r;
        std::map<char, char>* redire = new std::map<char,char>;
        // 
        void rotor(std::vector<int> giragira,int max){
            int splep=0, v1=0,v2=0;
            for(int index=0;index<max;index++){
                r.push_back({});
                for(int letra=0;letra<89;++letra){
                    splep=giragira[index]+33+letra;
                    (splep>121)?splep-=89*int(splep/121):splep;
                    if(criptar){
                        v1=letra+33;
                        v2=splep;
                    } else{
                        v1=splep;
                        v2=letra+33;
                    }
                    r[index].insert(std::pair<char, char>{char(v1),char(v2)});
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
            std::string output="";
            char cara;
            int quant=girar.size();
            for(char ll:letter){
                cara=ll;
                rotor(girar,quant);
                ++girar[0];
                if(girar[0]>88){
                    girar[0]-=88*int(girar[0]/88);
                    girar[1]+=1;
                    ++quant;
                    for(int i=1;i<girar.size();++i){
                        if(girar[i]>89){
                            girar[i]-=89*int(girar[i]/89);
                            girar[i]+=1;
                        }else{
                            break;
                        }
                        ++quant;
                    }
                } else{
                    quant=1;
                }
                for(int emb=0;emb<r.size();++emb){
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
                    cara=r[emb][cara];
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
                for(int emb=r.size()-1;emb>-1;--emb){
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
                    cara=r[emb][cara];
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
                (int(cara)<33|int(cara)>121)?output.push_back('!'):output.push_back(cara);
                r.clear();
            }
            return output;
        };
};