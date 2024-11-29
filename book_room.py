from datetime import datetime
db={}
flag=1
while(True):
    print("1.book new room","2.print db","3.checkout",sep="\n")
    op = int(input("enter option : "))
    if(op==1):
        name = input("enter name : ")
        print("rooms available:","single - $100","double - $200","deluxe - $300",sep="\n")
        roomtype = input("enter room type : ")
        days = int(input("enter no of days to stay : "))
        now = datetime.now()
        db[flag]={
                "name" : name,
                "room-type" : roomtype,
                "days" : days,
                "time" : now
                }
        flag=flag+1
    if(op==2):
        for cid, inner_db in db.items():
            print(f"id number : {cid}")
            for in_key,val in inner_db.items():
                print(f" {in_key} : {val}")
            print()
    if(op==3):
        idno = int(input("enter id number"))
        print(db[idno])
        perday = 0
        if(db[idno]["room-type"].lower() == "single"):
            perday = 100
        if(db[idno]["room-type"].lower() == "double"):
            perday = 200
        if(db[idno]["room-type"].lower() == "deluxe"):
            perday = 300
        total= perday*db[idno]["days"]
        print(f"total cost of stay ; {total} ")
    if(op==4):
        print(db)
    else:
        continue

