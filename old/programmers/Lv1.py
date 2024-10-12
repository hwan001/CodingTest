from my_package import *

# 짝수와 홀수
# https://school.programmers.co.kr/learn/courses/30/lessons/12937
def solution_12937(num):
    return (lambda x:"Even" if x%2 == 0 else "Odd")(num)


# 평균 구하기
# https://school.programmers.co.kr/learn/courses/30/lessons/12944
def solution_12944(arr):
    return sum(arr) / len(arr)


# 약수의 합
# https://school.programmers.co.kr/learn/courses/30/lessons/12928
def solution_12928(n):
    list_tmp = []
    for i in range(1, n+1):
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
    #import math

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


# 문자열내 P와 y의 개수
# https://school.programmers.co.kr/learn/courses/30/lessons/12916
def solution_12916(s):
    str_py = ""

    for ch in s:
        str_py += ch.lower() 
    
    if str_py.count("p") == str_py.count("y"):
        return True
    else:
        return False
    

# 하샤드 수
# https://school.programmers.co.kr/learn/courses/30/lessons/12947
def solution_12947(x):
    answer = False
    
    if x % sum([int(x) for x in str(x)]) == 0:
        answer =True
    
    return answer


# 정수 내림차순으로 배치하기
# https://school.programmers.co.kr/learn/courses/30/lessons/12933
def solution_12933(n):
    answer = ""
    for x in list(reversed(sorted([int(ch) for ch in str(n)]))):
        answer += str(x)
    return int(answer)


# 문자열을 정수로 바꾸기 
# https://school.programmers.co.kr/learn/courses/30/lessons/12925
def solution_12925(s):
    answer = 0
    
    if s[0] == "-":
        answer = -1 * int(s[1:])
    else:
        answer = int(s)
        
    return answer


# x만큼 간격이 있는 n개의 숫자
# https://school.programmers.co.kr/learn/courses/30/lessons/12954
def solution_12954(x, n):
    answer = []
    
    for i in range(1, n+1):
        answer.append(i * x)
    
    return answer


# 나머지가 1이 되는 수 찾기
# https://school.programmers.co.kr/learn/courses/30/lessons/87389
def solution_87389(n):
    answer = n
    
    for i in range(n, 1, -1):
        if n % i == 1 and answer > i:
            answer = i
    
    return answer


# 콜라츠 추측
# https://school.programmers.co.kr/learn/courses/30/lessons/12943
def solution_12943(num):
    answer = 0
    
    while(num != 1):
        answer += 1
        if answer == 500:
            return -1
        
        if num%2 == 0:
            num /= 2
        else:
            num *= 3
            num += 1
        
    return answer


# 두 정수 사이의 합
# https://school.programmers.co.kr/learn/courses/30/lessons/12912
def solution_12912(a, b):
    if a > b:
        a = a+b
        b = a-b
        a = a-b
        
    return sum([i for i in range(a, b+1)])


# 서울에서 김서방 찾기
# https://school.programmers.co.kr/learn/courses/30/lessons/12919
def solution_12919(seoul):
    answer = "김서방은 " + str(seoul.index("Kim")) + "에 있다"
    return answer


# 핸드폰 번호 가리기
# https://school.programmers.co.kr/learn/courses/30/lessons/12948
def solution_12948(phone_number):
    return '*' * len(phone_number[4:]) + phone_number[-4:]


# 나누어 떨어지는 숫자 배열
# https://school.programmers.co.kr/learn/courses/30/lessons/12910
def solution_12910(arr, divisor):
    answer = sorted([i for i in arr if i%divisor == 0])
    if len(answer) == 0:
        answer.append(-1)
    
    return answer


# 제일 작은 수 제거하기
# https://school.programmers.co.kr/learn/courses/30/lessons/12935
def solution_12935(arr):
    if arr == [10]:
        return [-1]
    
    del arr[arr.index(min(arr))]
    return arr


# 음양 더하기
# https://school.programmers.co.kr/learn/courses/30/lessons/76501
def solution_76501(absolutes, signs):
    answer = 0
    
    for i in range(len(absolutes)):
        if signs[i]:
            answer += absolutes[i]
        else:
            answer -= absolutes[i]
    
    return answer


# 수박수박수박수박수박수?
# https://school.programmers.co.kr/learn/courses/30/lessons/12922
def solution_12922(n):
    answer = ''
    
    if n%2==0:
        answer = "수박" * (n//2)
    else:
        answer = "수"
        if n != 1:
            answer += "박수" * (n//2)
            
    return answer



# 가운데 글자 가져오기
# https://school.programmers.co.kr/learn/courses/30/lessons/12903
def solution_12903(s):
    answer = ''
    len_s = len(s)
    
    if len_s%2==0:
        answer = s[len_s//2-1:len_s//2+1]
    else:
        answer = s[len_s//2]
    
    return answer


# 없는 숫자 더하기
# https://school.programmers.co.kr/learn/courses/30/lessons/86051
def solution_86051(numbers):
    answer = -1
    answer = 45 -sum(numbers)
    return answer


