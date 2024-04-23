#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; // no of processes
    cout << "Enter no of Processes: ";
    cin >> n;
    int r; // no of resources
    cout << "Enter no of resources: ";
    cin >> r;

    // Allocation matrix
    vector<vector<int>> allocation(n, vector<int>(r));
    cout << "Enter Allocation matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << ": ";
        for (int j = 0; j < r; j++)
        {
            cin >> allocation[i][j];
        }
    }
    cout << "\n";

    // Maximum Need Matrix
    vector<vector<int>> maxNeed(n, vector<int>(r));
    cout << "Enter Maximum Need Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << ": ";
        for (int j = 0; j < r; j++)
        {
            cin >> maxNeed[i][j];
        }
    }

    // Available resources
    vector<int> available(r);
    cout << "Enter Available Resources: ";
    for (int i = 0; i < r; i++)
    {
        cin >> available[i];
    }

    // Calculate Need matrix
    vector<vector<int>> need(n, vector<int>(r));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }

    // Safety algorithm
    vector<int> f(n, 0); // to track whether process i is allocated resources
    vector<int> ans;     // to store safe sequence
    int count = 0;       // to count number of processes in the safe sequence

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < r; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans.push_back(i);
                    for (int y = 0; y < r; y++)
                    {
                        available[y] += allocation[i][y];
                    }
                    f[i] = 1;
                    count++;
                }
            }
        }
    }

    // Check if all processes are included in the safe sequence
    if (count == n)
    {
        cout << "The Safe Sequence is: ";
        for (int i = 0; i < n; i++)
        {
            cout << "P" << ans[i] + 1 << "->";
        }
    }
    else
    {
        cout << "No Safe Sequence!" << endl;
    }

    return 0;
}
