# This is an nlogn implementation provided you create a GLOBAL array to store all the factorials which can be precomputed.
def fact(num):
    answer = 1
    for i in range(2,num+1):
        answer *= i
    return answer

def calculate_rank_nlogn(S):
    temp = sorted(S)
    rank = 1
    n =len(S)
    for i in range(len(S)):
        index = temp.index(S[i])
        del temp[index]
        #print str(index) +":" + str(n-1-i)
        rank += index*fact(n-1-i)
    print rank

#This is an n implementation provided you create a GLOBAL array to store all the factorials which can be precomputed.
def calculate_rank_n(S):
    temp_array = [0]*26
    for char in S:
        temp_array[ord(char)-ord('a')] += 1
    n = len(S)
    rank = 1
    for i in range(len(S)):
        index = sum(temp_array[:ord(S[i])-ord('a')])
        temp_array[ord(S[i])-ord('a')] = 0
        rank += index*fact(n-1-i)
    print rank

string = "string"
calculate_rank_nlogn(string)
calculate_rank_n(string)
