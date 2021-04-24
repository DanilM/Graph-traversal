#include <iostream>
#include <queue>
const int n = 9;
bool used[6];
int countDug = 0;
int countNode = 0;
struct duga
{
    //v - начальный узел
    //w - конечный узел
    //с - длина узла
    int v, w, c;
};
//Задаю список дуг для демострации работы программы
void SetDugs(duga D[])
{
    D[0].v = 2;
    D[0].w = 1;
    D[0].c = 6;

    D[1].v = 3;
    D[1].w = 1;
    D[1].c = 3;

    D[2].v = 5;
    D[2].w = 1;
    D[2].c = 1;

    D[3].v = 1;
    D[3].w = 4;
    D[3].c = 9;

    D[4].v = 2;
    D[4].w = 3;
    D[4].c = 2;

    D[5].v = 4;
    D[5].w = 2;
    D[5].c = 2;

    D[6].v = 3;
    D[6].w = 5;
    D[6].c = 1;

    D[7].v = 4;
    D[7].w = 3;
    D[7].c = 5;

    D[8].v = 4;
    D[8].w = 5;
    D[8].c = 9;
}

void Obhod(duga D[], int v)
{
    used[v] = true;
    std::queue<int> q;
    q.push(v);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        countNode++;
        for (int i = 0; i < 9; i++)
        {
            if (D[i].v == u)
            {
                countDug++;
            }
            if (D[i].v == u && !used[D[i].w])
            {
                used[D[i].w] = true;
                q.push(D[i].w);
            }
        }
    }
}

int main()
{
    int v;
    duga D[n];
    for (int i = 0; i < 6; i++)
    {
        used[i] = false;
    }
    SetDugs(D);
    std::cout << "Enter first node: ";
    std::cin >> v;
    Obhod(D, v);
    std::cout << "\n";
    int cycNum = countDug - countNode + 1;
    std::cout << "Cyclomatic number: " << cycNum;
}
