// CPP program to display content of Trie
#include <cs50.h>
#include <string.h>
#define alpha_size 26
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])/// bibliotecas

using namespace std;

// Trie node
struct TrieNode/// define el nodo
{
    struct TrieNode* children[alpha_size];
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode* createNode()//crea un trie
{
    struct TrieNode* pNode = new TrieNode;///crea un puntero hace que sea igual a new trienode

    for (int i = 0; i < alpha_size; i++)////hace que todos los hijos sean nullos
        pNode->children[i] = NULL;

    pNode->isLeaf = false;///y lo pone en falso

    return pNode;////regresa pnode el nodo creo no lo se
};

// function to insert a node in Trie
void insert_node(struct TrieNode* root, char* key)
{
    int level;///nivel
    int length = strlen(key);///saca el tamano de la palabra
    struct TrieNode* pCrawl = root;////pcrawl a apunta root

    for (level = 0; level < length; level++)///crea un loop del tamano de la palabra
    {
        int index = key[level] - 'a';/// crea index hace que sea igual a key nivel 0 le resta 'a'
                                    /// es para hacer que las index tome solo letras de 0 a 1 2 3
        if (pCrawl->children[index] == NULL)////if pclaw que esta atado a root mirando a index es nullo
            pCrawl->children[index] = createNode();///crea el nodo///si no pasa esta linea
            ///si ya existe entonces solo hace que pcraw cambie a ese nodo
        pCrawl = pCrawl->children[index];////hace que pcrawl mire al siguiente nodo
    }

    pCrawl->isLeaf = true;///cuando termina de crear el ultimo nodo lo pasa a true
}

// function to check if current node is leaf node or not
bool isLeafNode(struct TrieNode* root)
{
    return root->isLeaf != false;
}

// function to display the content of Trie
void display(struct TrieNode* root, char str[], int level)
{
    // If node is leaf node, it indiicates end of string, so a null charcter is added and string is displayed
    if (isLeafNode(root))///
    {
        str[level] = '\0';//hace que str [ 123 ]
        cout << str << endl;////caso base para hacer que imprima un
    }

    for (int i = 0; i < 26 ; i++)
    {
        // if NON NULL child is found add parent key to str and call the display function recursively ddfor child node
        if (root->children[i])
        {
            str[level] = i + 'a';   ///      i  +  110 para trasformarlos a las letras del alfabeto
            display(root->children[i], str, level + 1);
        }
    }
}

// Driver program to test above functions
int main()
{
    // Keys to be inserted in Trie
    char keys[][8] = { "the", "a", "there", "answer",
                       "any", "by", "bye", "their" };

    struct TrieNode* root = createNode();

    // Inserting keys in Trie
    for (int j = 0; j < ARRAY_SIZE(keys); j++)
        insert_node(root, keys[j]);

    int level = 0;
    char str[20];

    // Displaying content of Trie
    cout << "Content of Trie: " << endl;
    display(root, str, level);
}