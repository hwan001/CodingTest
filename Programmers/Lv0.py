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