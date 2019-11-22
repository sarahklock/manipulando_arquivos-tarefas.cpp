#include <iostream>
#include <fstream>

using namespace std;

int main(){

    fstream arquivo;
    string tarefa;
    int sn, ntarefas = 0;

    arquivo.open("teste.txt", ios :: app);

    arquivo << "Tarefas:" << endl;

    do{

        ntarefas++;

        cout << "Acrescente uma tarefa a sua lista de tarefas: \n";

        getline (cin, tarefa);

        arquivo << tarefa << endl;

        cout << "Deseja acrescentar mais tarefas? Digite 1 para 'sim' e 0 para 'nao'. \n";

        cin >> sn;

    }while(sn == 1);

    return 0;
}
