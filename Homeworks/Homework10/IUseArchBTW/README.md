# I use Arch BTW

Най-модерната операционна система xnuᴉ˥ има много диструбиции, като често дистрибуциите копират една от друга. Възможно е една дистрибуция да копира повече от 1 друга дистрибуция, както и много дистрибуции да копират една основна.

Определете дали йерархията е счупена. Йерархията ще е счупена, ако има дистрибуция, която директно или индиректно да копира себе си.

За улесниение дистрибуциите ще са именувани с цели числа.

### Input Format

Q - На първия ред получавате едно число - брой заявки. <br>
Следват Q на брой заявки. Всяка заявка е: <br>
E - на първия ред едно число - брой ребра. <br>
На следващите E реда има: <br>
Start End - две числа, начален и краен връх на ребро (End е дистрибуция, която копира Start)

### Constraints

0 <= Q <= 40 <br>
0 <= E <= 10^6 <br>
0 <= Start, End <= 10^8

### Output format

На един ред изведете резултатите за всички заявки, разделени с празно място (спейс). <br>
Резултат може да е 1 ако йерархията е счупена, или 0 ако е валидна.

### Sample Input 0

2 <br>
3 <br>
1 2 <br>
1 3 <br>
2 4 <br>
4 <br>
1 2 <br>
1 3 <br>
2 4 <br>
4 1

### Sample Output 0

0 1

### Explanation 0

Първата йерархия е валидна, защото няма дистрибуция, която да копира себе си, директно или индиректно. <br>
Втората йерархия не е валидна, защото дистрибуцията 2 копира 1, 4 копира 2 и 1 копира 4.