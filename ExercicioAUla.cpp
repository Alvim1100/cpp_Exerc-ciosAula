#include <iostream>
using namespace std;

string nome[50];
int matricula[50];
float nota1[50];
float nota2[50];
float nota3[50];
float media[50];
int i = 0;
int o = 0;
int op = 0;

void adicionaaluno(){
    cout << "CADASTRO" << endl << endl;
    cout << "Digite seu nome: " << endl;
    cin >> nome[i];
        
    cout << "Digite sua matricula: " << endl;
    cin >> matricula[i];

    cout << "Digite suas 3 notas em sequencia: " << endl;
    cin >> nota1[i];
    cin >> nota2[i];
    cin >> nota3[i];

    i++;
}

void listaalunos(){
    while(o < i){
        media[o] = (nota1[o]+nota2[o]+nota3[o])/3;
        cout << endl;
        cout << "Nome: " << nome[o] << endl;
        cout << "Matricula: " << matricula[o] << endl;
        cout << "Media: " << media[o] << endl;
            
        if(media[o] < 7){
            cout << "REPROVADO";
        }else{
            cout << "APROVADO";
        }
        cout << endl << endl;
        o++;
    }
}

void menu(){
    while(op != 3){
        cout << "MENU" << endl << "1- Adicionar um aluno " << endl << "2- Listar os alunos " << endl << "3- Parar o programa " << endl;
        cout << "Digite sua opcao: ";
        cin >> op;

        if(op == 1){
            adicionaaluno();
        }else if(op == 2){
            o = 0;
            listaalunos();
        }else{
            cout << "Obrigado por usar meu software!";
            break;
        }
    }
}


int main(){
    menu();    
}
    
    
    