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
        std::string word;
        std::vector<int> mudan;
        std::map<char,char> *plugin;
        std::string cifra(){
            std::string output="";
            char cara;
            for(char j:word){
                cara=j;
                rotor();
                ++mudan[0];
                if(mudan[0]>88){
                    mudan[0]-=89*int(mudan[0]/89);
                    mudan[1]+=1;
                    for(int i=1;i<mudan.size();++i){
                        if(mudan[i]>89){
                            mudan[i]-=89*int(mudan[i]/89);
                            mudan[i]+=1;
                        }else{
                            break;
                        }
                    }
                }
                std::cout<<j<<" "<<mudan[0]<<" "<<mudan[1]<<" "<<mudan[2]<<std::endl;
                for(int i=0;i<r.size();++i){
                    cara=r[i][cara];
                    std::cout<<cara<<" ";
                }
                for(int i=r.size()-1;i>=0;--i){
                    cara=r[i][cara];
                    std::cout<<cara<<" ";
                }
                std::cout<<std::endl;
                (int(cara)<33|int(cara)>121)?output.push_back('!'):output.push_back(cara);
                r.clear();
            }
            return output;
        };
    private:
        std::vector<std::map<char, char>> r;
        void rotor(){
            int splep=0, v1=0,v2=0, loc;
            for(int index=0;index<mudan.size();index++){
                r.push_back({});
                for(int letra=0;letra<89;++letra){
                    splep=mudan[index]+33+letra;
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
};
// Caso de teste
// int main(){
//     enigma trem;
//     std::string coiso;
//     int bo;
//     while(true){
//         std::cin>>trem.word;//ESTAMOS-VIVENDO-UM-APOCALIPSE-ZUMBI!
//         // 
//         std::cin.clear();
//         std::cin.ignore(INT_MAX,'\n');
//         // 
//         std::getline(std::cin,coiso);
//         char*split=std::strtok(&coiso[0]," ");
//         for(int i=0;split!=NULL;++i){
//             trem.mudan.push_back(std::stoi(split));
//             split=std::strtok(NULL," ");
//         }
//         std::cout<<"-----------"<<std::endl;
//         std::cin>>bo;
//         (bo==1)?trem.criptar=true:trem.criptar=false;
//         std::cout<<trem.cifra()<<std::endl;
//         trem.mudan.clear();
//     }
//     return 0;
// }