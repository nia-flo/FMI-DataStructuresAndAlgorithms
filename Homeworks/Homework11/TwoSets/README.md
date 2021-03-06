# Two sets

Имате даден претеглен неориентиран граф с N върха номерирани с числата от 0 до N-1 и M ребра. Върховете на графа са разделени на 2 множества: S и T. Всеки връх на графа е или в първото или във второто множество.

По-формално ако графа ни е G(V, E), тогава: <br>
S, T ⊆ V : (S ⋃ T = V) & (S ⋂ T = Ø)

Напишете програма, която отговаря на Q заявки. Всяка заявка се състои от връх от множеството S. Вие трябва да отговорите колко е минималното разстояние до връх от множеството T.

### Input Format

На първият ред на входа се въвеждат N и M - броя върхове и броя ребра.

Следват M реда с по 3 числа на ред - двойка върхове свързани от ребро и разстоянието между тях.

От следващия ред се въвежда K - броя на елементите на множеството T.

Следват K на брой числа - номерата на върховете в множеството T (Всички останали върхове са в множеството S).

От следващия ред се въвежда Q - броя на заявките.

Следват Q реда с пo 1 число на ред - номер на връх от множеството S.

### Constraints

1 <= N <= 10^5 <br>
1 <= M <= 3 * 10^5 <br>
1 <= K < N <br>
1 <= Q <= 10^5

### Output format

Изведете Q реда с по 1 число на ред - отговора на поредната заявка.

### Sample Input 0

6 8 <br>
0 1 1 <br>
1 2 2 <br>
1 3 6 <br>
0 4 5 <br>
1 4 7 <br>
1 5 8 <br>
3 5 2 <br>
4 5 2 <br>
2 <br>
4 5 <br>
4 <br>
0 <br>
1 <br>
2 <br>
3

### Sample Output 0

5 <br>
6 <br>
8 <br>
2

### Explanation 0

T = {4, 5} -> S = {0, 1, 2, 3}

Отговаряме на 4 заявки - за върхове 0, 1, 2, 3:
- Най-късият път от връх 0 до връх от Т е 0 -> 4 с дължина 5
- Най-късият път от връх 1 до връх от Т е 1 -> 0 -> 4 с дължина 6
- Най-късият път от връх 2 до връх от Т е 2 -> 1 -> 0 -> 4 с дължина 8
- Най-късият път от връх 3 до връх от Т е 3 -> 5 с дължина 2
