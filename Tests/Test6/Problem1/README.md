# Problem 1 - Път в граф

Даден е ненасочен граф и поредица от двойки върхове от него. За всяка двойка отговорете има ли път(от едно или повече ребра) в графа, който ги свързва.

### Input Format

N M - брой върхове и брой ребра в графа

Xi Xj - M на брой реда с ребра описани с два върха от графа

K - брой на двойките върхове за които се пита дали има път

Xki Xkj - K на брой двойки от номера на върхове

### Constraints

2 < N, M, K < 1,000,000

### Output Format

Поредица от K на брой нули и единици показваща дали има път(единица) или няма път(нула) между съответните подадени върхове.

### Sample Input 0

5 6 <br>
1 2 <br>
1 4 <br>
2 3 <br>
4 3 <br>
4 5 <br>
3 5 <br>
2 <br>
1 3 <br>
5 2

### Sample Output 0

1 1

