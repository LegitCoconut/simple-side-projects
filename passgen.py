print('-------------------------------------------------------------------')
print('|           UN-BREAKABLE PYTHON PASSWORD GENERTAER                |')
print('|                    written by adi.exe                           |')
print('|        uses random and string mdoule for generating pass        |')
print('|          uses 3 layer AI algorythm for randomising pass         |')
print('-------------------------------------------------------------------')
import random as r
alpha = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
spchar = [',', '.', '?', '!', ';', '\'', '"', '`', '(', ')', '[', ']', '{', '}', '<', '>', '+', '-', '*', '/', '%', '^', '&', '|', '~', '!', '=', '?', ':', '@', '#', '$', '%', '^', '&', '*', '_', '+', '-', '=', '|', ':', '\'', '"', ',', '.', '?', '/', '\\', '~']
talpha,tdigits,tspchar,password=[],[],[],[]
no=int(input('     how many digits in passowrd : '))
for i in range(no):
    talpha.append(alpha[r.randint(0,51)])
    tdigits.append(digits[r.randint(0,9)])
    tspchar.append(spchar[r.randint(0,49)])
r.shuffle(talpha)
r.shuffle(tspchar)
r.shuffle(tdigits)
tfinal=talpha+tdigits+tspchar
for j in range(no):
    password.append(tfinal[r.randint(0,(no*3)-1)])
final_pass = ''.join(password)
print('            your secure password :',final_pass)