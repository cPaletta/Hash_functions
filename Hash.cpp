#include <iostream>
#include <string>
#define size 3
using namespace std;

struct node {
    string val;
    node* next;
};

int Hash(string Word)
{
    int sum = 0;
    for (int i = 0; i < Word.length(); i++)
    {
        sum += Word[i];
    }
    return sum % (size - 1);
}

void AddToDB(node** tab, string word)
{
    node*& H = tab[Hash(word)];
    node* p = new node;
    p->val = word;
    p->next = H;
    H = p;
}


void PrintHashTable(node** tab)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Indeks " << i << ": ";
        node* current = tab[i];
        while (current != NULL)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
}

bool SearchInDB(node** tab, string word)
{
    int hashValue = Hash(word);
    node* current = tab[hashValue];

    while (current != NULL)
    {
        if (current->val == word)
        {
            cout << "Znaleziono ";
            return true;
        }
        current = current->next;
    }
    cout << "Nie znaleziono";
    return false;
}


void DelFromDB(node** tab, string word)
{
    node*& H = tab[Hash(word)];

    if (H != NULL)
    {
        if (H->val == word)
        {
            if (H != NULL)
            {
                node* p = H;
                H = p->next;
                delete p;
            }
        }
        else
        {
            node* p = H;
            while (p->next && p->next->val != word)
            {
                p = p->next;
            }
            if (p->next != NULL)
            {
                node* temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
        }
    }
}


int main()
{


    node** tab = new node * [size];

    for (int i = 0; i < size; i++)
    {
        tab[i] = NULL;
    }

    string word = "Jan";
    AddToDB(tab, word);

    AddToDB(tab, "Kacper");

    string word2 = "Ania";
    AddToDB(tab, word2);


    PrintHashTable(tab);

    SearchInDB(tab, "Jan");
    DelFromDB(tab, "Jan");
    PrintHashTable(tab);
    return 0;
}