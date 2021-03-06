# Super Hamilton

Супер Хамилтън е най-храбрият рицар в царството Алгоритмия и му е зададена много сложната задача да спаси принцесата на кралството от лабиринта на злия Сесий. За да се отключи вратата на принцесата са необходими да се съберат K на брой ключа, като всички ключове са разпръснати по 1 във всяка стая на лабиринта. Проблемът е че след като се посети една стая, тя се заключва за винаги и не може да бъде посетена втори път.

Намерете броя на възможните начини Хамилтън да стигне до принцесата. Ако не може да стигне, възможните начини са 0.

За улеснение лабиринтът представлява матрица, която има 4 вида символи:
- \- е стая, чийто ключ трябва да вземем
- x е непроходима стая (в нея няма ключ и не може да влезем)
- s е началната позиция на Супер Хамилтън (може да е на произволно място в лабиринта)
- e е стаята на принцесата, която Супер Хамилтън трябва да спаси

От всяка стая (s или -) може да отидем единствено в стаите на ляво/дясно/горе/долу, ако такива съществуват. Не може да се движим по диагонал и не може да напускаме лабиринта.

### Input Format

На първия ред получавате 2 числа rows cols, които са съответно размера на лабиринта (редове и колони)

На следващите rows реда ще получите по cols символа. Какво означава всеки символ е описано по-горе.

### Constraints

0 <= rows * cols <= 25

### Output format

Отпечатайте броя на възможните начини Хамилтън да стигне до принцесата.

### Sample Input 0

3 4 <br>
s--- <br>
---- <br>
--ex

### Sample Output 0

2

### Explanation 0

Възможните пътища, които посещават всички празни клетки -, от s до e са точно 2. Един път е ако тръгнем първо на дясно и другият път е ако тръгнем първо на долу.

### Sample Input 1

1 4 <br>
s-ex

### Sample Output 1

1

### Sample Input 2

2 4 <br>
s-xe <br>
--x-

### Sample Output 2

0

### Explanation 2

Тъй като e е блокиран зад стена от x, то няма нито един път от s до e.
