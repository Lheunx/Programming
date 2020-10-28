class Tiger:
    cm = 150
    kg = 100

    def growcm(self):
        self.cm +=1
    def growkg(self):
        self.kg +=1

hodol = Tiger()
hodol.growcm()
hodol.growcm()
print(hodol.cm,hodol.kg)