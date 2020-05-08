#include<iostream>
#include<fstream>
#include<string>
#include<limits>

using namespace std;

int main(){
    string str;
    int i;
    char c;
    double p;

    ifstream arq("arquivo.txt");
    if(!arq.is_open()){
        cerr << "The file is not open" << endl;
    }

    for(int cont=1; cont<=2; cont++){

        arq >> str;

        if(str=="Livros"||str=="CDs"){
             cout << str;
        }
        else{
            cerr << "Arquivo Corrompido" << endl;
        }

        arq>>i;
        cout << i;

        arq.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int j=1; j<=i; j++){
            arq >> c;
            if(c=='L'||c=='C'){
                cout << c;
            }
            else{
                cerr << "Arquivo Corrompido";
            }

            arq.ignore(numeric_limits<streamsize>::max(), '$');

            arq >> p;
            if(p<=0.0){
                cerr << "Preco inexistente" << endl;
            }
            else{
                cout << p;
            }
            arq.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return 0;
}
