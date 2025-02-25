# 짝수와 홀수
# https://school.programmers.co.kr/learn/courses/30/lessons/12937
def solution_12937(num):
    return (lambda x: "Even" if x % 2 == 0 else "Odd")(num)


# 평균 구하기
# https://school.programmers.co.kr/learn/courses/30/lessons/12944
def solution_12944(arr):
    return sum(arr) / len(arr)


# 약수의 합
# https://school.programmers.co.kr/learn/courses/30/lessons/12928
def solution_12928(n):
    list_tmp = []
    for i in range(1, n + 1):
        if n % i == 0:
            list_tmp.append(i)

    return sum(list_tmp)


# 자릿수 더하기
# https://school.programmers.co.kr/learn/courses/30/lessons/12931
def solution_12931(n):
    return sum([int(x) for x in str(n)])


# 정수 제곱근 판별
# https://school.programmers.co.kr/learn/courses/30/lessons/12934
def solution_12934(n):
    answer = 0
    sqrt_n = math.sqrt(n)

    if sqrt_n.is_integer():
        answer = (sqrt_n + 1) * (sqrt_n + 1)
    else:
        answer = -1

    return answer


# 자연수 뒤집어 배열로 만들기
# https://school.programmers.co.kr/learn/courses/30/lessons/12932
def solution_12932(n):
    return list(reversed([int(x) for x in str(n)]))


# 문자열 내 p와 y의 개수
# https://school.programmers.co.kr/learn/courses/30/lessons/12916
def solution_12916(s):
    str_py = ""

    for ch in s:
        str_py += ch.lower()

    return str_py.count("p") == str_py.count("y")


# 하샤드 수
# https://school.programmers.co.kr/learn/courses/30/lessons/12947
def solution_12947(x):
    return x % sum([int(x) for x in str(x)]) == 0


# 정수 내림차순으로 배치하기
# https://school.programmers.co.kr/learn/courses/30/lessons/12933
def solution_12933(n):
    return int("".join(sorted(str(n), reverse=True)))


# 문자열을 정수로 바꾸기
# https://school.programmers.co.kr/learn/courses/30/lessons/12925
def solution_12925(s):
    return int(s)


# x만큼 간격이 있는 n개의 숫자
# https://school.programmers.co.kr/learn/courses/30/lessons/12954
def solution_12954(x, n):
    return [i * x for i in range(1, n + 1)]


# 나머지가 1이 되는 수 찾기
# https://school.programmers.co.kr/learn/courses/30/lessons/87389
def solution_87389(n):
    for i in range(1, n):
        if n % i == 1:
            return i


# 콜라츠 추측
# https://school.programmers.co.kr/learn/courses/30/lessons/12943
def solution_12943(num):
    answer = 0

    while num != 1:
        answer += 1
        if answer == 500:
            return -1

        num = num // 2 if num % 2 == 0 else num * 3 + 1

    return answer


# 두 정수 사이의 합
# https://school.programmers.co.kr/learn/courses/30/lessons/12912
def solution_12912(a, b):
    return sum(range(min(a, b), max(a, b) + 1))


# 서울에서 김서방 찾기
# https://school.programmers.co.kr/learn/courses/30/lessons/12919
def solution_12919(seoul):
    return f"김서방은 {seoul.index('Kim')}에 있다"


# 핸드폰 번호 가리기
# https://school.programmers.co.kr/learn/courses/30/lessons/12948
def solution_12948(phone_number):
    return '*' * (len(phone_number) - 4) + phone_number[-4:]


# 나누어 떨어지는 숫자 배열
# https://school.programmers.co.kr/learn/courses/30/lessons/12910
def solution_12910(arr, divisor):
    answer = sorted([i for i in arr if i % divisor == 0])
    return answer if answer else [-1]


# 제일 작은 수 제거하기
# https://school.programmers.co.kr/learn/courses/30/lessons/12935
def solution_12935(arr):
    return arr if len(arr) == 1 else [i for i in arr if i != min(arr)]


# 음양 더하기
# https://school.programmers.co.kr/learn/courses/30/lessons/76501
def solution_76501(absolutes, signs):
    return sum([absolutes[i] if signs[i] else -absolutes[i] for i in range(len(absolutes))])


# 수박수박수박수박수?
# https://school.programmers.co.kr/learn/courses/30/lessons/12922
def solution_12922(n):
    return "수박" * (n // 2) + "수" * (n % 2)


# 가운데 글자 가져오기
# https://school.programmers.co.kr/learn/courses/30/lessons/12903
def solution_12903(s):
    return s[(len(s) - 1) // 2:len(s) // 2 + 1]


# 없는 숫자 더하기
# https://school.programmers.co.kr/learn/courses/30/lessons/86051
def solution_86051(numbers):
    return 45 - sum(numbers)