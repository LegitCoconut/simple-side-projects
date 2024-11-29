# making a crossword game using python
db = [
    ['G', 'O', 'A', 'T', 'P', 'L', 'E', 'X', 'Y', 'R'],
    ['O', 'A', 'I', 'N', 'F', 'L', 'O', 'W', 'E', 'R'],
    ['O', 'X', 'F', 'O', 'R', 'G', 'C', 'I', 'T', 'Y'],
    ['B', 'E', 'T', 'A', 'G', 'O', 'A', 'L', 'L', 'O'],
    ['L', 'E', 'T', 'S', 'G', 'O', 'H', 'O', 'G', 'E'],
    ['U', 'N', 'I', 'T', 'E', 'D', 'F', 'L', 'A', 'G'],
    ['S', 'G', 'A', 'R', 'T', 'W', 'I', 'N', 'D', 'S'],
    ['G', 'O', 'L', 'D', 'F', 'I', 'S', 'H', 'T', 'A'],
    ['A', 'M', 'E', 'R', 'I', 'C', 'A', 'E', 'A', 'G'],
    ['G', 'O', 'G', 'L', 'S', 'T', 'R', 'I', 'K', 'E']
]

# printing the whole crossword puzzle 

for a in range(10):
    for b in range(10):
        if(b==0):
            print(f"  {db[a][0]}" , end=' ')
        else:
            print(f"| {db[a][b]}",end=' ')
    print()
    print("  -------------------------------------")


# checking if the word is present 

word = input("Enter the word to search : ")
found=[]
# checking if word present in horizondal ---->from frond to back and back to front


for i in range(10):
    for j in range(10):
        cw=''
        if( ( j + (len(word)-1) ) <= 9 ):
            cw = cw + db[j][i]
            for k in range(1,len(word)):
                cw = cw + db[i][j+k]
        if( cw.lower() == word.lower() ):
            found.append(["fw",i,j])
            

for i in range(10):
    for j in range(9,-1,-1):
        cw=''
        if( ( j - (len(word)-1) ) >= 0 ):
            cw = cw + db[i][j]
            for k in range(1,len(word)):
                cw = cw + db[i][j-k]
        if( cw.lower() == word.lower() ):
            found.append(["bw",i,j,])


# checking if the word present from top to bottom and from bottom to top

for i in range(10):
    for j in range(10):
        cw=''
        if( ( j + (len(word)-1) ) <= 9 ):
            cw = cw + db[j][i]
            for k in range(1,len(word)):
                cw = cw + db[j+k][i]
        if( cw.lower() == word.lower() ):
            found.append(["tb",j,i])


print(found)












