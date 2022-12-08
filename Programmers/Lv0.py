# 잘라서 배열로 저장하기
# https://school.programmers.co.kr/learn/courses/30/lessons/120913
def solution_120913(my_str, n):
    answer = []
    
    while(len(my_str) > n):
        answer.append(my_str[:n])
        my_str = my_str[n:]
        
    answer.append(my_str)
    
    return answer

# 문자열안에 문자열
# https://school.programmers.co.kr/learn/courses/30/lessons/120908
def solution_120908(str1, str2):
    return 2 if len(str1.split(str2)) == 1 else 1


# 기사단원의 무기
# https://school.programmers.co.kr/learn/courses/30/lessons/136798
def solution_136798(number, limit, power):
    list_knight_power = []

    for n in range(1, number+1):
        list_tmp = []
        for x in range(1, int(math.sqrt(n))+1):
            if n % x == 0:
                list_tmp.append(x)
                list_tmp.append(n // x)
        list_knight_power.append(len(set(list_tmp)))

    return sum([power if x > limit else x for x in list_knight_power])