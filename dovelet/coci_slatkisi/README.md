문제 : http://211.228.163.31/30stair/coci_slatkisi/coci_slatkisi.php?pname=coci_slatkisi&stair=1

## 풀이

a, b를 입력받고 i번째 수에서 반올림한 결과를 출력하면 되는 문제 인데, c언어의 특징을 이용해서 short coding을 할 수 있다.

C언어에서 double 연산의 소숫점 n자리까지 출력을 하면 n+1자리에서 반올림을 하므로, a를 pow(10, b)로 나누고 소수점을 출력하지 않도록 해서 반올림 시킨 다음에, 0을 b만큼 붙이면 된다.

0을 b만큼 붙이는 것은 printf의 잘 사용하지 않는 기능을 이용해서 가능한데, 폭만큼 leading zero를 붙일 수 있는 %0과 width를 인자로 넘겨 받을 수 있는 *를 조합하여 %0*d 로 b, 0을 출력하면 된다.

## 주의

컴파일러 환경에 따라서 올바른 결과가 나오지 않을 수 있다. :)
