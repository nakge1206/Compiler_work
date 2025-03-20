# Compiler

![image](./compiler/.jpeg)

구현부분
-----
어휘분석 : 원시프로그램을 입력으로 어휘분석기를 통해 토큰으로 반환 (허용되지 않는 문자의 입력을 검출)

구문분석 : 어휘분석에서 나온 토큰을 입력으로 받아 구문트리(AST)를 반환. (문맥 무관 문법) (문법에 맞지 않는 문장을 검출)

중간코드생성 : 파스트리를 순회하면서 생성함
-----

미구현부분
-----
의미분석 : 의미가 정의되지 않는 문장들을 검출 (선언되지 않는 변수 사용 / 자료형 불일치 / 매개변수의 갯수와 형의 불일치)

코드최적화

목적코드생성
-----
