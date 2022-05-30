#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

/*
Faça um sistema para controlar a fila de vacinas para covid em um posto de saude. O sistema deve ter as seguintes opções:

- Adicionar na fila
  - Pergunta se é primeira dose, segunda dose, ou reforço.
    - Primeira dose: sorteia entre cornavac, pfizer, astrazeneca ou Janssen. Adiciona na respectiva fila de espera.
    - Segunda dose: Pergunta qual foi a primeira dose e adiciona na respectiva fila. JANSSEN não tem segunda dose.
    - Reforço: Todos os reforços são com a pfizer.

- Aplicar vacina
    - Pergunta qual a vacina deseja aplicar e remove um paciente da respectiva fila.

- Status das Filas
  - Mostra a quantidade de pessoas aguardando para cada tipo de vacina

- Sair
  - Encerra o sistema desde que não haja ninguém nas filas esperando vacina.

*/
int opmenu;
int coronavac = 0;
int pfizer = 0;
int astrazenica = 0;
int janssen = 0;
int sortvacina;

void mainmenu(){
    cout << "       MENU" << endl << 
    "|1-Adicionar na fila |" << endl << 
    "|2-Aplicar vacina    |" << endl <<
    "|3-Status da fila    |" << endl << 
    "|4-Sair              |" << endl;
}

void menudose(){
    cout << endl <<  "       DOSE" << endl << 
    "|1-Primeira dose     |" << endl << 
    "|2-Segunda dose      |" << endl <<
    "|3-Reforco           |" << endl << 
    "|4-Sair              |" << endl;
}

void menuvacinas(){
    cout <<
    "|1-Coronavac         |" << endl << 
    "|2-Pfizer            |" << endl <<
    "|3-Astrazenica       |" << endl << 
    "|4-Janssen           |" << endl;
}

void menuaplicarvac(){
    cout << endl <<  "Qual vacina voce deseja aplicar?" << endl << 
    "|1-Coronavac         |" << endl << 
    "|2-Pfizer            |" << endl <<
    "|3-Astrazenica       |" << endl << 
    "|4-Janssen           |" << endl;
}
void statusfilas(){
    cout << endl << "STATUS DA FILA" << endl << "Coronavac: " << coronavac << endl << "Pfizer: " << pfizer << endl << "Astrazenica: " << astrazenica << endl << "Janssen: " << janssen << endl << endl;
}

int main(){
    srand(time(0));
    while(true){
        mainmenu();
        cin >> opmenu;

        if(opmenu == 1){
            menudose();
            cin >> opmenu;

            if(opmenu == 1){
                sortvacina = rand() % 4 + 1;
                
                if(sortvacina == 1){
                    coronavac++;
                    cout << "Voce esta na fila da coronavac" << endl;
                } else if(sortvacina == 2){
                    pfizer++;
                    cout << "Voce esta na fila da pfizer" << endl;
                } else if(sortvacina == 3){
                    astrazenica++;
                    cout << "Voce esta na fila da astrazenica" << endl;
                } else if(sortvacina == 4){
                    janssen++;
                    cout << "Voce esta na fila da janssen" << endl;
                } else {
                    cout << "Voce digitou algo errado --- Tente novamente" << endl;
                }

            } else if(opmenu == 2){
                cout << endl <<  "Qual vacina voce tomou na primeira dose?";
                menuvacinas();
                cin >> opmenu;
                if(opmenu == 1){
                    coronavac++;
                    cout << "Voce esta na fila da coronavac" << endl;
                } else if(opmenu == 2){
                    pfizer++;
                    cout << "Voce esta na fila da pfizer" << endl;
                } else if(opmenu== 3){
                    astrazenica++;
                    cout << "Voce esta na fila da astrazenica" << endl;
                } else if(sortvacina == 4){
                    cout << "Jassen nao tem segunda dose" << endl;
                } else {
                    cout << "Voce digitou algo errado --- Tente novamente" << endl;
                }

            } else if(opmenu == 3){
                pfizer++;
                cout << "Seu reforco sera a pfizer" << endl;
            }
        } else if(opmenu == 2){
            cout << endl <<  "Qual vacina voce deseja aplicar?" << endl;
            menuvacinas();
            cin >> opmenu;
            
            if(opmenu == 1 && coronavac > 0){
                    coronavac--;
                    cout << "Voce tomou a coronavac" << endl;
                } else if(opmenu == 2 && pfizer > 0){
                    pfizer--;
                    cout << "Voce tomou a pfizer" << endl;
                } else if(opmenu == 3 && astrazenica > 0){
                    astrazenica--;
                    cout << "Voce tomou a astrazenica" << endl;
                } else if(opmenu == 4 && janssen > 0){
                    janssen--;
                    cout << "Voce tomou a janssen" << endl;
                } else {
                    cout << "Voce digitou algo errado --- Tente novamente" << endl;
                }

        } else if(opmenu == 3){
            statusfilas();
        } else if(opmenu == 4){
            if(coronavac == 0 && pfizer == 0 && astrazenica == 0 && janssen == 0){
                cout << "Obrigado por usar nosso serviço!" << endl;
                return 0;
            }else {
                cout << "Voce nao pode ter ninguem na fila para sair" << endl;
            }
        } else{
            cout << "Voce digitou algo errado --- Tente novamente" << endl;
        }
    }



}