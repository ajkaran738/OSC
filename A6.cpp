// ======================= FirstFit ============================
#include <iostream>
#include <vector>
using namespace std;

void FirstFit(vector<int> &MemBlocks, vector<int> &ProcessSize, int n, int m)
{
    vector<int> allocation(m, -1);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (MemBlocks[j] > ProcessSize[i] && allocation[i] == -1)
            {
                allocation[i] = j;
                MemBlocks[j] -= ProcessSize[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\t\tProcess Size\t\tBlock no.\n";
    for (int i = 0; i < m; i++)
    {
        cout << " " << i + 1 << "\t\t\t" << ProcessSize[i] << "\t\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of Memory Blocks : ";
    cin >> n;
    vector<int> MemBlocks(n);
    cout << "Enter Size of each Memory Block : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> MemBlocks[i];
    }

    int m;
    cout << "Enter number of Processes : ";
    cin >> m;
    vector<int> ProcessSize(m);
    cout << "Enter Size of each Process : " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> ProcessSize[i];
    }

    FirstFit(MemBlocks, ProcessSize, n, m);

    return 0;
}

// ======================= Best Fit ============================
#include <iostream>
#include <vector>
using namespace std;

void BestFit(vector<int> &MemBlocks, vector<int> &ProcessSize, int n, int m)
{
    vector<int> allocation(m, -1);
    for (int i = 0; i < m; i++)
    {
        int bestInd = -1;
        for (int j = 0; j < n; j++)
        {
            if (MemBlocks[j] >= ProcessSize[i])
            {
                if (bestInd == -1 || MemBlocks[j] < MemBlocks[bestInd])
                {
                    bestInd = j;
                }
            }
        }
        if (bestInd != -1)
        {
            allocation[i] = bestInd;
            MemBlocks[bestInd] -= ProcessSize[i];
        }
    }

    cout << "\nProcess No.\t\tProcess Size\t\tBlock no.\n";
    for (int i = 0; i < m; i++)
    {
        cout << " " << i + 1 << "\t\t\t" << ProcessSize[i] << "\t\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of Memory Blocks : ";
    cin >> n;
    vector<int> MemBlocks(n);
    cout << "Enter Size of each Memory Block : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> MemBlocks[i];
    }

    int m;
    cout << "Enter number of Processes : ";
    cin >> m;
    vector<int> ProcessSize(m);
    cout << "Enter Size of each Process : " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> ProcessSize[i];
    }

    BestFit(MemBlocks, ProcessSize, n, m);

    return 0;
}