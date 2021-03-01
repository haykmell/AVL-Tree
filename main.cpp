#include <iostream>
#include "tree.h"
using namespace std;

int main()
{
    Tree tree;
    tree.insert(5);

    tree.insert(10);
    tree.insert(15);

    tree.display();
}