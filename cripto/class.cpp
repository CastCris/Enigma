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
                if(mudan[0]>126){
                    mudan[0]-=126;
                    for(int i=1;i<mudan.size();++i){
                        if(mudan[i]>126){
                            mudan[i]-=126*int(mudan[i]/126);
                        }else{
                            break;
                        }
                    }
                }
                for(int i=0;i<r.size();++i){
                    cara=r[i][cara];
                }
                for(int i=r.size()-1;i>-1;--i){
                    cara=r[i][cara];
                }
                output.push_back(cara);
                r.clear();
            }
            return output;
        };
    private:
        std::vector<std::map<char, char>> r;
        void rotor(){
            int splep=0, v1=0,v2=0, dis_char;
            for(int index=0;index<mudan.size();index++){
                r.push_back({});
                for(int letra=33;letra<126;++letra){
                    splep=letra;
                    splep+=mudan[index];
                    if(splep>126){
                        splep=splep-126*int(splep/93)+32;
                    }
                    if(criptar){
                        v1=letra;
                        v2=splep;
                    } else{
                        v1=splep;
                        v2=letra;
                    }
                    r[index].insert(std::pair<char, char>{char(v1),char(v2)});
                }
            }
        }
};
// 
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
        std::cin>>bo;
        (bo==1)?trem.criptar=true:trem.criptar=false;
        std::cout<<trem.cifra()<<std::endl;
        trem.mudan.clear();
    }
    return 0;
}