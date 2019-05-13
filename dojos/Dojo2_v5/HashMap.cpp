#include "HashMap.h"
#include "LinkedList.h"
#include "IHashable.h"
#include "object.h"
#include <cstring>

HashMap::HashMap(size_t array_size, double load_factor)
    : items{nullptr}, element_count{0},
      array_size{array_size}, load_factor{load_factor}
{
    // memset(items, 0, sizeof(LinkedList) * array_size);
    items = (LinkedList*)calloc(array_size, sizeof(LinkedList));
}

void HashMap::add(IHashable *key, Object *value)
{
    if (((double)element_count) / array_size > load_factor)
        reHash();
    int hc = key->GetHashCode();
    int pos = hc % array_size;
    items[pos].add(key, value);
    element_count++;
}

const Object &HashMap::operator[](const IHashable &key) const
{
    int hc = key.GetHashCode();
    int pos = hc % array_size;

    return items[pos][key];
}

void HashMap::iterate(void (*funct)(const IHashable &h, const Object &val)) const
{
    for (size_t i = 0; i < array_size; i++)
    {
        items[i].iterate(funct);
    }
}

HashMap::~HashMap()
{
    // delete[] items;
    for (size_t i = 0; i < array_size; i++)
    {
        LinkedListNode *aux = items[i].first;
        while (aux != nullptr)
        {
            LinkedListNode *auxNext = aux->next;
            delete aux->value;
            delete aux->key;
            delete aux;
            aux = auxNext;
        }
    }
    free(items);
}
void HashMap::relink(LinkedList *n_items, int n_array_size, LinkedList &linkedList)
{
    LinkedListNode *aux = linkedList.first;
    while (aux)
    {
        LinkedListNode *next = aux->next;
        aux->next = nullptr;
        int npos = aux->key->GetHashCode() % n_array_size;
        n_items[npos].add(aux);
        aux = next;
    }
    linkedList.first = linkedList.last = nullptr;
}
void HashMap::reHash()
{
    puts("REHASH");
    int n_array_size = array_size * 2 + 1;

    // LinkedList *n_items = new LinkedList[n_array_size];
    LinkedList *n_items = (LinkedList*)calloc(n_array_size, sizeof(LinkedList));

    for (size_t i = 0; i < array_size; i++)
    {
        relink(n_items, n_array_size, items[i]);
    }
    // delete[] items;
    free(items);
    items = n_items;
    array_size = n_array_size;
}
bool HashMap::erase(const IHashable& key)
{
    int hc = key.GetHashCode();
    int pos = hc % array_size;
    return items[pos].erase(key);
}
