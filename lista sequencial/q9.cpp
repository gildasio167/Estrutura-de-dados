vector<int> uniao(vector<int> lista1, vector<int> lista2) {
    vector<int> resultado;
    int n1 = lista1.size(), n2 = lista2.size();
    int i = 0, j = 0;

    // Percorre as duas listas e adiciona elementos na lista resultado
    while (i < n1 && j < n2) {
        if (lista1[i] < lista2[j]) {
            resultado.push_back(lista1[i]);
            i++;
        }
        else if (lista2[j] < lista1[i]) {
            resultado.push_back(lista2[j]);
            j++;
        }
        else { // Elementos iguais
            resultado.push_back(lista1[i]);
            i++;
            j++;
        }
    }

    // Adiciona elementos restantes da lista1
    while (i < n1) {
        resultado.push_back(lista1[i]);
        i++;
    }

    // Adiciona elementos restantes da lista2
    while (j < n2) {
        resultado.push_back(lista2[j]);
        j++;
    }

    return resultado;
}




vector<int> intersecao(vector<int> lista1, vector<int> lista2) {
    vector<int> resultado;
    int n1 = lista1.size(), n2 = lista2.size();
    int i = 0, j = 0;

    // Percorre as duas listas, verificando elementos em comum
    while (i < n1 && j < n2) {
        if (lista1[i] < lista2[j]) {
            i++;
        }
        else if (lista2[j] < lista1[i]) {
            j++;
        }
        else { // Elementos iguais
            resultado.push_back(lista1[i]);
            i++;
            j++;
        }
    }

    return resultado;
}
