class Person:
    eyes =2
    nose =1
    mouth = 1
    ears = 2
    arms =2
    legs =2

    #먹고 자고 이야기하고
    def eat(self):
        print("얌얌...")
    def sleep(self):
        print("쿨쿨")
    def talk(self):
        print("어쩌구저쩌구")

class Student(Person):
    def study(self):
        print("열공열공~")

lhh = Student()

lhh.study()
lhh.sleep()