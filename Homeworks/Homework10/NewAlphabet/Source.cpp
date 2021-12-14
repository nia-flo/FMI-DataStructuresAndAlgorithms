#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    string previousWord;
    cin >> previousWord;

    map<char, set<char>> parents;
    for (int i = 0; i < previousWord.size(); i++)
    {
        parents[previousWord[i]] = set<char>();
    }

    for (int i = 1; i < N; i++)
    {
        string word;
        cin >> word;

        int j = 0;
        while (j < word.size() && j < previousWord.size() && word[j] == previousWord[j])
        {
            if (parents.find(word[j]) == parents.end())
            {
                parents[word[j]] = set<char>();
            }

            j++;
        }

        if (j == word.size() || j == previousWord.size())
        {
            continue;
        }

        parents[word[j]].insert(previousWord[j]);

        for (; j < word.size(); j++)
        {
            if (parents.find(word[j]) == parents.end())
            {
                parents[word[j]] = set<char>();
            }
        }

        previousWord = word;
    }

    vector<char> orphans;
    for (map<char, set<char>>::iterator it = parents.begin(); it != parents.end();)
    {
        if ((*it).second.size() == 0)
        {
            orphans.push_back((*it).first);

            map<char, set<char>>::iterator itCopy = it;
            itCopy++;

            parents.erase(it);

            it = itCopy;
        }
        else
        {
            it++;
        }
    }

    while (!parents.empty())
    {
        sort(orphans.begin(), orphans.end());
        for (int i = 0; i < orphans.size(); i++)
        {
            cout << orphans[i] << ' ';
        }

        vector<char> oldOrphans(orphans);
        orphans.clear();

        for (map<char, set<char>>::iterator it = parents.begin(); it != parents.end();)
        {
            for (int j = 0; j < oldOrphans.size(); j++)
            {
                set<char>::iterator toErase = (*it).second.find(oldOrphans[j]);
                if (toErase != (*it).second.end())
                {
                    (*it).second.erase(toErase);
                }
            }

            if ((*it).second.size() == 0)
            {
                orphans.push_back((*it).first);

                map<char, set<char>>::iterator itCopy = it;
                itCopy++;

                parents.erase(it);

                it = itCopy;
            }
            else
            {
                it++;
            }
        }
    }

    sort(orphans.begin(), orphans.end());
    for (int i = 0; i < orphans.size(); i++)
    {
        cout << orphans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
