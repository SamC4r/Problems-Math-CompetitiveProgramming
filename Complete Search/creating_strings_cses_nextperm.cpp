// using next_permutation method

#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int main()
{
    cin >> s;
    n = s.length();
    sort(s.begin(), s.end()); // Sorting it is very important. next_permutation() generates perms in lexicographical order.
    string solution;
    int cont = 1;

    // solution = s + "\n";
    // while(next_permutation(s.begin(),s.end())){
    //     cont++;
    //     solution += s + "\n";
    // }
    // cout << cont << "\n" << solution << endl;

    cont = 0;
    solution.clear();

    do //do while in order to process the first permutation. Try the previous code withoud solution = s + "\n"
    {
        cont++;
        solution += s + "\n";
    } while (next_permutation(s.begin(), s.end())); // do while. Executes the do once even if while is false and then the while iterates and comes back to the do.
    //next_permutation() changes s and it stops when there is no lexicographical greater perm.
    cout << cont << "\n"
         << solution;
}