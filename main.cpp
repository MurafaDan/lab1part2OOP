#include <iostream>
#include <random>
#include <time.h>

using namespace std;

struct Vector
{
    int id;
    int nr;
    char *el;
};

void initVector(Vector *vector)
{
    vector->nr = 1;
    vector->el = new char[vector->nr];
    if (vector->el == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < vector->nr; i++)
    {
        vector->el[i] = i;
    }
}

void afisVector(Vector *vector)
{
    cout << "ID-ul: " << vector->id << " | Numarul de elemente: " << vector->nr << endl;
    cout << "Elementele vectorului:" << endl;
    for (int i = 0; i < vector->nr; i++)
    {
        cout << " " << static_cast<int>(vector->el[i]);
    }
    cout << endl;
}

void setSizeVector(Vector *vector)
{
    cout << "Dati marimea vectorului:" << endl
         << ">>>";
    int len;
    cin >> len;
    vector->nr = len;
    vector->el = new char[vector->nr];
    if (vector->el == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < vector->nr; i++)
    {
        vector->el[i] = i;
    }
}

void deleteVector(Vector *vector)
{
    if (vector->el)
    {
        delete[] vector->el;
    }
    vector->el = NULL;
    delete vector;
}

void compareVector(Vector *vector1, Vector *vector2)
{
    cout << vector1->id << "  " << vector2->id << endl;
    if (vector1->nr < vector2->nr)
    {
        cout << "Vectorul cu ID" << vector2->id << " are cu " << vector2->nr - vector1->nr << " elemente." << endl;
    }
    else if (vector1->nr > vector2->nr)
    {
        cout << "Vectorul cu ID" << vector1->id << " are cu " << vector1->nr - vector2->nr << " elemente." << endl;
    }
    else
    {
        cout << "Vectorii au un numar egal de elemente." << endl;
    }
}

void modVector(Vector *vector)
{
    afisVector(vector);
    cout << "Introduceti elementele vectorului:" << endl;
    for (int i = 0; i < vector->nr; i++)
    {
        cout << "Elementul" << i + 1 << " : ";
        cin >> vector->el[i];
    }
    afisVector(vector);
}

void randVector(Vector *vector)
{
    afisVector(vector);
    srand(time(NULL));
    for (int i = 0; i < vector->nr; i++)
    {
        vector->el[i] = rand() % 200 - 100;
    }
    cout << endl
         << "Vectorul generat:" << endl;
    afisVector(vector);
}

void prodNegVector(Vector *vector)
{
    int prod = 1;
    cout << "Produsul elemntelor negative : ";
    for (int i = 0; i < vector->nr; i++)
    {
        if (vector->el[i] < 0)
        {
            prod *= (vector->el[i]);

        }
    }
    cout << prod << endl;
}

void menu()
{
    int option, n = 1, id;
    Vector *vectors[100];
    while (1)
    {
        cout << "=============Menu==============" << endl;
        cout << "1: Initializare new vector" << endl;
        cout << "2: Setare/modificare marime vector" << endl;
        cout << "3: Setare/modificare elemente vector" << endl;
        cout << "4: Afisare vector" << endl;
        cout << "5: Compara vector" << endl;
        cout << "6: Delete vector" << endl;
        cout << "7: Produsul elentelor negative" << endl;
        cout << "0: Exit" << endl
             << ">>>";
        cin >> option;

        switch (option)
        {
            case 1:
                Vector *newVector;
                newVector = new Vector;
                if (newVector == NULL)
                    exit(1);
                initVector(newVector);
                newVector->id = n;
                afisVector(newVector);
                vectors[n] = newVector;
                n++;
                break;
            case 2:
                cout << "Introduceti ID-ul vectorului la care doriti sa setati/modificati marimea:" << endl
                     << ">>>";
                cin >> id;
                if (id >= n || id < 0)
                {
                    cout << "Asa vector nu exista" << endl;
                    break;
                }
                setSizeVector(vectors[id]);
                break;
            case 3:
                cout << "Introduceti ID-ul vectorului la care doriti sa setati/modificati elementele:" << endl
                     << ">>>";
                cin >> id;
                if (id >= n || id < 0)
                {
                    cout << "Asa vector nu exista" << endl;
                    break;
                }
                while (option != -1)
                {
                    cout << "Alegeti introducerea manuala sau automata a vectorului!" << endl;
                    cout << "1 : Manual" << endl;
                    cout << "2 : Automata (random)" << endl
                         << ">>>";
                    cin >> option;
                    switch (option)
                    {
                        case 1:
                            modVector(vectors[id]);
                            option = -1;
                            break;
                        case 2:
                            randVector(vectors[id]);
                            option = -1;
                            break;
                        default:
                            cout << "Ati introdus o optie incorecta!" << endl;
                            break;
                    }
                }
                break;
            case 4:
                cout << "Introduceti ID-ul vectorului care doriti sa afisati:" << endl
                     << ">>>";
                cin >> id;
                if (id >= n || id < 0)
                {
                    cout << "Asa vector nu exista" << endl;
                    break;
                }
                afisVector(vectors[id]);
                break;
            case 5:
                cout << "Introduceti ID-ul vectorului 1 care doriti sa comparati:" << endl
                     << ">>>";
                int id1, id2;
                cin >> id1;
                if (id1 >= n || id1 < 0)
                {
                    cout << "Asa vector nu exista" << endl;
                    break;
                }
                cout << "Introduceti ID-ul vectorului 2 care doriti sa comparati:" << endl
                     << ">>>";
                cin >> id2;
                if (id2 >= n || id2 < 0)
                {
                    cout << "Asa vector nu exista" << endl;
                    break;
                }
                compareVector(vectors[id1], vectors[id2]);
                break;
            case 6:
                cout << "Introduceti ID-ul vectorului care doriti sa stergeti:" << endl
                     << ">>>";
                cin >> id;
                if (id >= n || id < 0)
                {
                    cout << "Asa vector nu exista" << endl;
                    break;
                }
                deleteVector(vectors[id]);
                break;
            case 7:
                cout << "Introduceti ID-ul vectorului la care doriti sa aflati produsul elementelor negative:" << endl
                     << ">>>";
                cin >> id;
                if (id >= n || id < 0)
                {
                    cout << "Asa vector nu exista" << endl;
                    break;
                }
                prodNegVector(vectors[id]);
                break;
            case 0:
                deleteVector(newVector);
                for (int i = 0; i < n; i++)
                {
                    deleteVector(vectors[i]);
                }
                cout << endl
                     << "Eliberarea memoriei a fost facuta cu succes!!!" << endl;

                    delete vectors[id];


                exit(1);
            default:
                cout << "Ati introdus o optie incorecta!" << endl;
                break;
        }
    }
}

int main()
{

    menu();

    return 0;
}
