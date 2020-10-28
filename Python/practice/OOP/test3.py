class Fridge:
    def __init__(self,hi=None):
        self.isOpend = False
        self.foods = []
        print(hi)

    def open(self):
        self.isOpend= True
        print('냉장고 문을 열었어요...')

    def put(self,thing):
        if self.isOpend:
            self.foods.append(thing)
            print("냉장고 속에 음식이 들어갔네")
        else:
            print("냉장고 문이 닫혀잇어서 못넣")

    def close(self):
        self.isOpend = False
        print('냉장고 문을 닫았어요...')

class Food:
    pass

f = Fridge('av')
d = Fridge()
apple = Food()
banana = Food()

f.open()
f.put(apple)
f.put(banana)
f.close()
for i in f.foods:
    print(i)

