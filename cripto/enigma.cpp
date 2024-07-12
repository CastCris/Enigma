/*
Para cada caso de teste, não é permitido colocar um número maior que 88, senão ele será subtraido até dar um número menor que 80.
O limite do tamanho da mensagem é ilimitado, porém, algumas palavras podem vim erradas, mas não o suficiente para deixar o texto ilégivel
*/
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
// 
class enigma{
    public:
        bool criptar;
        std::string word, plugin;
        std::vector<int> mudan;
        std::string misterio(){
            plu();
            return cifra(mudan,word,plus);
        }
    private:
        std::vector<std::map<char, char>> r;
        std::map<char, char> plus;
        void rotor(std::vector<int> giragira){
            int splep=0, v1=0,v2=0;
            for(int index=0;index<giragira.size();index++){
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
                    (criptar)?plus[temp[0]]=temp[2]:plus[temp[2]]=temp[0];
                }
                dividir=std::strtok(NULL," ");
            }
            return 0;
        }
        std::string cifra(std::vector<int> girar, std::string pla, std::map<char,char> gin){
            std::string output="";
            char cara;
            for(char j:pla){
                cara=j;
                rotor(girar);
                ++girar[0];
                if(girar[0]>88){
                    girar[0]-=88*int(girar[0]/88);
                    girar[1]+=1;
                    for(int i=1;i<girar.size();++i){
                        if(girar[i]>89){
                            girar[i]-=89*int(girar[i]/89);
                            girar[i]+=1;
                        }else{
                            break;
                        }
                    }
                }
                for(int emb=0;emb<r.size();++emb){
                    if(!criptar&&int(girar[cara])>32&&int(girar[cara])<122){
                        cara=girar[cara];
                    }
                    cara=r[emb][cara];
                    if(!criptar&&int(girar[cara])>32&&int(girar[cara])<122){
                        cara=girar[cara];
                    }
                }
                for(int emb=r.size()-1;emb>-1;--emb){
                    cara=r[emb][cara];
                    std::cout<<cara<<std::endl;
                }
                (int(cara)<33|int(cara)>121)?output.push_back('!'):output.push_back(cara);
                r.clear();
            }
            plus.clear();
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
        // 
        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');
        // 
        std::getline(std::cin,coiso);
        char*split=std::strtok(&coiso[0]," ");
        for(int i=0;split!=NULL;++i){
            trem.mudan.push_back(std::stoi(split));
            split=std::strtok(NULL," ");
        }
        std::cout<<"-----------"<<std::endl;
        std::getline(std::cin,trem.plugin);
        std::cout<<"-----------"<<std::endl;
        std::cin>>bo;
        (bo==1)?trem.criptar=true:trem.criptar=false;
        std::cout<<trem.misterio()<<std::endl;
        trem.mudan.clear();
    }
    return 0;
}