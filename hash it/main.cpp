#include <iostream>
#include <string>
using namespace std;

bool adicionar(string mapa[], string chave) {
    int h, hash, novo_hash;
    h = 0;
    for(int i = 0; i < chave.length(); i++) {
        h += int(chave[i]) * (i + 1);
    }
    hash = (h * 19) % 101;

    if(mapa[hash] == chave) {
        return false;
    } else {
        for(int j = 1; j <= 19; j++) {
            novo_hash = (hash + (23 * j) + (j * j)) % 101;
            if(mapa[novo_hash] == chave) {
                return false;
            }
        }
    }

    if(mapa[hash] == "") {
        mapa[hash] = chave;
        return true;
    }

    for(int j = 1; j <= 19; j++) {
        novo_hash = (hash + (j * j) + (23 * j)) % 101;
        if(mapa[novo_hash] == "") {
            mapa[novo_hash] = chave;
            return true;
        }
    }

    return false;
}

bool remover(string mapa[], string chave) {
    for(int i = 0; i < 101; i++) {
        if(mapa[i] == chave) {
            mapa[i] = "";
            return true;
        }
    }
    return false;
}

int main() {
    int N, m, num_de_entradas;
    string op, chave;
    string meu_mapa[101];

    cin >> N;
    for(int teste = 0; teste < N; teste++) {
        cin >> m;
        num_de_entradas = 0;

        for(int i = 0; i < 101; i++) {
            meu_mapa[i] = "";
        }

        for(int operacao = 0; operacao < m; operacao++) {
            cin >> op;

            if(op.substr(0, 3) == "ADD") {
                chave = op.substr(4);
                if(adicionar(meu_mapa, chave)) {
                    num_de_entradas += 1;
                }
            } else if(op.substr(0, 3) == "DEL") {
                chave = op.substr(4);
                if(remover(meu_mapa, chave)) {
                    num_de_entradas -= 1;
                }
            }
        }

        cout << num_de_entradas << "\n";
        for(int i = 0; i < 101; i++) {
            if(meu_mapa[i] != "") {
                cout << i << ":" << meu_mapa[i] << "\n";
            }
        }
    }

    return 0;
}
