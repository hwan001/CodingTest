# �߶� �迭�� �����ϱ�
# https://school.programmers.co.kr/learn/courses/30/lessons/120913
def solution_120913(my_str, n):
    answer = []
    
    while(len(my_str) > n):
        answer.append(my_str[:n])
        my_str = my_str[n:]
        
    answer.append(my_str)
    
    return answer

# ���ڿ��ȿ� ���ڿ�
# https://school.programmers.co.kr/learn/courses/30/lessons/120908
def solution_120908(str1, str2):
    return 2 if len(str1.split(str2)) == 1 else 1