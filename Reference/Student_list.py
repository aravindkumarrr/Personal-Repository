n=int(input("Enter the number of students in the class: "))

  students=[]
  for i in range(n):
      temp=[]
      marks=[]
      name=''
      regno=0
      s1=0
      s2=0
      s3=0
      print("STUDENT ", i+1, " details: ")
      name=input("Enter the name of the student: ")
      regno=input("Enter the registration number: ")
      s1=int(input("Enter subject 1 marks: "))
      s2=int(input("Enter subject 2 marks: "))
      s3=int(input("Enter subject 3 marks: "))
      temp.append(name)
      temp.append(regno)
      temp.append(s1)
      temp.append(s2)
      temp.append(s3)
      students.append(temp)

  print(students)
  sub1avg=0
  sub2avg=0
  sub3avg=0
  classavg=0
  studentavg=0

  def subavg():
      tempt=0
      for i in students:
          tempt+=i[2]
      sub1avg=tempt/n
      print("Subject 1 average is: ", sub1avg)

      for i in students:
          tempt+=i[3]
      sub2avg=tempt/n
      print("Subject 2 average is: ", sub2avg)

      for i in students:
          tempt+=i[4]
      sub3avg=tempt/n
      print("Subject 3 average is: ", sub3avg)

  def perstudentsubavg():
      for i in students:
          var=0
          for j in range(2,5):
              var+=i[j]
          
          i.append(var/3)
      print(students)
