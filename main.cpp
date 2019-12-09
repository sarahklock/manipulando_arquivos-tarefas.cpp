#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ofstream arquivo;
    string tarefas;
    vector <string> tasks;
    int sn;

    cout << "Digite 1 para criar uma lista de tarefas, 2 para acrescentar mais tarefas a lista anterior.\n";

    cin >> sn;

    cin.ignore();

    if (sn == 1){
        tasks.push_back("Tarefas:");
    }

    if (sn == 2){
        ifstream arquivo_antigo;
        arquivo_antigo.open("teste.txt", ios :: app );
        while(!arquivo_antigo.eof()){
             getline(arquivo_antigo, tarefas);
             tasks.push_back(tarefas);
             cout << tarefas << endl;
        }
        arquivo_antigo.close();
    }

    arquivo.open("teste.txt");

    do{
        cout << "Acrescente uma tarefa: \n";

        getline(cin, tarefas);

        tasks.push_back("-> " + tarefas);

        cout << "Deseja acrescentar mais tarefas? Digite 1 para 'sim', 0 para 'nao'. \n";

        cin >> sn;

        cin.ignore();

    } while(sn != 0);

    sort(tasks.begin() + 1, tasks.end());

    system("cls");

    cout << "Esta eh a sua lista de tarefas em ordem alfabetica: ";

    for(string task: tasks){

        cout << endl << task;
    }

    cout << endl << "Deseja deletar alguma tarefas? Se sim, digite 1 e, em seguida, em qual linha, \n";
    cout << "a partir da primeira tarefa, esta a que deseja deletar. Se não, digite 2.\n";

    cin >> sn;

    if (sn == 1){
        int linha_deletar;

        cin >> linha_deletar;

        tasks.erase(tasks.begin() + linha_deletar);
    }

    while(sn == 1){
        cout << "Esta eh a sua lista de tarefas atualizada: ";

        for(string task: tasks){

            cout << endl << task;
        }

        cout << endl << endl << "Deseja deletar mais alguma tarefas? Se sim, digite 1 e, em seguida, em qual linha, \n";
        cout << "a partir da primeira tarefa, esta a que deseja deletar. Se nao, digite 2.\n";

        cin >> sn;

        if (sn == 1){
            int linha_deletar;

            cin >> linha_deletar;

            tasks.erase(tasks.begin() + linha_deletar);
        }

    }

    arquivo << tasks[0];

    for(int i = 1; i < tasks.size(); i++){

        arquivo << endl << tasks[i];
    }

    arquivo.close();

    cout << "Sua lista esta pronta!\n";

    return 0;

}
